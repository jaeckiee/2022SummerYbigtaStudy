#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int visited_num;
    priority_queue<int> bag;
    cin >> visited_num;
    for (int i = 0; i < visited_num; i++) {
        int charged_num;
        cin >> charged_num;
        if (charged_num == 0) {
            if (bag.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << bag.top() << endl;
                bag.pop();
            }
            continue;
        }
        for (int j = 0; j < charged_num; j++) {
            int present_val;
            cin >> present_val;
            bag.push(present_val);
        }
    }
    return 0;
}