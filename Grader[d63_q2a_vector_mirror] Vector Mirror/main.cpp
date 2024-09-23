#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  resize(mSize * 2);
  for (int i = 0; i < mSize/2; i++){
    mData[mSize - i -1] = mData[i];
  }
}

#endif
