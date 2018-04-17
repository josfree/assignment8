#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "node.h"

class binary_search_tree
{
    public:
      binary_search_tree();
      ~binary_search_tree();
      void insert(string key, int value);
      void print();
      void deleteNode(string key);
      void deleteHelper(Node* &current, string key);
      string findMax();
      string findMin();
      void locate(string word);
      void locateHelper (Node* &current,string Word);
      void save(string inFile);
      void saveHelper (Node* current, std::ofstream& myOutFile);

    private:
      Node *root;
      void insertHelper(Node *current, string key, int value);
      void printHelper(Node *current);
      void destructorHelper(Node* current);

};

#endif // BINARYSEARCHTREE_H
