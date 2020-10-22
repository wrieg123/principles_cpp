#include "../../include/std_lib_facilities.h"

using namespace std;

int main() {

  string first_name, friend_name;
  char friend_sex = '0';
  int age;

  cout << "Please enter your first name: ";
  cin >> first_name;
  cout << "Please enter your friend's name: ";
  cin >> friend_name;
  cout << "Enter 'm' if your friend is male or 'f' if your friend is female: ";
  cin >> friend_sex;
  cout << "What is your friend's age? ";
  cin >> age;
  
  if (age <= 0 || age >= 110) simple_error("you're kidding!");

  string string_sex = (friend_sex == 'm') ? "him" : "her";

  cout << "Hello, " << first_name << endl;
  cout << "If you see " << friend_name << " can you ask " << string_sex << " to call me?" << endl;
  
  cout << "I hear you just had a birthday and you are " << age << " years old!";
  if (age < 12) cout << " Next year you will be " << age+1 << " years old.";
  else if (age == 17) cout << " Next year you will be able to vote.";
  else if (age > 70) cout << " I hope you are enjoying retirement";
  cout << endl;

  cout << "Yours sincerely, \n\nWill" << endl;

  return 1;
}
