#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  CP::vector<T> temp;
  for(auto it1 = begin(); it1 < end(); it1++){
    if(it1 == position){
        for(auto it2 = first; it2 < last; it2++){
            temp.push_back(*it2);
        }
    }
    temp.push_back(*it1);
  }
  *this = temp;
}

#endif
