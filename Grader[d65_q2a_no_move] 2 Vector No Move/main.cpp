#ifndef STUDENT_H
#define STUDENT_H

#include <algorithm>

template<typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
    int bs = upper_bound(aux.begin(),aux.end(),idx) - aux.begin();
    int rem = idx;
    if(bs != 0) rem-=aux[bs-1];
    return mData[bs][rem];

}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
    //your code here
    //you MAY need this function
    if(aux.empty()){
        aux.push_back(mData.back().size());
        return 0;
    }
    aux.push_back(mData.back().size() + aux.back());
}
#endif // STUDENT_H

