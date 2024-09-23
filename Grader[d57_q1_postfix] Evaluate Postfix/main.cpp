#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <stack>
#include <vector>
using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  stack<int> s;
  for (auto &x: v){
    if (x.first == 1){
        s.push(x.second);
    }
    else{
        int temp2 = s.top();s.pop();
        int temp1 = s.top();s.pop();
        int toPush = 0;
        switch(x.second){
            case 0: toPush = temp1 + temp2; break;
            case 1: toPush = temp1 - temp2; break;
            case 2: toPush = temp1 * temp2; break;
            case 3: toPush = temp1 / temp2; break;
        }
        s.push(toPush);
    }
  }
  return s.top();
}

#endif
