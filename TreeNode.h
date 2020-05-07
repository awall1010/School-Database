#ifndef TREENODE_H
#define TREENODE_H

#include <unistd.h>
#include <iostream>
using namespace std;

template <class T>
class TreeNode{
public:
  TreeNode();
  TreeNode(int key, T data);
  ~TreeNode();
  int key;
  T data;
  TreeNode *left;
  TreeNode *right;

};

template <class T>
TreeNode<T>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, T val){
  key = k;
  data = val;
  left = NULL;
  right = NULL;
}


template <class T>
TreeNode<T>::~TreeNode(){

}




#endif
