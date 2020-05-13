#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>
#include "TreeNode.h"

template <class T>
class BST{
private:
  // TreeNode<T> *root;
public:
  BST();
  ~BST();
  TreeNode<T> *root;
  void insert(int k, T data);
  bool search(int key);
  bool deleteNode(int key);

  bool isEmpty();

  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  TreeNode<T>* getSuccessor(TreeNode<T> *d);


  void printTree(TreeNode<T> *node);
  void printFromKey(int key);
  Student returnFromKey(int key);
  Faculty returnFacKey(int key);


};


template <class T>
BST<T>::BST(){
  root = NULL;
}

template <class T>
BST<T>::~BST(){

}

template <class T>
bool BST<T>::isEmpty(){
  return (root==NULL);
}

template <class T>
TreeNode<T> *BST<T>::getMax(){
  TreeNode<T> *curr = root;

  if(root == NULL){
    return NULL;
  }
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}

template <class T>
TreeNode<T> *BST<T>::getMin(){
  TreeNode<T> *curr = root;

  if(root == NULL){
    return NULL;
  }
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}


template <class T>
void BST<T>::printTree(TreeNode<T> *node){
  if(node == NULL){
    return;
  }
  printTree(node->left);
  node->data.printStats();
  printTree(node->right);
}

template <class T>
void BST<T>::insert(int key, T val){
  TreeNode<T> *node = new TreeNode<T>(key,val);

  if(isEmpty()){
    root = node;
  }
  else{

    TreeNode<T> *curr = root; //we need to start at the root
    TreeNode<T> *parent;
    while(true){
      parent = curr;
      if(key < curr->key){
            //go left
        curr = curr->left;
        if(curr == NULL){
          parent->left = node;
        }
          }
          else{
            //go right
            curr = curr->right;
            if(curr == NULL){
              parent->right = node;
              break;
            }
          }
        }
      }

  }


template <class T>
bool BST<T>::search(int place){ //search function
  if(isEmpty()){
    return false;
  }
  else{
    TreeNode<T> *curr = root;

    while(curr->key != place){
      if(place<curr->key){
        curr = curr->left;
      }
      else{
        curr = curr->right;
      }
      if(curr == NULL){
        return false;
      }
    }

  }
  return true;
}


template <class T>
bool BST<T>::deleteNode(int k){ //delete node
  if(isEmpty()){
    return false;
  }
  TreeNode<T> *parent = root;
  TreeNode<T> *curr = root;

  bool isLeft = true;

  while(curr->key != k){
    parent = curr;

    if(k< parent->key){
      isLeft = true;
      curr = curr->left;
    }
    else{
      isLeft = false;
      curr = curr->right;
    }
    if(curr == NULL){
      return false;
    }


  }
  if(curr->left == NULL && curr->right == NULL) { //then it is a leaf

  if(curr == root)
    root = NULL;
  else if (isLeft){ //if it  is Left
    parent->left = NULL;
  }

  else{ //if its right
    parent->right = NULL;
  }

}
else if(curr->right == NULL) //no right child, so must have left child
  {
    if(curr == root){
      root = curr->left;
    }
    else if(isLeft){
      parent->left = curr->left;
    }
    else{
      parent->right = curr->left;
    }


  }

  else if(curr->left == NULL) //no right child so left
{

  if(curr == root)
    root = curr->left;
  else if(isLeft)
    parent->left = curr->right;
  else
    parent->right = curr->right;

 }

 else{ //two children



     TreeNode<T> *successor = getSuccessor(curr);

     if(curr == root){
       root = successor;
     }

     else if (isLeft){
       parent->left = successor;
     }

     else{
       parent->right = successor;
     }



     successor->left = curr->left;

     return true;

   }




}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {

  TreeNode<T> *curr = d->right;
  TreeNode<T> *succPar = d; //successor parent
  TreeNode<T> *successor = d;

  while(curr != NULL) {
    succPar = successor;
    successor = curr;
    curr = curr->left;
  }
  if(successor != d->right){
    succPar->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template <class T>
void BST<T>::printFromKey(int k){
  TreeNode<T> *curr = root;

  while(curr->key != k){
    if(k<curr->key){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
    if(curr == NULL){
      cout<<"no matching value. "<<endl;
    }
  }
  curr->data.printStats();
}

template <class T>
Student BST<T>::returnFromKey(int k){
  TreeNode<T> *curr = root;
  while(curr->key != k){
    if(k<curr->key){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
    if(curr == NULL){
      cout<<"no matching value. "<<endl;
    }
  }
  return curr->data;
}

template <class T>
Faculty BST<T>::returnFacKey(int k){
  // cout<<"ENTERING RETURNFACKEY"<<endl;
  TreeNode<T> *curr = root;
  while(curr->key != k){
    if(k<curr->key){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
    if(curr == NULL){
      cout<<"no matching value. "<<endl;
    }
  }
  // cout<<"EXITING RETURN FAC "<<endl;
  return curr->data;
  // cout<<"returned DATA"<<endl;
}

#endif
