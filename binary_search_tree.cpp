#include "binary_search_tree.h"
#include <iostream>
#include <string>
using namespace std;


binary_search_tree::binary_search_tree() {
  root = NULL;
}


binary_search_tree::~binary_search_tree() {
  destructorHelper(root);
}

void binary_search_tree::destructorHelper(Node *current) {
  if(current != NULL) {
    destructorHelper(current->left);
    destructorHelper(current->right);
    delete current;
  }
}

void binary_search_tree::insert(string key, int value) {
  if(root == NULL)
    root = new Node(key,value);
  else
    insertHelper(root, key, value);
}


void binary_search_tree::insertHelper(Node *current, string key, int value) {
  if(value < current->data) {
    //Insert Left
    if(current->left == NULL)
      current->left = new Node(key,value);
    else
      insertHelper(current->left, key, value);
  }
  else {
    //Insert Right
    if(current->right == NULL)
      current->right = new Node(key, value);
    else
      insertHelper(current->right, key, value);
  }

}

void binary_search_tree::print() {
  printHelper(root);
  cout << endl;
}

void binary_search_tree::printHelper(Node *current) {
  // In-order traversal.
  if(current != NULL) {
    printHelper(current->left);
    cout << current->data << " ";
    cout << current->key << " ";
    printHelper(current->right);
  }
}
/*
void binary_search_tree::deleteNode(string key) {
  deleteHelper(root, key);
}

void binary_search_tree::deleteHelper(Node* &current, string key) {

  if(current == NULL)
    return;
  //Go left
  else if(key < current->key)
    deleteHelper(current->left, key);
  //Go right
  else if(current->key < key)
    deleteHelper(current->right, key);
  //Equal
  else {
    Node *temp;

    if(current->left == NULL) {
      temp = current->right;
      delete current;
      current = temp;
    }
    else if(current->right == NULL) {
      temp = current->left;
      delete current;
      current = temp;
    }
   
    else {
      temp = current->right;
      Node *parent = NULL;

      while(temp->left != NULL) {
	parent = temp;
	temp = temp->left;
      }

      current->data = temp->data;

      if(parent != NULL)
	deleteHelper(parent->left,parent->left->key, parent->left->data);
      else
	deleteHelper(current->right, current->right->key, current->right->data);

    }
  }
}
*/
string binary_search_tree::findMax(){
  Node* current = root;
  if(current == NULL){
    return "There is no max";
  }
  else{
    while(current->right != NULL){
      current = current->right;
    }
  return current->key;
  }
}

string binary_search_tree::findMin(){
  if(root == NULL){
    return "There is no min";
  }
  Node *current = root;
  if ((current->left == NULL)&&(current->right==NULL)){
    return current->key;
  }
  while(current->left != NULL){
    current = current->left;
  }
  return current->key;
}

void binary_search_tree::locate(string Word){
  locateHelper(root,Word);
}

void binary_search_tree::locateHelper(Node* &current,string Word){
  if(current == NULL)
    return;
  else if( Word < current->key)
    locateHelper(current->left,Word);
  else if(current->key < Word)
    locateHelper(current->right,Word);
  cout << "The string " << Word << " has the value of " << current->data << endl;
  return;

}
/*
void binary_search_tree::save(string inFile){

  ofstream myOutFile;
  outFile.open(inFile.c_str());

  saveHelper(root, outFile);
  myOutFile.close();
}

void binary_search_tree::saveHelper(Node *current, std::ofstream& outFile){

  if(current != NULL){
    saveHelper(current->left, outFile);
    myOutFile << current->key << " " << current ->data << endl;
    saveHelper(current->right, oFile);
  }
}
*/
