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
  DoublyLinkedList<Student> *m_advisees = new DoublyLinkedList<Student>();

  Faculty();
  Faculty(string name, int ID, string level, string department, DoublyLinkedList<Student> *advisees);
  ~Faculty();
};

Faculty::Faculty(){

}

Faculty::Faculty(string name, int ID, string level, string department, DoublyLinkedList<Student> *advisees ){
  m_name = name;
  m_ID = ID;
  m_level=level;
  m_department = department;
  m_advisees = advisees;
}
#endif
