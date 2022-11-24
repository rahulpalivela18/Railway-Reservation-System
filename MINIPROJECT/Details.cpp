#include "classes.h"

void Details::setDetails(){
      cout<<"\n--Add New details--\n";
      cout << "Train no: ";
			cin >> Train_num;
			cout << "Train Name: ";
			cin >> train_name;
			cout << "Boarding point: ";
			cin >> boardingPoint;
			cout << "Destination pt: ";
			cin >> destination;
			cout << "No of seats in first class & fare per ticket: ";
			cin >> firstClass >> price1;
			cout << "No of seats in second class & fare per ticket: ";
			cin >> secondClass >> price2;
			cout << "Date of travel\n";
			cout << "Day: ";
			cin >> d;
			cout << "Month: ";
			cin >> m;
			cout << "Year: ";
			cin >> y;
    }
void Details::displayDetails(){
		    cout << "\n|Train No." << "\t" << "|Train Name" << "\t" << "|Boarding pt." << "\t" << "|Destination pt."  <<"\t";
			cout << "|F-Class" << "\t"<< "|F-Class Fare" << "\t" << "|S-Class" << "\t" << "|S-Class Fare" <<"\t";
			cout << "|Day" << "-" << "Month" << "-" << "Year" << "\n";

			cout << "|" << Train_num << "\t\t" << "|" << train_name << "\t\t" << "|" << boardingPoint << "\t\t" << "|" << destination <<"\t\t\t";
			cout << "|" << firstClass << "\t\t" << "|"<< price1 << "\t\t" << "|" << secondClass<< "\t\t" << "|" << price2 <<"\t\t";
			cout << "|" << d << "-" << m << "-" << y << "\n";
		}

/*int Details::getFirstClass(){
  return firstClass;
}
void Details::setFirstClass(int fc){
  firstClass=fc;
}
int Details::getPrice1(){
  return price1;
}
void Details::setPrice1(int p1){
  price1=p1;
}
int Details::getSecondClass(){
  return secondClass;
}
void Details::setSecondClass(int sc){
  secondClass=sc;
}
int Details::getPrice2(){
  return price2;
}
void Details::setPrice2(int p2){
  price2=p2;
}*/