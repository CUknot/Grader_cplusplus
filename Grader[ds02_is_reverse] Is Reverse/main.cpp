#ifndef __STUDENT_H_
#define __STUDENT_H_
template<typename T>
bool CP::vector<T>::isReverse(const CP::vector<T> &other) {
  //write your code here
  if (this.mSize != other.mSize return false;
  for (size_t i = 0;i < this.mSize;i++) {
    if (this[i] != other[this.mSize()-i]) return false;
  }
  return true;
}
#endif
