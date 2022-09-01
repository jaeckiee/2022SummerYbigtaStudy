#include <iostream>
#include <queue>
#include <iomanip>
#include <stdlib.h> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    priority_queue<int, vector<int>, greater<int> > abs_pq;
    priority_queue<int> minus_pq;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int input;
        cin >> input;
        if (input == 0) {
            if (abs_pq.empty()) {
                cout << 0 << endl;
            }
            else{
                int top_minus_pq;
                if (minus_pq.empty()) {
                    top_minus_pq = 0;
                }
                else {
                    top_minus_pq = minus_pq.top();
                }
                int top_abs_pq = abs_pq.top();
                if (top_abs_pq == abs(top_minus_pq)) {
                    cout << top_minus_pq << endl;
                    minus_pq.pop();
                    abs_pq.pop();
                }
                else {
                    cout << top_abs_pq << endl;
                    abs_pq.pop();
                }
            }
            continue;
        }
        if (input < 0) {
            minus_pq.push(input);
        }
        abs_pq.push(abs(input));
    }
    return 0;
}