/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>

/* Add a prototype for a helper function here if you need */
void addToBack(Node* val, Node*& list);
// void popFront(Node*& in);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  if (in == nullptr) {
    return;
  }
  // If its even
  else if (in->value % 2 == 0 || in->value == 0) {
    // add "in" to back of "evens"
    Node* temp = in;
    in = in->next;
    addToBack(temp, evens);
    split(in, odds, evens);
    in = nullptr;
  }
  // If odd
  else {
    // add "in" to back of "odds"
    Node* temp = in;
    in = in->next;
    addToBack(temp, odds);
    split(in, odds, evens);
    in = nullptr;
  }
}

/* If you needed a helper function, write it here */
// void getFrontNode(Node*& in) {
  
// }

void addToBack(Node* val, Node*& list) {
  if (list == nullptr) {
    val->next = nullptr;
    list = val;
  }
  else if (list->next == nullptr) {
    val->next = nullptr;
    list->next = val;
  } else {
    addToBack(val, list->next);
  }
}
