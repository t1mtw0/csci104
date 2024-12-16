#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(std::string name) {
	mName = name;
}

std::string Person::getName() {
	return mName;
}

Professor::Professor(std::string name, std::string department) : Person(name) {
	mDepartment = department;
}

std::string Professor::getDepartment() {
	return mDepartment;
}

Student::Student(std::string name, std::string major) : Person(name) {}

void Student::setGPA(double gpa) {
	mGpa = gpa;
}

std::string Student::getMajor() {
	return mMajor;
}

UscStudent::UscStudent(std::string name, std::string major, double gpa) : Student(name, major) {
	setGPA(gpa);
}

void UscStudent::printTranscript() {
	std::cout << "School Name: USC" << std::endl;
	std::cout << "GPA: " << mGpa << std::endl;
	std::cout << "Major: " << mMajor << std::endl;
}