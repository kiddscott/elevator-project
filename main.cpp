#include <iostream>
#include <cmath>
using namespace std;

const int FLOOR_TRAVEL_TIME = 10;
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: moveElevator
//
// Description:
//		This function moves the elevator to the desired floor
//
// Inputs: 
//		startFloor: the floor that the elevator starts on (for single movement)
//		endFloor: 	the floor that the elevator ends on (for single movement)
//
// Assumptions:
//		this currently assumes the input is correct
// 		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int moveElevator(int startFloor, int endFloor){

	int travelTime = abs(endFloor - startFloor) * FLOOR_TRAVEL_TIME;

	return travelTime;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: inputCheck
//
// Description:
//		This function is used to check proper input in the command line
//
// Inputs: 
//
// Assumptions:
//		this currently assumes the input is correct
// 		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int inputCheck(){

	// assuming all command line input is correct

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: Main
//
// Description:
//		This function is the main elevator line.
//
// Inputs: (optional)
//		filename: 		name of file
//		startFloor: 	the starting floor for the elevator
//		floorsToVisit: 	floor number to visit, separated by spaces
//
// Assumptions:
// 		arguments: filename startFloor floorsToVisit[0] floorsToVisit[1] floorsToVisit[2] ... floorsToVisit[n]
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {


    int numFloorsToVisit = 0;
	int* floorsToVisit;
    int startFloor = 0;    
    int totalTravelTime = 0;

	// set variables with default values or with terminal input values
	if (argc == 1){
    
    	cout << "Using default elevator values." << endl;
        startFloor = 12;
    	numFloorsToVisit = 4;
        floorsToVisit = new int[numFloorsToVisit]{2, 9, 1, 32};
        
    }else{
    	
        if (inputCheck() == true){
        
    		cout << "Using entered elevator values." << endl;
          	startFloor = atoi(argv[1]);
    		numFloorsToVisit = argc - 2;
          	floorsToVisit = new int[numFloorsToVisit];
          	for (int i = 0; i < numFloorsToVisit; i++){
              		floorsToVisit[i] = atoi(argv[i+2]);
          	}
          
        }else{
        
        	return 1;
            
        }
    
    }
    
    //run elevator
    int i = 0;
    while (i < numFloorsToVisit){
    
    	// begin with starting floor on first iteration
    	if (i == 0)
    		totalTravelTime += moveElevator(startFloor, floorsToVisit[i]);
        else
    		totalTravelTime += moveElevator(floorsToVisit[i-1], floorsToVisit[i]);        
    
    	i++;
    
    }
    
    // output values
    cout << "Total Travel Time: " << totalTravelTime << " seconds" << endl;
    cout << "Floors Visited: " << startFloor;
    for (int i = 0; i < numFloorsToVisit; i++){
    
    	cout << ", " << floorsToVisit[i];
    
    }
  
  delete floorsToVisit;
  
  return 0;
}
