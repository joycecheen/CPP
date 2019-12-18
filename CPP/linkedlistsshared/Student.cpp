#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::Student(char* firstInput, char* lastInput, int IDInput, float GPAInput) {
  firstName = firstInput;
  lastName = lastInput;
  ID = IDInput;
  GPA = GPAInput;
}
Student::~Student() {
  delete firstName;
  delete lastName;
}
char* Student::getFirst() {
  return firstName;
}
char* Student::getLast() {
  return lastName;
}
int Student::getID() {
  return ID;
}
float Student::getGPA() {
  return GPA;
}
void Student::printStudent() {
  cout << "Name: " << firstName << " " << lastName << endl;
  cout << "ID: " << ID << endl;

  cout.precision (2);
  cout.setf(ios::showpoint);
  cout << "GPA: " << fixed << GPA << endl;

}
