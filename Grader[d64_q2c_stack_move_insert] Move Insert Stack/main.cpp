#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  CP::stack<T> temp;
  if(k > mSize) k = mSize;
  if(m > s2.size()) m = s2.size();
  for (int i = 0; int i < size - 1 - k;i++) temp.push(mData[i]);
  for (int i = m; int i > 0;i--) temp.push(s2.mData[s2.size() - i]);
  for (int i = size - 1 - k; int i < size;i++) temp.push(mData[i]);
  s2.mSize -= m;
  *this = temp;
}
#endif
