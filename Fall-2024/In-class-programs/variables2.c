/* C program by Dave Russillo on 09/03/2024 for CS1310. Learning variables. */
#include <stdio.h>

void main(void) {
    double rate; // in mph
    double time; // in hours
    double distance; // in miles
    
    printf("This program calculates the distance you will go. \n \n");
    time = 2;
    rate = 80;
    distance = rate * time;
    printf("You went %lf miles at %lf mph for %lf hours.", distance, rate, time);
}

