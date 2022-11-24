#include "classes.h"
#include <bits/stdc++.h>
void database();
void user();
void manage();
void reserve(char*);
void cancel();
void enquiry();
void displayPassdetail();
void myBookings(char*);
char f[10] = "f";
char s[10] = "s";
int addr, ad, flag, f1, d, m, i, amt, y, FLAG = 1;
float tamt;
int main() {
  int choice;
  while(1){
    cout<<"\n MAIN MENU \n";
    cout<<"1. Admin mode\n2. User mode\n3. Exit\nEnter your choice: ";
    cin>>choice;
    switch(choice){
      case 1:
        database();
        break;
      case 2:
        user();
        break;
      case 3:
        cout<<"Thankyou Visit AGAIN"<<endl;
				exit(0);
    }
  }
}

void database(){
  char password[20];
  char pass[20] = "NONE";
  cout<<"Enter Admin Password: ";
  cin>>password;
  Details a;
	fstream f;
	int choice;
	char c;
  if(strcmp(pass, password) != 0){
    cout<<"You have entered an incorrect Password, Try AGAIN. Exiting from mode\n";
  }
  else{
    do{
      cout << "\n --- ADMINISTRATOR MENU --- \n";
			cout << "1. Create detail Database \n";
			cout << "2. Add details \n";
			cout << "3. Display details \n";
			cout << "4. User Management \n";
			cout << "5. Diplay Passenger details \n";
			cout << "6. Return to Main Menu \n";
			cout << "Enter your choice : ";
			cin >> choice;
      switch(choice){
        case 1:
					f.open("t.txt",ios::out|ios::binary);
					do
					{
					a.setDetails();
					f.write((char *) & a,sizeof(a));
					cout << "\nDo you want to add one more record?\n";
					cout << "y-for Yes\nn-for No\n";
					cin >> c;
					}while(c=='y');
					f.close();
					break;
        
        case 2:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					a.setDetails();
					f.write((char *) & a,sizeof(a));
					f.close();
					break;
        
        case 3:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					f.seekg(0);
					while(f.read((char *) & a,sizeof(a)))
					{
					a.displayDetails();
					}
					f.close();
					break;
        
				case 4:
					manage();
					break;
        
				case 5:
					displayPassdetail();
					break;
      }
      
    }while(choice <= 5);
  }
  
}

void user(){
  //cout<<"HI";
  Login a;
  int ch;
  //int d=0;
  cout<<"\n-----Login User-----\n";
  char password[10];
	fstream f;
	f.open("id.txt",ios::in|ios::out|ios::binary);
	char id[100];
	std::cout << "Enter your ID : ";
	std::cin >> id;
	std::cout << "Enter your Password : ";
	std::cin >> password;
	while(f.read((char *) & a,sizeof(a)))
	{
		if((strcmp(a.getID(),id)==0)&&(strcmp(a.getPWD(),password)==0))
		{
			do
			{
				std::cout<<"\n1.Reserve\n2.Cancel\n3.Enquiry\n4.View Bookings\n5.Return to the main menu\n";
				cout<<"Enter your choice:";
				cin>>ch;
				switch(ch)
				{
					case 1:
						reserve(id);
						break;
					case 2:
						cancel();
						break;
					case 3:
						enquiry();
            break;
          case 4:
            myBookings(id);
						break;
				}
			}while(ch<=4);
		}
		else
		{
			d=1;
		}
	}
	if(d==1)
	{
		cout<<"Enter your user id and password correctly\n";
	}
}

void manage()
{
	int ch;
	fstream f;
	char c;
	Login a;
	std::cout<<"\n---WELCOME TO THE USER MANAGEMENT MENU---\n";
	do
	{
		std::cout << "1. Create id database\n";
		std::cout << "2. Add details\n";
		std::cout << "3. Display details\n";
		std::cout << "4. Return to the main menu\n";
		std::cout << "Enter your choice: ";
		std::cin>>ch;
		switch(ch)
		{
			case 1:
				f.open("id.txt",ios::out|ios::binary);
				do
				{
					a.setID();
					f.write((char *) & a,sizeof(a));
					std::cout << "Do you want to add one more record\n";
					std::cout << "y-Yes\nn-No\n";
					std::cin>>c;
				}while(c == 'y');
				f.close();
				break;
			case 2:
				f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
				a.setID();
				f.write((char *) & a,sizeof(a));
				f.close();
				break;
			case 3:
				f.open("id.txt",ios::in|ios::out|ios::binary);
				f.seekg(0);
				while(f.read((char *) & a,sizeof(a)))
				{
					a.displayDetails();
				}
				f.close();
				break;
			}
		}while(ch<=3);
}

void reserve(char* userID){
  flag=1;
  int ch;
  //int amt,addr,ad;
  do
  {
    std::cout << "1.Reserve\n2.Return to the main menu\n";
        std::cout << "Enter your choice:";
        std::cin >> ch;
        std::cout << endl;
        switch (ch)
        {
        case 1:
            Details a;
    Reservation b;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
    int ch;
    b.setReservationDetails();
    while (f1.read((char *)&a, sizeof(a)))
    {
      flag=1;
        if (a.Train_num == b.tno)
        {
            if (strcmp(b.clas, f) == 0)
            {
                if (a.firstClass >= b.nosr)
                {
                    amt = a.price1;
                    addr = f1.tellg();
                    ad = sizeof(a.firstClass);
                    f1.seekp(addr - (7 * ad));
                    a.firstClass=a.firstClass - b.nosr;
                    ;
                    f1.write((char *)(&(a.firstClass)), sizeof((a.firstClass)));
                    
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    b.amc = amt;
                    strcpy(b.userID, userID);
                    f2.write((char *)&b, sizeof(b));
                    b.displayResDetails();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "**********Sorry req seats not available********\n";
                }
            }
            else if (strcmp(b.clas, s) == 0)
            {
                if (a.secondClass >= b.nosr)
                {
                    amt = a.price2;
                    addr = f1.tellg();
                    ad = sizeof(a.price2);
                    f1.seekp(addr - (5 * ad));
                    a.secondClass=a.secondClass - b.nosr;
                    
                    f1.write((char *)&a.price2, sizeof(a.price2));
                    b.amc = amt;
                    f2.write((char *)&b, sizeof(b));
                    b.displayResDetails();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "********Sorry req no of seats not available*******\n";
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "!\n";
    }
    f1.close();
    f2.close();
            break;
        }
    } while (ch == 1);    
  
}

void can(){
  flag = 1;
  Details a;
  Reservation b,dFILE;
  Cancel c;
  fstream f1, f2, f3;
  f1.open("t.txt",ios::in|ios::out|ios::binary);
  f2.open("p.txt",ios::in|ios::out|ios::binary);
  f3.open("cn.txt",ios::in|ios::out|ios::binary);
  cout<<"**********CANCELLATION MENU*********\n";
  c.setCancelDetails();

  while (f2.read((char*)&b, sizeof(b))){
    flag=1;
    if(b.pnr == c.pnr){
      c.tno = b.tno;
      strcpy(c.tname, b.tname);
      strcpy(c.bp, b.bp);
      strcpy(c.dest, b.dest);
      c.nosc = b.nosr;
      for(int j=0; j < c.nosc; j++){
        strcpy(c.PassengerName[j], b.PassengerName[j]);
        c.age[j] = b.age[j];
      }

      strcpy(c.clas, b.clas);
      if(strcmp(c.clas, f) == 0){//checking for first class
        while(f1.read((char*)&a, sizeof(a))){
          if(a.Train_num == c.tno){
            a.firstClass = a.firstClass + c.nosc;
            d = a.d;
            m = a.m;
            y = a.y;
            addr = f1.tellg();
            ad = sizeof(a.firstClass);
            f1.seekp(addr - (7 * ad));
            f1.write((char *)&a.firstClass, sizeof(a.firstClass));
            tamt = b.amc;
          if (y > c.y || y == c.y && m > c.m || 
           y == c.y && m == c.m && d > c.d)
            {
              cout<<"You are cancelling..\n";
              c.amr = tamt - (tamt/2);
              fstream temp, temp1;
              temp.open("p.txt",ios::in|ios::out|ios::binary);
              temp1.open("temp.txt",ios::out|ios::binary);
              while (temp.read((char*)&dFILE, sizeof(dFILE))){
                if (dFILE.pnr != c.pnr) {
                  temp1.write((char *)&dFILE, sizeof(dFILE));
                }
              }
              temp.close();
              temp1.close();
              remove("p.txt");
              rename("temp.txt", "p.txt");
            }
            else{
              cout << "Cancelling after the departure\n";
              cout << "Your request cannot be completed\n";
              //goto h;
            }
            //goto h;
            c.displayCancelDetails();
          }
          }
        }
      
        else if(strcmp(c.clas, s) == 0){
          while(f1.read((char*)&a, sizeof(a))){
            if(a.Train_num == c.tno){
              a.secondClass = a.secondClass + c.nosc;
              d = a.d;
              m = a.m;
              y = a.y;
              addr = f1.tellg();
              ad = sizeof(a.secondClass);
              f1.seekp(addr - (5 * ad));
              f1.write((char *)&a.firstClass, sizeof(a.firstClass));
              tamt = b.amc;

              if( ((c.d == d) && (c.m == m)) || (c.m == m) || (m > c.m) || (c.y < y) ){
                cout<<"You are cancelling..\n";
                c.amr = tamt - tamt/2;
                fstream temp, temp1;
              temp.open("p.txt",ios::in|ios::out|ios::binary);
              temp1.open("temp.txt",ios::out|ios::binary);
              while (temp.read((char*)&dFILE, sizeof(dFILE))){
                if (dFILE.pnr != c.pnr) {
                  temp1.write((char *)&dFILE, sizeof(dFILE));
                }
              }
              temp.close();
              temp1.close();
              remove("p.txt");
              rename("temp.txt", "p.txt");
              }
              else{
                cout << "Cancelling after the departure\n";
                cout << "Your request cannot be completed\n";
                //goto h;
              }
              c.displayCancelDetails();

            
          }
        }
      }
      
    }
    else{
      flag = 0;
    }
  }
  h:
  if(flag==0)
    {
            cout << "Enter the correct pnr no\n";
    }

  f1.close();
  f2.close();
  f3.close();
}


// void can(){
// Details a;
//     Reservation b;
//     Cancel c;
//     fstream f1, f2, f3;
//     f1.open("t.txt",ios::in|ios::out|ios::binary);
//     f2.open("p.txt",ios::in|ios::out|ios::binary);
//     f3.open("cn.txt",ios::in|ios::out|ios::binary);
//     cout<<"**********CANCELLATION MENU*********\n";
//     c.setCancelDetails();
  
//     while(f2.read((char *) & b,sizeof(b)))
//     {
//         if (b.pnr == c.pnr)
//         {
//             c.tno = b.tno;
//             strcpy(c.tname, b.tname);
//             strcpy(c.bp, b.bp);
//             strcpy(c.dest, b.dest);
//             c.nosc = b.nosr;
//             for (int j = 0; j < c.nosc; j++)
//             {
//                 strcpy(c.PassengerName[j], b.PassengerName[j]);
//                 c.age[j] = b.age[j];
//             }
//             strcpy(c.clas, b.clas);
//             if (strcmp(c.clas, f) == 0)
//             {
//                 while (f1.read((char *)&a, sizeof(a)))
//                 {
//                     if (a.Train_num == c.tno)
//                     {
//                         a.firstClass = a.firstClass + c.nosc;
//                         d = a.d;
//                         m = a.m;
//                         addr = f1.tellg();
//                         ad = sizeof(a.firstClass);
//                         f1.seekp(addr - (7 * ad));
//                         f1.write((char *)&a.firstClass, sizeof(a.firstClass));
//                         tamt = b.amc;
//                         if ((c.d == d) && (c.m == m))
//                         {
//                             cout << "You are cancelling at the date of departure\n";
//                             c.amr = tamt - ((tamt * 60) / 100);
//                           c.displayCancelDetails();
//                         }
//                         else if (c.m == m)
//                         {
//                             cout << "You are cancelling at the month of departure\n";
//                             c.amr = tamt - ((tamt * 50) / 100);
//                           c.displayCancelDetails();
//                         }
//                         else if (m > c.m)
//                         {
//                             cout << "You are cancelling one month before the date of departure\n";
//                             c.amr = tamt - ((tamt * 20) / 100);
//                           c.displayCancelDetails();
//                         }
//                         else
//                         {
//                             cout << "Cancelling after the departure\n";
//                             cout << "Your request cannot be completed\n";
//                           //goto h;
//                         }
                        
                        
//                     }
//                 }
//             }
//             else if (strcmp(c.clas, s) == 0)
//             {
//                 while (f1.read((char *)&a, sizeof(a)))
//                 {
//                     if (a.Train_num == c.tno)
//                     {
//                         a.secondClass = a.secondClass + c.nosc;
//                         d = a.d;
//                         m = a.m;
//                         addr = f1.tellg();
//                         ad = sizeof(a.secondClass);
//                         f1.seekp(addr - (5 * ad));
//                         f1.write((char *)&a.secondClass, sizeof(a.secondClass));
//                         tamt = b.amc;
//                         if ((c.d == d) && (c.m == m))
//                         {
//                             cout << "You are cancelling at the date of departure\n";
//                             c.amr = tamt - ((tamt * 60) / 100);
//                           c.displayCancelDetails();
//                         }
//                         else if (c.m == m)
//                         {
//                             cout << "You are cancelling at the month of departure\n";
//                             c.amr = tamt - ((tamt * 50) / 100);
//                           c.displayCancelDetails();
//                         }
//                         else if (m > c.m)
//                         {
//                             cout << "You are cancelling one month before the date of departure\n";
//                             c.amr = tamt - ((tamt * 20) / 100);
//                           c.displayCancelDetails();
//                         }
//                         else
//                         {
//                             cout << "Cancelling after the departure\n";
//                             cout << "Your request cannot be completed\n";
                          
                        
//                         }
                        
//                     }
//                 }
//             }
//         }
//         else
//         {
//             cout<<"Invalid Pnr!\nTry again"<<endl;
//         }
//     }
    
    
//     f1.close();
//     f2.close();
//     f3.close();
// }

void cancel(){
  int ch;
    do
    {
        cout << "……………..CANCELLATION MENU………\n";
        cout << "1.Cancel\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            can();
            break;
        }
    } while (ch == 1);
}

void enquiry()
{
    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    Details a;
    while(f.read((char *) & a,sizeof(a)))
    {
            a.displayDetails();
    }
}

void myBookings(char* id)
{
  std::cout << "\n--------Passenger Details--------\n";
	fstream f;
	Reservation b;
	f.open("p.txt",ios::in|ios::out|ios::binary);
	f.seekg(0);
	while(f.read((char *) & b,sizeof(b)))
	{
    if (strcmp(b.userID, id) == 0)
		  b.displayResDetails();
	}
	f.close();
        
}

void displayPassdetail(){
  std::cout << "\n--------Passenger Details--------\n";
	fstream f;
	Reservation b;
	f.open("p.txt",ios::in|ios::out|ios::binary);
	f.seekg(0);
	while(f.read((char *) & b,sizeof(b)))
	{
		b.displayResDetails();
	}
	f.close();
}