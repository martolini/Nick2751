//
//  task1.cpp
//  freelancer
//
//  Created by Martin Skow Røed on 12.05.13.
//  Copyright (c) 2013 Martin Skow Røed. All rights reserved.
//

#pragma once

#include <fstream>
#include <iostream>
using namespace std;

class Person{
    friend   ostream & operator << ( ostream & w, const Person &);  //   will send name and age to w with NO descriptions
    
public:  Person(const char *, int);
    Person(void);      //   The name NOT GIVEN will be used
    Person(const Person &);
    const Person & operator = (const Person &);
    void Print(void) const;     // will print to cout the name and age with descriptions
    ~Person();
private:
    char * name;
    int age;
} ;

class Worker : public Person {
    friend   ostream & operator << ( ostream & w, const Worker &);  //   will send name , age and salary to w
    // with NO descriptions
public:
    Worker(const char *, int, double);
    Worker(const Worker &);
    void Print() const;
private:
    double salary;
} ;


Person::Person(const char * p , int a) {
    name = new char[strlen(p)];
    strcpy(name, p);
    age = a;
}


Person::Person(void) {
    name = new char[10];
    strcpy(name, "NOT GIVEN");
    age = -1;
}//   The name NOT GIVEN will be used

Person::Person(const Person & other) {
    name = new char[strlen(other.name)];
    strcpy(name, other.name);
    this->age = other.age;
}

const Person & Person::operator = (const Person & other) {
    delete []name;
    name = new char[strlen(other.name)];
    strcpy(name, other.name);
    this->age = other.age;
    return *this;
}

void Person::Print(void) const {
    cout << "Name: " << name << ", age: " << age;
}

Person::~Person() {
    delete []name;
}



Worker::Worker(const char * p, int a, double s) :Person(p, a) , salary(s) {
    //using initialized list instead of everything
}

Worker::Worker(const Worker & other) : Person() {
    Worker &w = *this;
    w = other;
}

void Worker::Print() const  {
    Person::Print();
    cout << ", salary: " << salary;
}


ostream & operator << ( ostream & out, const Person & p) {
    out << p.name << ", " << p.age;
    return out;
}// Just the data, NO descriptions

ostream & operator << ( ostream & out, const Worker & w) {
    out << Person(w);
    out << ", " << w.salary;
    return out;
}//  Just the data, NO descriptions
