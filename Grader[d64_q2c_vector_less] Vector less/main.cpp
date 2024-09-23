#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
  if(mSize == 0 && other.size() != 0) return true;
  for(int i = 0; i < mSize; i++){
    if(other.size() - 1 < i) return false;
    if(mData[i] < other[i]) return true;
    if(mData[i] < other[i]) return false;
  }
  return false;
}

#endif
