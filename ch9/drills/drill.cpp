#include "../../include/std_lib_facilities.h"
#include "Chrono.h"

void Chapter941() {

  using namespace Chrono941;
  cout << "Clock from 9.4.1\n";
  Date today;
  init_day(today, 1978, 6, 25);
  Date tomorrow = today;
  add_day(tomorrow, 1);
  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  Date invalid_date;
  init_day(invalid_date, 2003, 112, 5);
  
}


void Chapter942() {
  using namespace Chrono942;
  cout << "Clock from 9.4.2\n";
  Date today(1978, 6, 25);
  Date tomorrow = today;
  tomorrow.add_day(1);

  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  Date invalid_date(2003, 1212, 5);
}

void Chapter943() {
  using namespace Chrono943;
  cout << "Clock from 9.4.3\n";
  Date today(1978, 6, 25);
  Date tomorrow = today;
  tomorrow.add_day(1);

  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  Date invalid_date(2003, 1212, 5);
}


void Chapter971() {
  using namespace Chrono971;
  cout << "Clock from 9.7.1\n";
  Date today(1978, Date::jun, 25);
  Date tomorrow = today;
  tomorrow.add_day(1);

  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  Date invalid_date(2003, Date::dec, -5);

}


void Chapter974() {
	using namespace Chrono974;
	cout << "Chapter 9.7.4:\n";
	Date default_d;
	cout << "Default date: " << default_d << endl;
	Date today(1978,Date::jun,25);  // colloquial style
	Date tomorrow = today;  // copy constructor
	tomorrow.add_day(1);
	Date next_year = today;
	next_year.add_year(1);
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;
	cout << "Next year: " << next_year << endl;
	Date invalid_date = Date(2004,Date::dec,-5);   // verbose style
}

int main() {
  try {
    Chapter974();
  } catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
  } catch(...) {
    cerr << "exception\n";
  }
  return 0;
}
