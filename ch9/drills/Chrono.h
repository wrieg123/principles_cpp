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
  class Date {
    int y, m, d;
  public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }
   
  };

  ostream& operator<<(ostream& os, Date& d);

}

namespace Chrono971 {
  class Date {
    public:
      enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
      };

      Date(int y, Month m, int d);
      void add_day(int n);
      int year() { return y; }
      Month month() { return m; }
      int day() { return d; }
    private:
      int y, d;
      Month m;
  };
  
  ostream& operator<<(ostream& os, Date& d);
}


namespace Chrono974 {
  class Date {
    public:
      enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
      };

      Date(int y, Month m, int d);
      Date();

      int year() const;
      Month month() const;
      int day() const;

      void add_day(int n);
      void add_month(int n);
      void add_year(int n);

    private:
      int y;
      Month m;
      int d;
  };

  ostream& operator<<(ostream& os, const Date& d);
}
