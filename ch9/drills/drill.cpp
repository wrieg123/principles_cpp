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


int main() {
  try {
    Chapter942();
  } catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
  } catch(...) {
    cerr << "exception\n";
  }
  return 0;
}
