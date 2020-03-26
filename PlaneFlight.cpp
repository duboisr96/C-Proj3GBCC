//Ryan DuBois Proj 3 class
#include <iostream>
using namespace std;
#include "PlaneFlight.h"


  int *seats;       //dynamic array of seats

  int numSeats;  //size of the seats array


  PlaneFlight::PlaneFlight(int planeSize)  {
    cout << "construct" << planeSize << endl;
    numSeats = planeSize;
    seats = new int[numSeats];
  }
  void PlaneFlight::reserveSeat(int seatNo)   {
    seats[seatNo] = 1; // seat is 1 if reserved, 0 if not
    //assumes seats is on plane and not reserved already
  }

  bool PlaneFlight::isFull() const {
    for (int i = 0; i<numSeats; i++) {
      if (seats[i] == 0) {
        cout << "not full" << endl;
        return false;
      }
    }
    cout << "is full" << endl;
    return true;
  }

  bool PlaneFlight::isEmpty() const {
    for (int i = 0; i<numSeats; i++) {
      if (seats[i] == 1) {
        cout << "not empty" << endl;
        return false;
      }
    }
    cout << "is empty" << endl;
    return true;
  }

  int PlaneFlight::seatsLeft() const {
    int count = numSeats;
    for (int i = 0; i<numSeats; i++) {
      count -= seats[i];
    }
    return count;
  }

  bool PlaneFlight::validSeatNum(int seatNo)  const {
    if (seatNo > numSeats) {
      return false;
    }
    return true;
  }

  bool PlaneFlight::seatVacant(int seatNo) const {
    if (seats[seatNo] == 1) {
      return true;
    }
    return false;
  }

  void PlaneFlight::cancelSeat(int seatNo) {
    seats[seatNo] = 0; 
  }


  PlaneFlight::PlaneFlight(const PlaneFlight&  obj) { 
    numSeats = obj.numSeats;
    seats = new int[numSeats];
    for (int i = 0; i <obj.numSeats; i++) {
      seats[i] = obj.seats[i];
    }
  }

  PlaneFlight::~PlaneFlight() {
    delete[] seats;
    cout <<"flight deleted successfully" << endl;
  }

  PlaneFlight& PlaneFlight::operator=(const PlaneFlight& rightside) {
    for (int i = 0; i <rightside.numSeats; i++) {
      seats[i] = rightside.seats[i];
    }
    cout << endl << numSeats << " numseats in operator =" << endl;
    return *this;
  }

  ostream& operator<<(ostream& out, const PlaneFlight& obj)  { //friend function
    cout << "in operator << numseats:" << obj.numSeats << endl; 
    for (int i = 0; i <obj.numSeats; i++) {
      if (obj.seats[i] == 0) {
        cout <<"Seat " << i << " is " << "empty" << endl;
      }
      else {
        cout <<"Seat " << i << " is " << "reserved" << endl;
      }
    }
    return out;
  }