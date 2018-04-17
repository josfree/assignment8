#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node
{
    public:
      Node(string key, int value);
      Node();
      ~Node();
      Node *left, *right;
      int data;
      string key;
};

#endif // NODE_H
