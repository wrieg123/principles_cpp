/*
	calculator08buggy.cpp

	Helpful comments removed.

*/

#include "../../include/std_lib_facilities.h"

class Symbol_Table {
  public:
    Symbol_Table() { };

    double get_value(const string& s);
    void set_value(const string& s, const double d);
    bool is_declared(const string& s);
    double declare(const string& s, const double d, const bool set_const = false);

  private:
    struct Variable {
      string name;
      double value{};
      bool is_const{false};
    };

    // vector of Variable structs
    vector<Variable> var_table;

    // iterator
    using vt_itr = vector<Variable>::iterator;

    // function to find variable name through iterator
    vt_itr find_name(vt_itr first, vt_itr last, const string& value) {
      for(; first != last; ++first) {
        if(first->name == value) return first;
      }
      return last;
    }
};

// gets value by reference name (str)
double Symbol_Table::get_value(const string& s) {
  auto vt = find_name(var_table.begin(), var_table.end(), s);
  if (vt == var_table.cend()) error("get: undefined name ", s);
  return vt->value;
}

// set the Variable of the named to a double
void Symbol_Table::set_value(const string& s, const double d) {
  auto vt = find_name(var_table.begin(), var_table.end(), s);
  if(vt == var_table.cend()) error("set: undefined name ", s);
  if(vt->is_const) error("set: cannot set a constant");
  vt->value = d;
}

// checks for a name if it is not cend then returns true
bool Symbol_Table::is_declared(const string& s) {
  auto vt = find_name(var_table.begin(), var_table.end(), s);
  return vt != var_table.cend();
}

double Symbol_Table::declare(const string& s, const double d, const bool set_const) {
  if (is_declared(s)) error(s, " declared twice");
  var_table.push_back(Variable{s, d, set_const});
  return d;
}


Symbol_Table symbol_table; // set the global scoped table

const char let = 'L';
const char constant = 'C';
const char func = 'F';
const char quit = 'Q';
const char help = 'H';
const char print = ';';
const char number = '8';
const char name = 'a';
const char root = 'S';
const char pows = 'P';
const char K = 'k';


struct Token {
	char kind;
	double value;
	string name;

	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
  Token(char ch, string s) :kind(ch), name(s) { }
};

class Token_stream
{
public:
	Token_stream() :full(false), buffer() {}

	// get a Token to place in the stream
	Token get();

	// put a Token back into the stream
	void putback(const Token t);

	// discard characters up to and including the given input kind token
	void ignore(const char c);

private:
	bool full;      // is there a Token in the buffer?
	Token buffer;   // here is where we keep a Token put back using putback()
};


Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case '=':
    case ',':
    case K: 
      return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      {	cin.unget();
      double val;
      cin >> val;
      return Token(number, val);
      }
    default:
      if (isalpha(ch)) {
        string s;
        s += ch;
        while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
        cin.unget();
        if (s == "let") return Token(let);
        if (s == "exit") return Token(quit);
        if (s == "sqrt") return Token(root);
        if (s == "pow") return Token(pows);
        if (s == "const") return Token(constant);
        if (s == "help") return Token(help);
        return Token(name, s);
      }
      error("Bad token");
	}
}


void Token_stream::putback(const Token t) {
  if (full) {
    error("putback() into a full buffer");
  }
  buffer = t;
  full = true;
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(': {	
    t = ts.get();
    if (t.kind != ')') error("'(' expected");
    }
	case '-':
		return -primary();
  case root: 
    {
    double d = expression();
    if (d < 0) error("Cannot take sqrt of negative number");
    return sqrt(d);
    }
  case pows: 
    {
    t = ts.get();
    if (t.kind != '(') error("'(' expected");
    double d = expression();
    t = ts.get();
    if (t.kind != ',') error("',' expected");
    double i = expression();
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return pow(d, i);
    }
	case number:
		return t.value;
	case name:
		return symbol.get_value(t.name);
	default:
		error("primary expected");
	}
  return 0;
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
      case K:
        left *= 1000;
        break;
      case '*':
        left *= primary();
        break;
      case '/':
      {	
        double d = primary();
        if (d == 0) error("divide by zero");
        left /= d;
        break;
      }
      case '%': {
        double d = primary();
        if (d == 0) error("divide by zero");
        left = fmod(left, d);
        break;
      }
      default:
        ts.putback(t);
        break;
    }
    return left;
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
    case ',':
      break;
		default:
      ts.putback(t);
		}
    return left;
	}
}


double declaration(const bool is_const = false) {
  Token t = ts.get();
  if (t.kind != name) error("name expected in declaration");
  if (symbol_table.is_declared(t.name)) error(t.name, " declared twice");
  
  Token t2 = ts.get();
  if (t2.kind != '=') error("= missing in declaration of ", t.name);

  double d = expression();
  symbol_table.declare(t.name, d, is_const);
  return d;

}

//double declaration()
//{
//	Token t = ts.get();
//	if (t.kind != 'a') error("name expected in declaration");
//	string name = t.name;
//	if (is_declared(name)) error(name, " declared twice");
//	Token t2 = ts.get();
//	if (t2.kind != '=') error("= missing in declaration of ", name);
//	double d = expression();
//	names.push_back(Variable(name, d));
//	return d;
//}


double statement() {
	Token t = ts.get();
	double d{};
	switch(t.kind){
		case let:
			d = declaration();
			break;
		case constant:
			d = declaration(true);
			break;
		case name:
			{
				Token t2 = ts.get();
				if(t2.kind != '='){
					cin.putback(t2.kind);
					ts.putback(t);
					d = expression();
				} else {
					d = expression();
					symbol_table.set_value(t.name, d);
				}
				break;
			}
		default:
			ts.putback(t);
			d = expression();
	}
	return d;
}


void clean_up_mess()
{
	ts.ignore(print);
}

void print_help();

//------------------------------------------------------------------------------

void calculate()
{
	const string prompt = "> ";  // indicate a prompt
	const string result = "= ";  // indicate a result

	Token t;
	while(t.kind != quit) try{
		cout << prompt;
		t = ts.get();
		while(t.kind == print) t = ts.get();
		switch(t.kind){
			case quit:
				break;
			case help:
				print_help();
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				break;
			case ',':
				cout << result << statement() << endl;
				break;
			default:
				ts.putback(t);
				cout << result << statement() << endl;
		}
	}
	catch(runtime_error& e){
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()
try{
	cin.sync_with_stdio(false);
	calculate();
	return 0;
}
catch(exception& e){
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch(...){
	cerr << "exception\n";
	keep_window_open();
	return 2;
}

//------------------------------------------------------------------------------

double func_availible(const string& s, const vector<double>& args)
{
	double d{};
	if(s == "sqrt"){
		if(args.size() != 1) error("sqrt() expects 1 argument");
		if(args[0] < 0) error("sqrt() expects argument value >= 0");
		d = sqrt(args[0]);
	} else if(s == "pow"){
		if(args.size() != 2) error("pow() expects 2 arguments");
		d = args[0];
		auto multiplier = args[0];
		auto p = narrow_cast<int>(args[1]);
		for(; p > 1; --p){
			d *= multiplier;
		}
	} else{
		error("unknown function");
	}
	return d;
}

double function(const string& s)
{
	Token t = ts.get();
	vector<double> func_args;
	if(t.kind != '('){
		error("expected '(', malformed function call");
	} else{
		do{
			t = ts.get();
			// true check for arguments
			// false if no arguments
			if(t.kind != ')'){
				ts.putback(t);
				func_args.push_back(expression());
			}
		} while(t.kind != ')');
	}
	return func_availible(s, func_args);
}

//------------------------------------------------------------------------------

void print_help()
{
	ostringstream os;
	os << "Welcome to our simple calculator.\n"
		<< "- Please enter expressions using floating-point numbers.\n"
		<< "- Operations available are +, -, *, /, %.\n"
		<< "- Can change order of operations using ( ).\n"
		<< "- Declare named variables with the let keyword. (let x = 10.5)\n"
		<< "- Declare named constant variables with the constant keyword. (const PI = 3.14)\n"
		<< "- Can reassign non constant named variables. (x = PI/2)\n"
		<< "- Functions available are pow(arg, p) and sqrt(arg).\n"
		<< "- Use the '" << print << "' or new line to show results.\n"
		<< "- type " << quit << " to quit.\n\n";

	cout << os.str() << endl;
}
