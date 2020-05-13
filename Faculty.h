// #include "Person.h"
#ifndef FACULTY_H
#define FACULTY_H
#include <unistd.h>
#include <iostream>
#include "LL.h"
#include "Student.h"
using namespace std;

class Faculty{
public:
  string m_name;
  int m_ID;
  string m_level;
  string m_department;
  // double m_GPA;
  // DoublyLinkedList<Student> *m_advisees = new DoublyLinkedList<Student>();
  DoublyLinkedList<int> *m_advisees = new DoublyLinkedList<int>();
  Faculty();
  Faculty(string name, int ID, string level, string department, DoublyLinkedList<int> *advisees);
  ~Faculty();

  void printStats();
  void removeAdvisee(int ID);
};

Faculty::Faculty(){

}

Faculty::Faculty(string name, int ID, string level, string department, DoublyLinkedList<int>* advisees ){
  m_name = name;
  m_ID = ID;
  m_level=level;
  m_department = department;
  m_advisees = advisees;
}

Faculty::~Faculty(){

}


void Faculty::printStats(){
  cout<<"Name: "<<m_name<<endl;
  cout<<"ID: "<<m_ID<<endl;
  cout<<"Level: "<<m_level<<endl;
  cout<<"Department: "<<m_department<<endl;
  cout<<"Student Advisee ID's: "<<endl;
  m_advisees->printList();
  cout<<endl;
}

void Faculty::removeAdvisee(int ID){
  cout<<"Entering the function. "<<endl;
  m_advisees->removeAtPos(ID);
  cout<<"advisee removed. "<<endl;
}


#endif
