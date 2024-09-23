#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

class Solution {
public:
    int numSteps(string s) {
        return numStepsHelper(s);
    }

private:
    int numStepsHelper(string& s){
        //base case
        if(s.length() == 1) return 0;

        if(s.back() == '0') {
            s.pop_back();
            return 1 + numStepsHelper(s);
        }
        else{
            int c = 0;
            while(s.back() == '1')  {
                s.pop_back();
                c++;
            }
            if(!s.empty())s.back() = '1';
            return 1 + numStepsHelper(s);
        }
    }
};
