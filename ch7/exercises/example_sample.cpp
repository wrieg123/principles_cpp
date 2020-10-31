#include "../../include/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Symbol_Table {
public:
	Symbol_Table() {};

	double get_value(const string& s);
	void set_value(const string& s, const double d);
	bool is_declared(const string& s);
	double declare(const string& s, const double d, const bool set_const = false);

private:
	// place to hold variable name value
	struct Variable
	{
		string name;
		double value{};
		bool is_const{false};
	};

	// container for all the variables
	vector<Variable> var_table;

	// private function to find name in var_table
	using vt_itr = vector<Variable>::iterator;
	vt_itr find_name(vt_itr first, vt_itr last, const string& value)
	{
		for(; first != last; ++first){
			if(first->name == value){
				return first;
			}
		}
		return last;
	}
};

// return the value of the Variable with the input name.
double Symbol_Table::get_value(const string& s)
{
	auto vt = find_name(var_table.begin(), var_table.end(), s);
	if(vt == var_table.cend()) error("get: undefined name ", s);
	return vt->value;
}

// set the Variable of the named to a double value.
void Symbol_Table::set_value(const string& s, const double d)
{
	auto vt = find_name(var_table.begin(), var_table.end(), s);
	if(vt == var_table.cend()) error("set: undefined name ", s);
	if(vt->is_const) error("set: is a constant");
	vt->value = d;
}

// is a name already declared
bool Symbol_Table::is_declared(const string& s)
{
	auto vt = find_name(var_table.begin(), var_table.end(), s);
	return vt != var_table.cend();
}

// add name value to a vector of Variables
double Symbol_Table::declare(const string& s, const double d, const bool set_const)
{
	if(is_declared(s)) error(s, " declared twice");
	var_table.push_back(Variable{s, d, set_const});
	return d;
}

//------------------------------------------------------------------------------

Symbol_Table symbol_table;

//------------------------------------------------------------------------------

const char number = '8';                // t.kind == number Token.
const char print = ';';                 // t.kind == print Token.

const char quit = 'q';                  // t.kind == quit Token.                                     
const string key_quit = "quit";    // quit keyword
const char help = 'h';                  // t.kind == help Token.
const string key_help = "help";    // help keyword

const char name = 'a';                  // t.kind = name of variable Token
const char let = 'L';                   // t.kind = declaration token
const string declkey = "let";      // declaration keyword
const char constant = 'C';              // t.kind = constant declaration Token
const string declkey_const = "const";// constant declaration keyword

const char func = 'F';      // t.kind = function Token

struct Token
{
	char kind;
	double value;
	string name;
	Token() :kind('\0'), value(0.0), name("") {}
	Token(char ch, double val = 0.0) :kind(ch), value(val), name("") {}
	Token(char ch, string s) :kind(ch), value(0.0), name(s) {}
};

//------------------------------------------------------------------------------

// place to hold valid Tokens from cin
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

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	Token t{};
	if(full){
		full = false;
		t = buffer;
	} else{
		char ch{};
		// get next character, eat spaces except new line is print
		do{
			cin.get(ch);
			if(ch == '\n') ch = print;
		} while(isspace(ch));
		switch(ch){
			case print:
			case '(': case ')':
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case ',':
			case '=':
				t.kind = ch;
				break;
			case '.':
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				{
					cin.putback(ch);
					double val{};
					cin >> val;
					t.kind = number;
					t.value = val;
					break;
				}
			default:
				if(isalpha(ch) || ch == '_'){
					string s;
					s += ch;
					while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
					cin.putback(ch);
					if(s == declkey){
						t.kind = let;
					} else if(s == declkey_const){
						t.kind = constant;
					} else if(ch == '('){
						t.kind = func;
						t.name = s;
					} else if(s == key_quit){
						t.kind = quit;
					} else if(s == key_help){
						t.kind = help;
					} else{
						t.kind = name;
						t.name = s;
					}
				} else{
					error("Bad token");
				}
		}
	}
	return t;
}

void Token_stream::putback(const Token t)
{
	if(full){
		error("putback() into a full buffer");
	}
	buffer = t;
	full = true;
}

void Token_stream::ignore(const char c)
{
	if(full && c == buffer.kind){
		full = false;
	} else{
		full = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), c);
	}
}

Token_stream ts;

//------------------------------------------------------------------------------

double expression();
double function(const string& s);

//------------------------------------------------------------------------------

double primary()
{
	Token t = ts.get();
	double d{};
	switch(t.kind){
		case '(':
			{
				d = expression();
				t = ts.get();
				if(t.kind != ')'){
					error("')' expected");
				}
				break;
			}
		case '-':
			d = -1 * primary();
			break;
		case '+':
			d = primary();
			break;
		case number:
			d = t.value;
			break;
		case name:
			d = symbol_table.get_value(t.name);
			break;
		case func:
			d = function(t.name);
			break;
		default:
			error("primary expected");
	}
	return d;
}

//------------------------------------------------------------------------------

double term()
{
	double left = primary();
	while(true){
		Token t = ts.get();
		switch(t.kind){
			case '*':
				left *= primary();
				break;
			case '/':
				{
					double d = primary();
					if(d == 0) error("divide by zero");
					left /= d;
					break;
				}
			case '%':
				{
					double d = primary();
					if(d == 0){
						error("divide by zero");
					}
					left = fmod(left, d);
					break;
				}
			default:
				ts.putback(t);
		}
		return left;
	}
}

//------------------------------------------------------------------------------

double expression()
{
	double left = term();
	while(true){
		Token t = ts.get();
		switch(t.kind){
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

//------------------------------------------------------------------------------

double declaration(const bool is_const = false)
{
	Token t = ts.get();
	if(t.kind != name){
		error("name expected in declaration");
	}
	if(symbol_table.is_declared(t.name)){
		error(t.name, " declared twice");
	}
	Token t2 = ts.get();
	if(t2.kind != '='){
		error("= missing in declaration of ", t.name);
	}
	double d = expression();
	symbol_table.declare(t.name, d, is_const);
	return d;
}

//------------------------------------------------------------------------------

double statement()
{
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

//------------------------------------------------------------------------------

void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

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
