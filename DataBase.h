#ifndef DATABASE_H
#define  DATABASE_H
// #include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "Student.h"

using namespace std;

class DataBase{
public:
  DataBase();
  // ~DataBase();

  BST<Student> studentTree;
  BST<Faculty> facultyTree;

  void addStudent(Student student);
  void addStudent();
  void printStudents();
  void printStudentFromID(int studentID);
  void deleteStudent(int studentID);
  void addFac(Faculty faculty);
  void addFac();
  void printFac();
  void printFacID(int facultyID);
  void deleteFac(int facultyID);

  void runDB();

};

DataBase::DataBase(){

}

void DataBase::addStudent(Student student){
  studentTree.insert(student.m_ID, student);
}

void DataBase::addStudent(){
  string name;
  int ID;
  string grade;
  string major;
  double gpa;
  int advisor;
  cout <<"Enter Student's Name: "<<endl;
  cin>>name;
  cout<< "enter ID: " <<endl;
  cin>>ID;
  cout<<"Enter Class Standing: "<<endl;
  cin>>grade;
  cout<<"Enter Major: "<<endl;
  cin>>major;
  cout<<"enter GPA: " << endl;
  cin >>gpa;
  cout<< "Enter Advisor ID: "<<endl;
  cin >> advisor;
  // cout<<"STUDENT CREATED. "<<endl;
  cout<<endl;
  Student newStu(name,ID,grade,major,gpa,advisor);
  cout<<"STUDENT CREATED. "<<endl;
  newStu.printStats();
  // studentTree.insert(student.m_ID, student);
  // addStudent(newStu);
  cout<<"Student added. "<<endl;

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
void DataBase::addFac(){
  string name;
  int ID;
  string level;
  string department;
  DoublyLinkedList<Student> *advisees = new DoublyLinkedList<Student>();
  cout <<"Enter Faculty's Name: "<<endl;
  cin>>name;
  cout<< "enter ID: " <<endl;
  cin>>ID;
  cout<<"Enter Level: "<<endl;
  cin>>level;
  cout<<"Enter Department: "<<endl;
  cin>>department;
  while(true){
    int advisee;
    cout<<"Enter 1 to Add Student Advisee or anything else to stop."<<endl;
    cin>>advisee;
    if(advisee==1){
      int stuID;
      cout<<"Enter ID of Student Advisee: "<<endl;
      cin>>stuID;
      advisees->insertBack(studentTree.returnFromKey(stuID));
    }
    else{
      break;
    }

  }

  Faculty fac(name,ID,level,department,advisees);
  addFac(fac);
  cout<<"Faculty Added."<<endl;
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

void DataBase::runDB(){
  // 1) Print all students and their information
  // 2.Print all faculty and their information
  // 3.Find and display student information given the students id
  // 4.Find and display faculty information given the faculty id
  // 5.Given a student’s id, print the name and info of their faculty advisor
  // 6.Given a faculty id, print ALL the names and info of his/her advisees.
  // 7.Add a new student
  // 8.Delete a student given the id
  // 9.Add a new faculty member
  // 10.Delete a faculty member given the id.
  // 11.Change a student’s advisor given the student id and the new faculty id.
  // 12.Remove an advisee from a faculty member given the ids
  // 13.Rollback
  // 14.Exit
  int choice1;
  cout<<"enter a choice: \n1) Print all students and their information\n2)Print all faculty and their information \n3.Find and display student information given the students id\n4.Find and display faculty information given the faculty id\n5.Given a student’s id, print the name and info of their faculty advisor\n6.Given a faculty id, print ALL the names and info of his/her advisees.\n7.Add a new student\n8.Delete a student given the id\n9.Add a new faculty member\n10.Delete a faculty member given the id.\n11.Change a student’s advisor given the student id and the new faculty id.\n12.Remove an advisee from a faculty member given the ids\n13.Rollback \n14.Exit"<<endl;
  cin>>choice1;

  if(choice1 == 1){
    //print all students
    printStudents();
  }

  else if(choice1 ==2){
    //print all faculty
    printFac();
  }

  else if(choice1 == 3){
    //print student info given ID
    int inputID;
    cout<<"Enter Student ID You Want To Print: "<<endl;
    cin >> inputID;
    printStudentFromID(inputID);
  }
  else if(choice1 ==4){
    //print info given Fac ID
    int facOut;
    cout<<"Enter Faculty ID You Want To Print: "<<endl;
    cin>>facOut;
    printFacID(facOut);
  }
  else if(choice1 == 5){
    //given studet ID print info of advisor

  }
  else if(choice1 ==6){
    //given facID print all info and names of advisees
  }
  else if(choice1 ==7){
    //add a new student
    cout<<endl;
    addStudent();
  }
  else if(choice1 ==8){
    int stuID;
    cout<<"Enter ID of Student You Want Deleted: "<<endl;
    cin>>stuID;
    deleteStudent(stuID);
    //delete student given the ID
  }
  else if(choice1 ==9){
    //add new fac member
    addFac();
  }
  else if(choice1 ==10){
    //delete fac given ID
    int facID;
    cout<<"Enter ID of Faculty You Want Deleted: "<<endl;
    cin>>facID;
    deleteFac(facID);
  }
  else if(choice1 == 11){
    //change student's advisors given stu ID and new fac ID
  }
  else if(choice1 ==12){
    // remove advisee from fac member given ID
  }
  else if(choice1 == 13){
    // rollback
  }
  else if(choice1 == 14){
    // break;
  }


}
#endif
