//Ryan DuBois Proj 3 header
#include <iostream>
using namespace std;
class PlaneFlight  { 
  private:

      int *seats;       //dynamic array of seats

      int numSeats;  //size of the seats array

    public:

      PlaneFlight(int planeSize);

      void reserveSeat(int seatNo);

      bool isFull() const;

      bool isEmpty () const;

      int seatsLeft() const;

      bool validSeatNum(int seatNo)  const;

      bool seatVacant(int seatNo) const;

      void cancelSeat(int seatNo);

      PlaneFlight(const PlaneFlight&  obj);

      ~PlaneFlight();

      PlaneFlight& operator =(const PlaneFlight& rightside);

      friend ostream& operator<<(ostream& out, const PlaneFlight& obj);  
}; 