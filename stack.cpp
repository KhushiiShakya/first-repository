#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int num) {
    // Base case: stack empty or top <= num
    if (s.empty() || s.top() <= num) {
        s.push(num);
        return;
    }

    // Otherwise remove top and recurse
    int top = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(top);
}

void sortStack(stack<int> &s) {
    // Base case
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, top);
    }
}

int main() {
    stack<int> s;
    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        s.push(value);
    }

    sortStack(s);

    cout << "Sorted stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
