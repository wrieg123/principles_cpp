#pragma once
#include "../../include/std_lib_facilities.h"



namespace Chrono941 {
  struct Date {
    int y;
    int m;
    int d;
  };

  void init_day(Date &dd, int y, int m, int d);
  void add_day(Date &dd, int n);

  ostream& operator<<(ostream& os, const Date &d);

}


namespace Chrono942 {
  struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
  };

  ostream& operator<<(ostream& os, const Date& d);

}


namespace Chrono943 {
   


}
