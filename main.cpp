#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

//Converts the lat and long to distance
double haversine(double lat1, double long1, double lat2, double long2, double radius, double& distance1){
    double pi = 3.141593;
    //Converts degrees to radian for calculation
    lat1 = lat1 * pi/180;
    lat2 = lat2 * pi/180;
    long1 = long1 * pi/180;
    long2 = long2 * pi/180;
    
    //Haversine formula
    distance1 = 2*radius*(asin(sqrt(pow(sin((lat2-lat1)/2),2)+(cos(lat1))*(cos(lat2))*(pow(sin((long2-long1)/2),2)))));
}

//Converts flight distance to estimated flight time
double getFlightTime(double flightDistance, double& flightTime1, double& flightTime2, int& flightTimeHour1, int& flightTimeMin1, int& flightTimeHour2, int& flightTimeMin2){
    //Calculates longest estimated flight time
    flightTime1 = flightDistance/460;
    flightTimeHour1 = flightDistance/460; //Slow hours
    flightTimeMin1 = (flightTime1 - flightTimeHour1)*60; //Slow minutes
    //Calculates fastest estimated flight time
    flightTime2 = flightDistance/575;
    flightTimeHour2 = flightDistance/575; //Fast hours
    flightTimeMin2 = (flightTime2 - flightTimeHour2)*60; //Fast minutes
}


int main(){
    
    int departLocationNumber;
    int arriveLocationNumber;
    int flightTimeSlowHours;
    int flightTimeSlowMins;
    int flightTimeFastHours;
    int flightTimeFastMins;
    double departLatitude;
    double departLongitude;
    double arriveLatitude;
    double arriveLongitude;
    double earthRadius = 3958.8;
    double distance;
    double flightTimeSlow;
    double flightTimeFast;
    string departLocationName;
    string arriveLocationName;
    
    //Sets rounding
    cout << setprecision(9);
    
    //Introduction to program
    cout << "Hello. This application will calculate the amount of time that it";
    cout << " takes to flight from one city to another.";
    cout << " Please follow all directions." << endl;
    cout << endl << endl;
    
    //Vector for location
    vector <string> location{"Venice, FL, USA", "Newport, AR, USA", 
    "Jamestown, NY, USA", "Dallas, TX, USA", "Palm Springs, CA, USA",
    "North Pole, AK, USA", "Syracuse, NY, USA", "Chattanooga, TN, USA",
    "Buffalo, NY, USA", "Charlotte, NC, USA"};
    
    //Vector for locations latitude
    vector <double> latitude{27.109644, 35.618671, 42.095554, 32.779167, 
    33.830517, 64.751114, 43.088947, 35.045631, 42.880230, 35.227085};
    
    //Vector for locations longitude
    vector <double> longitude{-82.448792, -91.271286, -79.238609, -96.808891,
    -116.545601, -147.349442, -76.154480, -85.309677, -78.878738, -80.843124};
    
    //Asks for user input for departing location
    cout << "Choose a location to depart from. (input 1 to 10)" << endl;
    //Outputs departing choices
    for(int i = 0; i < 10; i++){
    //cout << i + 1 << ")   " << leaving[i] << endl;
    if(i < 9){
        cout << i + 1 << ")   " << location[i] << endl;
    }
    else{
        cout << i + 1 << ")  " << location[i] << endl;
    }}
    cin >> departLocationNumber;
    //Checks for incorrect inputs and prompts a new input
    while(departLocationNumber<1 || departLocationNumber>10){
        cout << "Input a number between 1 and 10." << endl;
        cin >> departLocationNumber;
    }
    
    //Stores depart location name
    departLocationName = location[departLocationNumber - 1];
    //Stores depart location latitude
    departLatitude = latitude[departLocationNumber - 1];
    //Stores depart location longitude
    departLongitude = longitude[departLocationNumber - 1];
    
    //Removes the selected location from the vector
    location.erase(location.begin() + departLocationNumber - 1);
    //Removes the selected locations latitude from the vector
    latitude.erase(latitude.begin() + departLocationNumber - 1);
    //Removes the selected locations longitude from the vector
    longitude.erase(longitude.begin() + departLocationNumber - 1);
    
    //Asks for user input for arriving location
    cout << endl << "Choose a location to arrive at. (input 1 to 9)" << endl;
    for(int i = 0; i < 9; i++){
        cout << i + 1 << ")   " << location[i] << endl;
    }
    cin >> arriveLocationNumber;
    //Checks for incorrect inputs and prompts a new input
    while(arriveLocationNumber<1 || arriveLocationNumber>9){
        cout << "Input a number between 1 and 9." << endl;
        cin >> arriveLocationNumber;
    }
    
    //Stores arrive location name
    arriveLocationName = location[arriveLocationNumber - 1];
    //Stores arrive location latitude
    arriveLatitude = latitude[arriveLocationNumber - 1];
    //Stores arrive location longitude
    arriveLongitude = longitude[arriveLocationNumber - 1];
    
    //Calls the haversine function
    haversine(departLatitude, departLongitude, arriveLatitude, arriveLongitude, earthRadius, distance);
    
    //Calls the getFlightTime function
    getFlightTime(distance, flightTimeSlow, flightTimeFast, flightTimeSlowHours, flightTimeSlowMins, flightTimeFastHours, flightTimeFastMins);
    
    //Final output statement / summary
    cout << "Your flight from " << departLocationName << " to " << arriveLocationName;
    cout << " will take anywhere from " << flightTimeFastHours << " hour(s) and " << flightTimeFastMins;
    cout << " minute(s) to " << flightTimeSlowHours << " hour(s) and " << flightTimeSlowMins << " minute(s). " << endl;
    
    return 0;
}
