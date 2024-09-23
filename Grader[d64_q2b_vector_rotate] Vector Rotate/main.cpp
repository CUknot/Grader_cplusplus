#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  T temp[k];
  int i = 0;
  for(auto it = first; it < first + k; it++, i++)temp[i] = *it;
  for(auto it = first; it < last - k; it++, i++) *it = *(it + k);
  i = k - 1;
  for(auto it = last ; it > last - k; it--, i--) *it = T[i];
}

#endif
