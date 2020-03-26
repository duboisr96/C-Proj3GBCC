//Ryan DuBois Proj 3 unit tester
#include <iostream>
using namespace std;
#include "PlaneFlight.h"

int main() {
  PlaneFlight flight1(5);
  PlaneFlight flight2(5);
 
  flight1.reserveSeat(3);
  PlaneFlight flight3(flight1);
  cout << flight1;
  cout << flight3;

  flight3.reserveSeat(1);
  flight2 = flight1;

  cout << flight1;
  cout << flight2;
  cout << flight3;

  flight1.isFull();
  flight2.isEmpty();
  cout << "seats left " << flight3.seatsLeft() <<endl;
  cout << flight2.validSeatNum(33) << endl;
  cout << flight1.seatVacant(2) << endl;
  flight3.cancelSeat(3);
  cout << flight3;
}