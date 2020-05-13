#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "DataBase.h"


int main(int argc, char const *argv[]) {
  DataBase db = DataBase();
  db.runDB();


  
  // Student Aidan("Aidan",2317537,"Sophomore","Computer Science",3.4,223344);
  // Student Noah("Noah", 233675,"Junior","Data Analytics", 3.7,223344);
  // DoublyLinkedList<int> *students = new DoublyLinkedList<int>();
  // students->insertBack(2317537);
  // students->insertBack(233675);
  //
  // Faculty Rene("Rene",223344,"Associate", "Computer Science",students);
  // db.addStudent(Noah);
  // db.addStudent(Aidan);
  // db.addFac(Rene);
  // DataBase db = DataBase();

  // db.writeStudents(Aidan);
  // db.writeFaculty(Rene);


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
