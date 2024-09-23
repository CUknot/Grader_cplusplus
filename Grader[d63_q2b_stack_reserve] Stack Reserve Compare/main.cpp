#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    int thisReserve = this->mCap - this->mSize;
    int otherReserve = other.mCap - other.mSize;
    if (thisReserve > otherReserve) return 1;
    else if (thisReserve == otherReserve) return 0;
    else if (thisReserve < otherReserve) return -1;
}

#endif
