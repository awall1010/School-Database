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
  cout<<node->data<<endl;
  printTree(node->right);
}

template <class T>
void BST<T>::insert(int key, T val){
  TreeNode<T> *node = new TreeNode<T>(key,val);

  if(isEmpty()){
    root = node;
  }
  else{

    TreeNode<T> *curr = root; //start at the root
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
bool BST<T>::search(int place){
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
bool BST<T>::deleteNode(int k){
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
  if(curr->left == NULL && curr->right == NULL) {
  //then we have a leaf TreeNode
  //have to determine if left or right and if root nodee
  if(curr == root)
    root = NULL;
  else if (isLeft){
    parent->left = NULL;
  }

  else{
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

      //node we are deleting has a child thats a left child
      //this else if determines position of node to be deleted
  }

  else if(curr->left == NULL) //no right child, so must have left child
{
  //these branching statements identify position of node to be deleted
  if(curr == root)
    root = curr->left;
  else if(isLeft)
    parent->left = curr->right;
  else
    parent->right = curr->right;
    //node we are deleting has a child thats a left child
 }

 else{
     //the node to be deleted has two children
     //at this point we being to cry and bang our heads while listening to music

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


     //connect/link successor to current's (D) left child
     successor->left = curr->left;

     return true;

   }




}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {
  //the parameter d represents the node to be deleted
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
