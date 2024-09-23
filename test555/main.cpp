#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& l) {
    for (auto x : l) {
        cout << x << " ";
    }
    cout << endl;
}

void check(list<int>& l, list<int>::iterator& it) {
    int left = 0;
    int right = 0;
    auto temp = it;

    while (temp != l.begin() && *(--temp) == *it)
        left += 1;

    auto temp1 = it;

    while (next(temp1) != l.end() && *(++temp1) == *it)
        right += 1;

    // Erase elements if there are enough duplicates
    if (left + right >= 2) {
        advance(it, -left);
        for (int i = 0; i <= left + right; i++) {
            it = l.erase(it);
        }
        if(*it == *(--it))check(l, ++it);
    }
}

int main() {
    int N, K, V, in;
    cin >> N >> K >> V;
    list<int> l;
    list<int>::iterator it;

    for (int i = 0; i < N; i++) {
        if (i == K) {
            l.push_back(V);
            it = --l.end();
        }

        cin >> in;
        l.push_back(in);
    }

    //cout << "Original List: ";
    //printList(l);

    check(l, it);

    //cout << "Final List: ";
    printList(l);

    return 0;
}
