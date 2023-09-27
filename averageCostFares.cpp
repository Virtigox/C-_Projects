#include <iostream>
using namespace std;

// struct
struct numberOfRides{
    int noBusRides;
    int noBoatRides;
};

// number of bus rides and number of boat rides after computing number of free rides
numberOfRides freeRide_func(int numberOfBusRides,int numberOfBoatRides, int numberOfFreeRides) {

    numberOfRides nORs;
    //base cases
    if (numberOfBoatRides == 0 && numberOfBusRides == 0){
        nORs.noBusRides = numberOfBusRides;
        nORs.noBoatRides = numberOfBoatRides;
    }
    else if (numberOfBoatRides == 0) {
        numberOfBusRides -=  numberOfFreeRides;
        nORs.noBusRides = numberOfBusRides;
    }
    else if (numberOfFreeRides < numberOfBoatRides){
        numberOfBoatRides -= numberOfFreeRides;
        nORs.noBoatRides = numberOfBoatRides;
        nORs.noBusRides = numberOfBusRides;
    }
    else if (numberOfFreeRides >= numberOfBoatRides) {
        numberOfBusRides -= (numberOfFreeRides - numberOfBoatRides);
        numberOfBoatRides = 0;
        nORs.noBusRides = numberOfBusRides;
        nORs.noBoatRides = numberOfBoatRides;
    }

    return  nORs;
}
int main(){
	//initializing the variables
	double busFare = 1.75;
	double boatFare = 2.00;
	int numberOfBusRides;
	int numberOfBoatRides;
	int numberOfFreeRides;
	double totalCostOfFares,totalCostAfterFreeRide,averageCostPerLeg;


    // Prompting values
    std::cout << "How many Bus Rides Do you take: ";
	std::cin >> numberOfBusRides;

    std::cout << "How many Boat Rides Do you take: ";
	std::cin >> numberOfBoatRides;

    std::cout << "How many Free Rides Do you get: ";
	std::cin >> numberOfFreeRides;

	totalCostOfFares = numberOfBusRides*busFare + 
                        numberOfBoatRides*boatFare;
	std::cout << "Total Cost of Fares before free Ride:"<<totalCostOfFares<< std::endl;

    // freeRide Calculation
    numberOfRides nORs = freeRide_func(numberOfBusRides,numberOfBoatRides,numberOfFreeRides);
    numberOfBusRides = nORs.noBusRides;
    numberOfBoatRides = nORs.noBoatRides;

    std::cout << numberOfBusRides << "\n"<<numberOfBoatRides<<std::endl;
    totalCostAfterFreeRide  = (numberOfBusRides*busFare) + (numberOfBoatRides *boatFare);
    std::cout <<"Total Cost of Fares after free Ride:"<< totalCostAfterFreeRide<<std::endl;

    //average cost per leg after free fares reduction
    if (totalCostAfterFreeRide <= 0){
        std::cout<< "You dont have to pay for the fares."<<std::endl;
    }
    else{
        averageCostPerLeg = totalCostAfterFreeRide / (numberOfBusRides + numberOfBoatRides);
        std::cout << "Average Cost Per Journey: $" << averageCostPerLeg << std::endl;
    }
	return 0;
	 
}
