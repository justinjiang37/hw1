#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const std::string& val) {
  cout << "HI" << endl;
  if (size_ == 0) {
    Item* n = new Item();
    n->val[0] = val;
    n->last = 1;
    size_ = 1;
    head_ = n;
    tail_ = n;
    cout << "HI" << endl;
  }
  else {
    // list is full
    if (tail_->last == 10) {
      // create new item
      Item* n = new Item();
      n->val[0] = val;
      n->last = 1;
      // Add new item to end of linked list;
      tail_->next = n;
      n->prev = tail_;
      tail_ = n;
      size_++;
    }
    // list is not full
    else {
      tail_->val[tail_->last] = val;
      tail_->last++;
      size_++;
    }
  }
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back() {
  // If only one element in the list
  if (size_ == 1) {
    delete head_;
    size_ = 0;
  } else {
   // If pops the last element in tail item
    if (tail_->last == 1) {
      Item* temp = tail_;
      tail_->prev->next = NULL;
      tail_ = tail_->prev;
      delete temp;
      size_--;
    } 
    // There is more than one element in the tail item
    else if (tail_->last > 1) {
      // remove item at index last-1
      tail_->last -= 1;
      size_--;
    } 
  }
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val) {
  if (size_ == 0) {
    Item* n = new Item();

    // Adds the val to the last element of the array
    n->val[0] = val;
    n->last = 1;

    size_ = 1;
    head_ = n;
    tail_ = n;

    // cout << *n->val << endl;
  }
  else {
    // list is full
    if (head_->first == 0) {
      // create new item
      Item* nItem = new Item();
      nItem->val[9] = val;
      nItem->last = 10;
      nItem->first = 9;
      // Add new item to front of front linked list
      nItem->next = head_;
      head_->prev = nItem;
      head_ = nItem;
      size_++;
      // cout << head_->val[9] << endl;
      // cout << tail_->val[0] << endl;
    }
    // list is not full
    else {
      head_->val[head_->first-1] = val;
      head_->first--;
      size_++;
      // cout << head_->val[8] << endl;
      cout << head_->val[8] << endl;
      cout << head_->val[9] << endl;
      cout << tail_->val[0] << endl;
      cout << "location: " << *getValAtLoc(0) << endl;
      cout << "location: " << *getValAtLoc(1) << endl;
      cout << "location: " << *getValAtLoc(2) << endl;
    }
  }
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front() {
  if (size_ == 1) {
    delete tail_;
    size_ = 0;
  } else {
    // If pops the last element in head item
    if (head_->first == 9) {
      Item* temp = head_;
      head_->next->prev = NULL;
      head_ = head_->next;
      delete temp;
      size_--;
    } 
    // There is more than one element in the head item
    else if (head_->first < 9) {
      // remove item at index first
      head_->first += 1;
      size_--;
    }
  }
}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

/** 
  * Returns a pointer to the item at index, loc,
  *  if loc is valid and NULL otherwise
  *   - MUST RUN in O(n) 
  */
std::string* ULListStr::getValAtLoc(size_t loc) const {
  Item* temp_Item = head_;
  int ind = head_->first;
  int total = 0;
  int count = 0;
  while (count < loc) {
    // if reached last element of an item
    if (ind == temp_Item->last-1) {
      // cout << "Hi";
      total += 10;
      temp_Item = temp_Item->next;
      // index out of bounds
      if (temp_Item == NULL) {
        return NULL;
      }
    }
    ind++;
    count++;
  }

  // cout << "i: " << ind << endl;
  // cout << "t: " << total << endl;
  return &temp_Item->val[ind-total];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
