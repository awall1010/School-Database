#ifndef DATABASE_H
#define  DATABASE_H
// #include "Student.h"
#include <fstream>
#include "Faculty.h"
#include "BST.h"
#include "Student.h"
#include "LL.h"

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
  void writeStudents(Student student);
  void writeFaculty(Faculty faculty);
  void runDB();

};

DataBase::DataBase(){

}

void DataBase::addStudent(Student student){
  // cout<<"TRYING TO INSERT."<<endl;
  studentTree.insert(student.m_ID, student);
  writeStudents(student);
}

void DataBase::addStudent(){
  string name;
  int ID;
  string grade;
  string major;
  double gpa;
  int advisor;
  cout <<"Enter Student's Name: "<<endl;
  // cin>>name;
  getline(cin>>ws,name);
  cout<< "enter ID: " <<endl;
  cin>>ID;
  cout<<"Enter Class Standing: "<<endl;
  // cin>>grade;
  getline(cin>>ws,grade);
  cout<<"Enter Major: "<<endl;
  // cin>>major;
  getline(cin>>ws,major);
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
  addStudent(newStu);
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
  writeFaculty(fac);
}
void DataBase::addFac(){
  string name;
  int ID;
  string level;
  string department;
  DoublyLinkedList<int> *advisees = new DoublyLinkedList<int>();
  cout <<"Enter Faculty's Name: "<<endl;
  // cin>>name;
  getline(cin>>ws,name);
  cout<< "enter ID: " <<endl;
  cin>>ID;
  cout<<"Enter Level: "<<endl;
  // cin>>level;
  getline(cin>>ws,level);
  cout<<"Enter Department: "<<endl;
  // cin>>department;
  getline(cin>>ws,department);
  while(true){
    int advisee;
    cout<<"Enter 1 to Add Student Advisee or any other INT to stop."<<endl;
    cin>>advisee;
    if(advisee==1){
      int stuID;
      cout<<"Enter ID of Student Advisee: "<<endl;
      cin>>stuID;
      // advisees->insertBack(studentTree.returnFromKey(stuID));
      advisees->insertBack(stuID);
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
void DataBase::writeStudents(Student S){
  ofstream file;
  file.open("students.txt", ios::app);
  file<<endl;
  file<<S.m_name<<endl;
  file<<S.m_ID<<endl;
  file<<S.m_level<<endl;
  file<<S.m_major<<endl;
  file<<S.m_GPA<<endl;
  file<<S.m_advisorID<<endl;
  file<<endl;
}
void DataBase::writeFaculty(Faculty F){
  ofstream file;
  file.open("faculty.txt", ios::app);
  file<<endl;
  file<<F.m_name<<endl;
  file<<F.m_ID<<endl;
  file<<F.m_level<<endl;
  file<<F.m_department<<endl;
  // file<<F.m_advisees->printList();


  for(int i = 0; i<F.m_advisees->size;++i){
    file<<F.m_advisees->front->data;
    F.m_advisees->front=F.m_advisees->front->next;
    file<<endl;
  }


  file<<endl;
}

void DataBase::deleteFac(int facultyID){
  facultyTree.deleteNode(facultyID);
}


void DataBase::printStudentFromID(int studentID){
  cout<<"IM HERE"<<endl;
  studentTree.printFromKey(studentID);
}

void DataBase::printFacID(int facultyID){
  facultyTree.printFromKey(facultyID);
}

void DataBase::runDB(){

  while(true){
  int choice1;
  cout<<"enter a choice: \n1. Print all students and their information\n2. Print all faculty and their information \n3. Find and display student information given the students id\n4. Find and display faculty information given the faculty id\n5. Given a student’s id, print the name and info of their faculty advisor\n6. Given a faculty id, print ALL the names and info of his/her advisees.\n7. Add a new student\n8. Delete a student given the id\n9. Add a new faculty member\n10. Delete a faculty member given the id.\n11. Change a student’s advisor given the student id and the new faculty id.\n12. Remove an advisee from a faculty member given the ids\n13. Rollback \n14. Exit"<<endl;
  cin>>choice1;
  cout<<endl;

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
    //given student ID print info of advisor
    int stuID;
    cout<<"Enter Student ID: "<<endl;
    cin>>stuID;
    cout<< "FACULTY INFO: "<<endl;
    printFacID(studentTree.returnFromKey(stuID).getAdvisor());



  }
  else if(choice1 ==6){
    //given facID print all info and names of advisees
    int facID;
    cout<<"Enter Faculty ID. "<<endl;
    cin>>facID;
    // while(!facultyTree.returnFacKey(facID).m_advisees->isEmpty()){
    for(int i = 0; i<facultyTree.returnFacKey(facID).m_advisees->size;++i){
      // cout<<"NO PRINT"<<endl;
      // cout<<"should be "<<facultyTree.returnFacKey(facID).m_advisees->front->data<<endl;
      printStudentFromID(facultyTree.returnFacKey(facID).m_advisees->front->data);
      cout<<"print"<<endl;
      facultyTree.returnFacKey(facID).m_advisees->front=facultyTree.returnFacKey(facID).m_advisees->front->next;
    }
    // printStudentFromID(facultyTree.returnFacKey(facID).m_advisees->front->data);

    // }

  }
  else if(choice1 ==7){
    //add a new student

    cout<<endl;
    addStudent();
    // break;
  }
  else if(choice1 ==8){
    int stuID;
    cout<<"Enter ID of Student You Want Deleted: "<<endl;
    cin>>stuID;
    deleteStudent(stuID);
    //delete student given the ID
    // break;
  }
  else if(choice1 ==9){
    //add new fac member
    addFac();
    // break;
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
    int stuID;
    int facultyID;
    cout<<"Enter the ID of the Student Yout Want To Update:"<<endl;
    cin>>stuID;
    cout<<"Enter New Faculty ID: "<<endl;
    cin>>facultyID;
    cout<<"Old faculty ID: "<< studentTree.returnFromKey(stuID).getAdvisor()<<endl;
    studentTree.returnFromKey(stuID).setAdvisor(facultyID);
    // cout<<"New Faculty ID: "<<studentTree.returnFromKey(stuID).getAdvisor()<<endl;


  }
  else if(choice1 ==12){
    // remove advisee from fac member given ID
    int stuID;
    int facID;
    cout<<"Enter Faculty ID You Want: "<<endl;
    cin>>facID;
    cout<<"Enter Advisee You Want Removed: "<<endl;
    cin>>stuID;
    // Faculty fac = facultyTree.returnFacKey(facID);
    facultyTree.returnFacKey(facID).removeAdvisee(stuID);

    // fac.m_advisees->removeAtPos(stuID);

  }

  else if(choice1 == 13){
    // rollback
    cout<<"Sorry, This Feature is Not Available right now, shouldn't have messed up!"<<endl;
  }
  else if(choice1 == 14){
    break;
  }
  else{
    cout<<"INVALID CHOICE TRY AGAIN."<<endl;
  }
cout<<endl;
}

}
#endif
