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

//943

namespace Chrono943 {
  Date::Date(int y, int m, int d) :y(y), m(m), d(d) {
    if (m < 1 || m > 12 || d < 1 || d > 31) error("Invalid Date Parameter");
  }
  
  void Date::add_day(int n) {
    d += n;
    if (d > 31) error("Invalid Day!");

  }

  ostream& operator<<(ostream& os, Date& dd) {
    return os << "(" << dd.year() << ", " << dd.month() << ", " << dd.day() << ")";
  }
}


//971

namespace Chrono971 {
  Date::Date(int y, Month m, int d) :y(y), m(m), d(d) {
    if (m < Date::jan || m > Date::dec || d < 1 || d > 31) error("Invalid Date Parameter");
  }

  void Date::add_day(int n) {
    d += n;
    if (d > 31) error("Invalid Day!");
  }

  ostream& operator<<(ostream& os, Date& dd) {
    return os << "(" << dd.year() << ", " << dd.month() << ", " << dd.day() << ")";
  }
  
}

namespace Chrono974 {
  Date::Date(int yy, Month mm, int dd) :y(yy), m(mm), d(dd) {
    if (m < Date::jan || m > Date::dec || d < 1 || d > 31) error("Invalid Date Parameter");
  }

  const Date& default_date() {
    static Date dd(2001, Date::jan, 1);
    return dd;
  }

  Date::Date() 
    :y(default_date().year()),
    m(default_date().month()),
    d(default_date().day())
  {
  }

  int Date::year() const {
    return y;
  }

  Date::Month Date::month() const {
    return m;
  }

  int Date::day() const {
    return d;
  }

  void Date::add_year(int n) {
    y += n;
  }
  
  void Date::add_month(int n) {
    //no
  }
  void Date::add_day(int n) {
    d += n;
    if (d > 31) error("add_day() is invalid");
  }

  ostream& operator<<(ostream& os, const Date& d) {
    return os << "(" << d.year() << ", " << d.month() << ", " << d.day() << ")";
  }
}
