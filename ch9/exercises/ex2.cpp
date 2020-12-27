#include "../../include/std_lib_facilities.h"

class Name_pairs {
  public:
    void read_names();
    void read_ages();
    void print() const;
    void sort();
    const vector<string>& get_name() const { return name; }
    const vector<double>& get_age() const { return age; }

  private:
    vector<string> name;
    vector<double> age;
};


void Name_pairs::read_names() {
  cout << "Enter names, '_' to finish: ";
  string s;
  while (cin >> s && s != "_") {
    for (int i = 0; i < name.size(); ++i) {
      if (name[i] == s) error("Name exists already: ", s);
    }
    name.push_back(s);
  }
}

void Name_pairs::read_ages() {
  
  for (int i = 0; i < name.size(); ++i) {
    cout << "Age for " << name[i] << ": ";
    double a;
    cin >> a;
    age.push_back(a);
  }
}


void Name_pairs::print() const {
  if (name.size() != age.size()) error("print(): name and age msut be the same size");

  for (int i = 0; i < name.size(); ++i) {
    cout << "(" << name[i] << ", " << age[i] << ")" << endl;
  }
}

void Name_pairs::sort() {
  if (name.size() != age.size()) error("sort(): name and age must be the same size");
  vector<string> name_presort = name;
  vector<double> age_cp = age;
  std::sort(name.begin(), name.end());
  for (int i = 0; i < name.size(); ++i) {
    for (int j = 0; j < name_presort.size(); ++j) {
      if (name[i] == name_presort[j]) age[i] = age_cp[j];
    }
  }
}

int main() {
  try {
    Name_pairs np1;
    np1.read_names();
    np1.read_ages();
    np1.print();
    np1.sort();
    np1.print();
  }
  catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
  }
  catch (...) {
    cerr << "exception\n";
  }
  return 0;
}
