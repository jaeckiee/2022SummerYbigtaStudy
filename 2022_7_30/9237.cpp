#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue< int, vector<int>, less<int> > pq1;
    priority_queue< int, vector<int>, less<int> > pq2;
    int n;
    int tmp;
    int result;
    int topnum;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq1.push(tmp);
    }
    for (int i = 0; i < n; i++) {
        pq2.push(pq1.top() - (n - i - 1));
        pq1.pop();
    }
    result = n;
    topnum = pq2.top();
    if (topnum > 0) {
        result = result + topnum;
    }
    cout << result;
    return 0;
}