#include "classes.h"
void Login::setID(){
  cout<<"Enter your id: ";
  cin>>id;
  cout<<"Enter your password: ";
  cin>>password;
  strcpy(pass, password);
}

char* Login::getID(){
  string strid=id;
  return strid;
}

void Login::displayDetails(){
  cout << "\n|" << "User ID:" << "\t" << "|" << "Password\n";
  cout << "|" << id << "\t\t" << "|" << pass << "\n\n";
}

char* Login::getPWD(){
  string strpwd=password;
  return strpwd;
}
