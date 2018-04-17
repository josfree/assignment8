#include <iostream>
#include "binary_search_tree.h"
#include <string>


using namespace std;

int main()
{
  int userChoice;
    binary_search_tree  tree;
    bool end = false;

    while (end != true){

    tree.insert("This",30);
    tree.insert("is", 4);
    tree.insert("difficult",9);
    tree.insert("for", 3);
    tree.insert("me", 1);

    tree.print();
    cout << "1: Insert in the binary search tree" << endl;
    cout << "2: Find" << endl;
    cout << "3: Print " << endl;
    cout << "4: Locate Max" << endl;
    cout << "5: Locate Min" << endl;
    cout << "6: Save progress " << endl;
    cout << "7: Delete" << endl;
    cin >> userChoice;
    cout << endl;
    //menu driven by choice
    if (userChoice == 1){
      string key;
      int value;
      cout << "Enter key";
      cin >> key;
      cout << "Enter value";
      cin >> value;
      tree.insert(key, value);
    }

    if(userChoice == 2){
      string word;
      cout << "Enter a word you would like to find" << endl;
      cin >> word;
      tree.locate(word);
    }
    if(userChoice == 3){
      tree.print();
    }
    if(userChoice == 4){
      string max = tree.findMax();
      cout << "Max: " <<  max << endl;
    }
    if(userChoice == 5){
      string min = tree.findMin();
      cout << "Min: " << min << endl;

    }
    if(userChoice == 6){
      string fileName;
      cout << "Enter file save name" << endl;
      cin >> fileName;
      // tree.save(fileName);
    }
    if(userChoice == 7){
      string key;
      cout << "Enter the key of node you want to delete!" << endl;
      cin >> key;
      // tree.deleteNode(key);
    }
    else
      end == true;

}

  return 0;
}

