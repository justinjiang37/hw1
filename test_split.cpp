/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "HI";
  
  Node* five = new Node(5, NULL);
  Node* four = new Node(4, five);
  Node* three = new Node(3, four);
  Node* two = new Node(2, three);
  Node* head = new Node(1, two);

  Node* temp = head;
  while (temp -> next != NULL) {
    temp = temp->next;
    // std::cout << temp->value;
  }

  Node* odds = nullptr;
  Node* evens = nullptr;
  // split(head, odds, evens);
}
