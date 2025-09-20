// Name: Davide Russillo
// Student ID: S00763645
// Assignment: CS2313 Homework 1

#include <limits>

#ifndef MPGSTATS_H_
#define MPGSTATS_H_

class MPGStats {
public:
  MPGStats() = default;

  double addTrip(double miles, double gallons) {
    if(miles < 0 || gallons <= 0)
      return -1.0;
    else {
      double MPG = miles / gallons;
      trips++;
      totalMiles += miles;
      totalGallons += gallons;
      if(MPG < 15)
        lowMPGcount++;
      if(MPG > bestMPG)
        bestMPG = MPG;
      if(MPG < worstMPG)
        worstMPG = MPG;

      return MPG;
    }
  }

  double overallMPG() const {
    if(totalGallons == 0) {
      return 0;
    } else {
      return totalMiles / totalGallons;
    }
  }

  int getTrips() const {
    return trips;
  }

  double getTotalMiles() const {
    return totalMiles;
  }

  double getTotalGallons() const {
    return totalGallons;
  }

  int getLowMPGcount() const {
    return lowMPGcount;
  }

  double getBestMPG() const {
    return bestMPG;
  }

  double getWorstMPG() const {
    return worstMPG;
  }



private:
  int trips = 0;
  double totalMiles = 0;
  double totalGallons = 0;
  int lowMPGcount = 0;
  double bestMPG = 0.0;
  double worstMPG = std::numeric_limits<double>::infinity();
};

#endif
