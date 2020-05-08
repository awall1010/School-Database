#ifndef DATABASE_H
#define  DATABASE_H
// #include "Student.h"
#include "Faculty.h"
#include "BST.h"

using namespace std;

class DataBase{
public:
  DataBase();
  // ~DataBase();

  BST<Student> studentTree;
  BST<Faculty> facultyTree;

  void addStudent(Student student);
  void printStudents();
  void printStudentFromID(int studentID);
  void deleteStudent(int studentID);
  void addFac(Faculty faculty); 
  void printFac();
  void printFacID(int facultyID);
  void deleteFac(int facultyID);


};

DataBase::DataBase(){

}

void DataBase::addStudent(Student student){
  studentTree.insert(student.m_ID, student);
}

void DataBase::printStudents(){
  studentTree.printTree(studentTree.root);
}

void DataBase::deleteStudent(int studentID){
  studentTree.deleteNode(studentID);
}

void DataBase::addFac(Faculty fac){
  facultyTree.insert(fac.m_ID, fac);
}

void DataBase::printFac(){
  facultyTree.printTree(facultyTree.root);
}

void DataBase::deleteFac(int facultyID){
  facultyTree.deleteNode(facultyID);
}


void DataBase::printStudentFromID(int studentID){
  studentTree.printFromKey(studentID);
}

void DataBase::printFacID(int facultyID){
  facultyTree.printFromKey(facultyID);
}
#endif
