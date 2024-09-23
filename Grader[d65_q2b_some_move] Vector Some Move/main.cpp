#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  int i = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
  if (index < mSize) {
      if (i > 0)
        index -= aux[i - 1];
      if (index == 0){
          mData.insert(mData.begin() + i,value);
          int aux_value = (i - 1 < 0 ) ? value.size() : aux[i-1] + value.size();
          aux.insert(aux.begin() + i,aux_value);

          for (size_t j = i + 1; j < aux.size(); ++j){
            aux[j] += value.size();
          }
      }
      else {
          mData[i].insert(mData[i].begin() + index, value.begin(),value.end());
          for (size_t j = i ; j < aux.size();++j){
            aux[j] += value.size();
          }
     }
  }
  else {
    mData.insert(mData.end(),value);
    aux.push_back(aux[aux.size()-1] + value.size());

  }
   mSize += value.size();
   mCap += value.size();

}

#endif
