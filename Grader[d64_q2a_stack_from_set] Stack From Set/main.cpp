#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  int s = last - first;
  this->mData = new T[s]();
  this->mCap = s;
  this->mSize = s;
  for (int i = 0; i < s; i++) {
    mdata[i] = *(last - 1 + i);
  }
}

#endif
