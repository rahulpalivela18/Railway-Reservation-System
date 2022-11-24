#include "classes.h"

void Cancel::setCancelDetails(){
  cout<<"Enter the details as follows\n";
  cout<<"Pnr No: ";
  cin>>pnr;
  cout<<"Date Of Cancellation: ";
  cin>>d>>m>>y;
  cout<<"End of Details\n";
}

void Cancel::displayCancelDetails(){
        cout << "…………………………………….\n";
        cout << "…………………………………….\n";
        cout << "Pnr no:" << pnr;
        cout << "\nTrain no:" << tno;
        cout << "\nTrain name:";
        cout << tname;
        cout << "\nBoarding point:";
        cout << bp;
        cout << "\nDestination pt:";
        cout << dest;
        cout << "\nYour class:";
        cout << clas;
        cout << "\nno of seats to be cancelled:" << nosc;
        for (int i = 0; i < nosc; i++)
        {
            cout << "\nPassenger name:";
            cout << PassengerName[i];
            cout << "\npassenger age:" << age[i];
        }
        cout << "\nDate of cancellation:" << d << "-" << m << "-" << y;
        cout << "\nYou can collect:" << amr << "rs" << endl;
        cout << "*****************************************\n";
        cout << "………End of Cancellation………….\n";
        cout << "*****************************************\n";
}