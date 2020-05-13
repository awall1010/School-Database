#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include <cstddef>
#include <iostream>
#include "LN.h"
using namespace std;


///header file for my DoublyLinkedList
template<class T>
class DoublyLinkedList{
private:
  // ListNode *front;
  // ListNode *back;
  // unsigned int size;
public:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;

  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertFront(T data);
  void insertBack(T data);
  T removeBack();
  T removeFront();
  T search(T val); //will return value or position of node depending on implementation
  void removeAtPos(T pos);
  T viewFront();


  int getSize();
  bool isEmpty();
  void printList();


  // ListNode *front;
  // ListNode *back;
  // unsigned int size;

};




// this is where we implement

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = new ListNode<T>();
  back = new ListNode<T>();
  // front = NULL;
  // back = NULL;
  front->next = back;
  back->prev = front;

}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //build some character

}

template<class T>
int DoublyLinkedList<T>::getSize(){
  return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty(){
  return(size==0);
}

template<class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front; //create temporary pointer

  while(curr!= NULL){
    cout<< curr->data <<endl; //print current data
    curr=curr->next; //update current pointer to make next;
  }
}

template<class T>
void DoublyLinkedList<T>::insertFront(T d){
      ListNode<T> *node = new ListNode<T>(d);
      //check if isEmpty
      if(isEmpty()){
        back = node;
      }
      else{
        //not empty
        front->prev = node;
        node->next = front;
      }
      front = node;
      size++;
}


template<class T>
void DoublyLinkedList<T>::insertBack(T d){
      ListNode<T> *node = new ListNode<T>(d);
      //check if isEmpty
      if(isEmpty()){
        front = node;
      }
      else{
        //not empty
        back->next = node; //next pointer back = node
        node->prev = back; //node previous = back

      }
      back = node; //update back to now = node

      size++; //increment size


}



template<class T>
T DoublyLinkedList<T>::removeFront(){
  size--;
  T temp = front->data;
  ListNode<T> *ft = front; //have to create because after you update front, have to delete the old front and if no reference to it its lost
  front = front->next;
  ft->next = NULL;//set first value = null before you can delete
  delete ft;
  return temp;
}

template<class T>
T DoublyLinkedList<T>::viewFront(){
  return front->data;
}


template<class T>
T DoublyLinkedList<T>::search(T value){
  int position = -1;
  ListNode<T> *curr = front;

  while(curr!= NULL){
    //iterate and attempt to find value
    position++;
    if(curr->data ==value){ //if data at current place == value
      break;
    }
    else{
      curr = curr->next;
    }
  }
  if (curr==NULL){
    position = -1; //means we iterated all the way through and didnt find it.
  }

  return position;
}

template <class T>
void DoublyLinkedList<T>::removeAtPos(T value){
  // cout<<"IN LL"<<endl;
  ListNode<T> *curr = front;
  // cout<<"Node Created"<<endl;
  while(curr->data !=value){
    //iterate and attempt to find value
    curr = curr->next;
    if (curr==NULL){
      // position = -1; //means we iterated all the way through and didnt find it.
      cout<<"KEY NOT FOUND."<<endl;
    }
  }
  // cout<<"FOUND DATA: "<< curr->data<<endl;
  // if (curr==NULL){
  //   // position = -1; //means we iterated all the way through and didnt find it.
  // }



  if(curr!=back){
    curr->next->prev = curr->prev;
    // cout<<"update 1"<<endl;
  }
  // curr->next->prev = curr->prev;
  // cout<<"update 1"<<endl;
  if(curr != front){
    curr->prev->next = curr->next;
    // cout<<"update 2"<<endl;
  }
  // curr->prev->next = curr->next;
  // cout<<"update 2"<<endl;
  curr->next = NULL;
  // cout<<"set null 1"<<endl;
  curr->prev = NULL;
  // cout<<"set null 2"<<endl;
  delete curr;
  // cout<<"delete curr"<<endl;

  size--;


}


#endif
