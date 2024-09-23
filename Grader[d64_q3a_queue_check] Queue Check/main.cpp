#include <iostream>
#include <algorithm>

using namespace std;

bool check(const int& front, const int& size, const int& cap, const int& last) {
    if (cap == 0) return false;
    if (front != (last - size + cap) % cap) return false;
    if (cap < size) return false;
    if (cap <= front || cap <= last) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int action;
        int front, size, cap, last;
        cin >> front >> size >> cap >> last >> action;

        int Array[4] = {front + 1, last + 1, size, front + size - last}; // Declare Array before switch

        if (!check(front, size, cap, last)) {
            cout << "WRONG ";
            switch (action) {
                case 1:
                    front = (last - size + cap) % cap;
                    cout << front;
                    break;
                case 2:
                    size = (last - front + cap) % cap;
                    cout << size;
                    break;
                case 3:
                    cap = *max_element(Array, Array + 4);
                    cout << cap;
                    break;
                case 4:
                    last = (front + size) % cap;
                    cout << last;
                    break;
            }
            cout << "\n";
        } else {
            cout << "OK \n";
        }
    }
    return 0;
}
