// Name: Davide Russillo
// Student ID: S00763645
// Assignment: CS2313 Homework 1

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>

class Student {
  private:
    std::string name;
    int age;
    double gpa;

  public:
    // constructor
    // using string reference to avoid copying the string (const to accept literals)
    Student(const std::string &name, int age, double gpa) {
      // using 'this' pointer to current object
      this->name = name;

      // invalid age
      if(age < 0) {
        this->age = 0;
      } else {  // valid age
        this->age = age;
      }

      // invalid gpa (outside [0, 4] interval)
      if(gpa < 0 || gpa > 4) {
        this->gpa = 0;
      } else {
        this->gpa = gpa;
      }
    }

    // getters and setters
    void setName(const std::string &name) {
      this->name = name;
    }
    std::string getName() const {
      return name;
    }

    void setAge(const int age) {
      if(age < 0) {
        this->age = 0;
      } else {  // valid age
        this->age = age;
      }
    }
    int getAge() const {
      return age;
    }

    void setGpa(const double gpa) {
      if(gpa < 0 || gpa > 4) {
        this->gpa = 0;
      } else {
        this->gpa = gpa;
      }
    }
    double getGpa() const {
      return gpa;
    }


    // other methods
    bool isAdult() const {
      return age > 17;
    }

    void printInfo() const {
      std::cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << std::endl;
    }

    bool eligibleForScholarship() const {
      return gpa >= 3.5 && age <= 25;
    }

    void calculateWeeklyStudyAverage() const {
      double hours[5];
      double sum = 0;

      for(int i = 0; i < 5; i++) {
        std::cout << "Enter hours for day " << i+1 << ": ";
        std::cin >> hours[i];
        sum += hours[i];
      }
      std::cout << "Your average daily study hours are " << sum / 5 << "h." << std::endl;
    }
};

#endif
