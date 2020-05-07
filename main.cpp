#include "Student.h"
#include "Faculty.h"
#include "BST.h"


int main(int argc, char const *argv[]) {
  // Student *Aidan = new Student("Aidan",2317537,"Sophomore","Computer Science",3.4,1111);
  // DoublyLinkedList<Student> *none = new DoublyLinkedList<Student>();
  // Faculty *Rene = new Faculty("Rene", 11111,"Big Professor","Computer Science", none);
  BST<int> *st = new BST<int>();
  st->insert(0, 1);
  st->insert(1, 2);
  st->insert(2, 3);
  // TreeNode<int>* root = new TreeNode<int>();
  st->printTree(st->root);

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
