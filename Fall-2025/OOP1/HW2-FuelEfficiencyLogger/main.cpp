// Name: Davide Russillo
// Student ID: S00763645
// Assignment: CS2313 Homework 1

#include <iostream>
#include <iomanip>
#include <limits>

#include "MPGStats.h"

using namespace std;

int main() {
  MPGStats stats;  // initialized
  double new_trip_miles;
  double new_trip_gallons;
  double new_trip_MPG;
  cout << fixed << setprecision(2);  // format doubles

  // Phase 1
  int new_trips_count;
  while(true) {
    cout << "Input how many trips to log: ";
    cin >> new_trips_count;
    if(!cin) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: non-numeric value entered. Try again." << endl;
    } else {
      break;
    }
  }

  while(new_trips_count > 0) {
    cout << "Enter miles and gallons: ";
    cin >> new_trip_miles >> new_trip_gallons;
    // input error handling
    if(!cin) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: non-numeric value entered. Try again." << endl;
      continue;
    }
    // valid case
    new_trip_MPG = stats.addTrip(new_trip_miles, new_trip_gallons);
    if(new_trip_MPG != -1.0) {
      new_trips_count--;
      cout << "Trip MPG: " << new_trip_MPG << endl;
    }
  }

  cout << endl;

  // Phase 2
  while(true) {
    cout << "Enter miles and gallons (enter -1 for miles to end): ";
    cin >> new_trip_miles >> new_trip_gallons;
    // input error handling
    if(!cin) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: non-numeric value entered. Try again." << endl;
      continue;
    }
    // sentinel case handling
    if(new_trip_miles == -1)
      break;
    // valid case
    new_trip_MPG = stats.addTrip(new_trip_miles, new_trip_gallons);
    if(new_trip_MPG != -1)
      cout << "Trip MPG: " << new_trip_MPG << endl;
  }

  cout << endl;

  // Final summary
  cout << "Total trips: " << stats.getTrips() << endl;
  cout << "Total miles driven: " << stats.getTotalMiles() << endl;
  cout << "Total gallons used: " << stats.getTotalGallons() << endl;
  cout << "Overall MPG: " << stats.overallMPG() << endl;
  cout << "Best MPG on a single trip: " << stats.getBestMPG() << endl;
  cout << "Worst MPG on a single trip: " << stats.getWorstMPG() << endl;
  cout << "Number of trips with low MPG (less than 15 MPG): " << stats.getLowMPGcount() << endl;

  return 0;
}
