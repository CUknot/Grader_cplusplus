#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if (a > b) std::swap(a,b);
  if (begin() > a || begin() > b) return false;
  if (a + m > end() || b + m > end()) return false;
  if (a == b || a + m > b)return false;
  return true
}

#endif
