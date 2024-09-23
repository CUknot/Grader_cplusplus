#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  std::vector<std::vector<T>> output(k);
  CP::stack<T> temp = *this;
  for(int i = 0; i < k; i++){
    int s = temp.mSize/(k - i) + (temp.mSize%k == 0);
    for(int j = 0; j < s; j++){
     output[i].pushback(temp.top()); temp.pop();
    }
  }
  return output;
}
#endif
