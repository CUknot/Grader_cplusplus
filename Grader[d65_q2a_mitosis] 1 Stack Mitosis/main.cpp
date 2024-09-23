#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    CP::stack<T> temp;
    for(int i = 0; i < mSize; i++){
        if (a <= mSize - 1 - i && mSize - 1 - i <= b) temp.push(mData[i]);
        temp.push(mData[i]);
    }
    *this = temp;
}

#endif
