#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  CP::vector<T> temp;
  std::sort(data.begin(),data.end());
  int index = 0;
  for(int i = 0; i < mSize; i++){
    if (index < data.size() && i == data[index].first){
        temp.push_back(data[index].second);
        index++;
    }
    temp.push_back(mData[i]);
  }
  *this = temp;
}

#endif
