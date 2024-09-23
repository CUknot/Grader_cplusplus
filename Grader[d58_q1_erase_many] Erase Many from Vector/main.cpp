#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  CP::vector<T> temp;
  auto it = begin();
  auto itp = pos.begin();
  while(it != end()){
    if(itp == pos.end() || it - begin() != *itp){
        temp.push_back(*it);
    }
    else itp++;
    it++;
  }
  *this = temp;
}

#endif
