#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "DataBase.h"


int main(int argc, char const *argv[]) {
  Student Aidan("Aidan",2317537,"Sophomore","Computer Science",3.4,1111);
  Student Noah("Noah", 233675,"Junior","Data Analytics", 3.7,1234);
  // DoublyLinkedList<Student> *none = new DoublyLinkedList<Student>();
  // Faculty *Rene = new Faculty("Rene", 11111,"Big Professor","Computer Science", none);
  // BST<Student>* st = new BST<Student>();
  // st->insert(0, *Aidan);
  // Aidan->printStudent();
  // st->insert(1, 2);
  // st->deleteNode(1);
  // st->insert(2, 3);
  // st->printTree(st->root);
  DataBase db = DataBase();
  // db.addStudent(*Aidan);
  db.addStudent(Noah);
  db.addStudent(Aidan);
  // db.addStudent();
  // db.printStudents();
  // db.deleteStudent(2317537);
  // db.printStudents();
  // db.printStudentFromID(233675);
  db.runDB();
  return 0;
}



// #include <iostream>
// using namespace std;
//
// public class Person{
// private:
//
// public:
//   string m_name;
//   int m_ID;
//   string m_level;
//   Person();
//   Person(string name, int ID, string level);
//   ~Person();
//
//
//
// };
//
// Person::Person(){
//   m_name = " ";
//   m_ID=0;
//   m_level =" ";
// }
//
// Person::Person(string name, int ID, string level){
//   m_name = name;
//   m_ID = ID;
//   m_level = level;
// }
//
// Person::~Person(){
//
// }



// #include "Student.h"
// #include "Faculty.h"
//
//
// int main(int argc, char const *argv[]) {
//   // Student *Aidan = new Student("Aidan",2317537,"Sophomore","Computer Science",3.4,1111);
//   // DoublyLinkedList<Student> *none = new DoublyLinkedList<Student>();
//   // Faculty *Rene = new Faculty("Rene", 11111,"Big Professor","Computer Science", none);
//   return 0;
// }
