#include "Chrono.h"

namespace Chrono941 {

  void init_day(Date& dd, int y, int m, int d) {
    if (m < 1 || m > 12 || d < 1 || d > 31) error("Invalid Date Parameter");
    dd.y = y;
    dd.m = m;
    dd.d = d;
  }

  void add_day(Date& dd, int n) {
    init_day(dd, dd.y, dd.m, dd.d+n);
  }

  ostream& operator<<(ostream& os, const Date& dd) {
    return os << "(" << dd.y << ", " << dd.m << ", " << dd.d << ")";
  }

}


namespace Chrono942 {
  Date::Date(int y, int m, int d) :y(y), m(m), d(d) {
    if (m < 1 || m > 12 || d < 1 || d > 31) error("Invalid Date Parameter");
  }

  void Date::add_day(int n) {
    d += n;
    if (d > 31) error("Invalid Day!");
  }

  ostream& operator<<(ostream& os, const Date& dd) {
    return os << "(" << dd.y << ", " << dd.m << ", " << dd.d << ")";
  }
}

