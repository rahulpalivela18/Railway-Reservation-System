#include "classes.h"
void Reservation::setReservationDetails(){
    cout<<"Enter the details as follows\n";
    cout<<"Train Number: ";
    cin>>tno;
    cout<<"Train Name: ";
    cin>>tname;
    cout<<"Boarding Point: ";
    cin>>bp;
    cout<<"Destination Point: ";
    cin>>dest;
    cout<<"Number Of Seats Required: ";
    cin>>nosr;
    for(int i = 0; i < nosr; i++){
      cout<<"Passenger name:";
			cin >> PassengerName[i];
			cout<<"Passenger age:";
			cin>>age[i];
    }

    cout<<"Enter the class f-first class s-second class:";
    cin >> clas;
		cout<<"Date of travel:";
		cin>>d>>m>>y;
		cout<<"…………END OF GETTING DETAILS…………\n";
}
void Reservation::displayResDetails(){
    cout<<"Pnr no: "<<pnr;
		cout<<"\nTrain no: "<<tno;
		cout<<"\nTrain name: "<<tname;
		cout<<"\nBoarding point: "<<bp;
		cout<<"\nDestination pt: "<<dest;
		cout<<"\nNo of seats reserved: "<<nosr;
		for(int i=0;i<nosr;i++)
		{
			cout<<"\nPassenger name: ";puts(PassengerName[i]);
			cout<<"Passenger age: "<<age[i];
		}
    
		cout<<"\nYour class: ";puts(clas);
		cout<<"\nDate of reservation: "<<d<<"-"<<m<<"-"<<y;
  }