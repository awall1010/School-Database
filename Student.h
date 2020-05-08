// #include "Person.h"
#ifndef STUDENT_H
#define STUDENT_H

#include <unistd.h>
#include <iostream>
using namespace std;

class Student{
public:

  string m_name;
  int m_ID;
  string m_level;
  string m_major;
  double m_GPA;
  int m_advisorID;
  Student();
  ~Student();
  Student(string name, int ID, string level, string major, double GPA, int advisorID);
  void printStats();
};

Student::Student(){
  m_name = " ";
  m_ID=0;
  m_level = " ";
  m_major = " ";
  m_GPA = 0.0;
  m_advisorID =0;

}

Student::Student(string name, int ID, string level, string major, double GPA, int advisorID){
  m_name = name;
  m_ID= ID;
  m_level=level;
  m_major=major;
  m_GPA=GPA;
  m_advisorID = advisorID;
}

Student::~Student(){

}

void Student::printStats(){
  cout<<endl;
  cout<<"Name: "<<m_name<<endl;
  cout<<"ID: "<<m_ID<<endl;
  cout<<"Level: "<<m_level<<endl;
  cout<<"Major: "<<m_major<<endl;
  cout<<"GPA: "<<m_GPA<<endl;
  cout<<"Advisor ID: "<<m_advisorID<<endl;
  cout<<endl;
}



#endif
