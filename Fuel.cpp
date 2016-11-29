#include <iostream>
using namespace std;

class Odometer

{
public:
	Odometer();
	void reset();
	void compute_fuel();
	void input_miles(int getmiles);
	void Odometer::set_fuel_efficiency(double fuel_efficiency);
	double Odometer::get_num_gallons();
	int gallons_consumed;
	


private:
	int miles_tracker;
	double fuel_efficiency;
	int getmiles;
	
	
	
};

Odometer::Odometer()
{
	
	miles_tracker = 0;
	fuel_efficiency = 0;
	int miles_driven = 0;
}



void Odometer::reset()
{
	miles_tracker = 0;
}



void Odometer::compute_fuel()
{
	fuel_efficiency = (miles_tracker/gallons_consumed);
}



void Odometer::input_miles(int miles_driven)
{
	miles_tracker = miles_tracker + miles_driven;

}




void Odometer::set_fuel_efficiency(double Fuel_efficiency)
{
	fuel_efficiency = Fuel_efficiency;
}

double Odometer::get_num_gallons()
{
	return miles_tracker/fuel_efficiency;
}




	 


int main()
{

	Odometer simulator;
  int number_of_miles_driven;

  cout << "Please enter the amount of miles driven : " << endl;
  cin >> number_of_miles_driven;

  simulator.input_miles(number_of_miles_driven);


    //simulator.set_fuel_efficiency(Fuel_efficiency);
	//cout <<"Enter your amount of fuel in gallons: " << endl;
	//cin >> Fuel_efficiency;

return 0;
}