#include<cstdlib>
#include<iostream>
#include <fstream>
#include <string.h>
#include <time.h>
using namespace std;

class Login;
class Details;
class Reservation;
class Cancel;

class Login{
private:
    char id[100];
    char password[100];
    char pass[100];
public:
    void setID();
    void displayDetails();
    char* getID();
    char* getPWD();
};

class Details{
public:
  int Train_num;
  char train_name[100];
  char boardingPoint[100];
  char destination[100];

  int firstClass;
  int price1;
  int secondClass;
  int price2;
  int d, m, y;

    /*int getTrain_num();
    void setTrain_num(int tn);
    char* getTrain_name();
    void setTrain_name(int tN);
    char* getBoardingPoint();
    void setBoardingPoint(char* bp);
    char* getDestination();
    void setDestination(char* d);
    int getFirstClass();
    void setFirstClass(int fc);
    int getPrice1();
    void setPrice1(int p1);
    int getSecondClass();
    void setSecondClass(int sc);
    int getPrice2();
    void setPrice2(int p2);*/
    void setDetails();
    void displayDetails();
};

class Reservation{
public:
  int pnr;
  char userID[100];
  int tno;
  char tname[100];
  char bp[10];
  char dest[100];
  char PassengerName[10][100];
	int age[20];
	char clas[10];
	int nosr;//no of seats required for reservation
	int i;
	int d,m,y;
  float amc;//amount collected

  /*int getPnr();
  void setPnr(int p);
  int getTno();
  void setTno(int tn);
  char* getTname();
  void setTname(char* tN);
  char* getBp();
  void setBp(char* b);
  char* getDest();
  void setDest(char* d);
  int* getAge();
  void setAge(int *a);
  char* getClas();
  void setClas(char* clas);
  int getSeatsReq();
  void setSeatsReq(int sr);*/
  void setReservationDetails();
  void displayResDetails();
};

class Cancel{
public:
  int pnr;
  int tno;//train number
  char tname[10];
  char bp[10];//boardingPoint
  char dest[10];
  char PassengerName[10][100];
  int age[10];
  int nosc;//no of seats cancelled
  char clas[10];
  int d, m, y;
  float amr; //amount returned

  void setCancelDetails();
  void displayCancelDetails();
};
