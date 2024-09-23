#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  if (K > mSize) K = mSize;
  mSize -= K;
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  if (K > mSize) K = mSize;
  std::stack<T> temp;
  for(int i = mSize - K; i != mSize; i++) temp.push(mData[i]);
  mSize -= K;
  return temp;
  //
  //don't forget to return an std::stack
}

#endif
