// Name: Davide Russillo
// Student ID: S00763645
// Assignment: CS2313 Homework 1

#include <iostream>
#include "Student.h"

using namespace std;

int main() {
  Student s1 = Student("John", 19, 3.75);
  Student s2 = Student("Arthur", -1, 100);

  s1.printInfo();
  s2.printInfo();

  if(s1.isAdult())
    cout << s1.getName() << " is an adult." << endl;
  else
    cout << s1.getName() << " is not an adult." << endl;

  if(s2.isAdult())
    cout << s2.getName() << " is an adult." << endl;
  else
    cout << s2.getName() << " is not an adult." << endl;

  s2.eligibleForScholarship();

  if(s1.eligibleForScholarship())
    cout << s1.getName() << " is eligible for a scholarship." << endl;
  else
    cout << s1.getName() << " is not eligible for a scholarship." << endl;

  if(s2.eligibleForScholarship())
    cout << s2.getName() << " is eligible for a scholarship." << endl;
  else
    cout << s2.getName() << " is not eligible for a scholarship." << endl;

  s1.calculateWeeklyStudyAverage();

  string newStudentName;
  double newStudentGpa;

  std::cout << "Enter new student's name: ";
  std::cin >> newStudentName;
  std::cout << "Enter new student's GPA: ";
  std::cin >> newStudentGpa;

  Student s3 = Student(newStudentName, 18, newStudentGpa);
  s3.printInfo();


  return 0;
}
