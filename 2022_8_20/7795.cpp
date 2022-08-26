#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testnum;
    int n, m;
    int tmp;
    cin >> testnum;
    for (int i = 0; i < testnum; i++) {
        int result = 0;
        cin >> n >> m;
        vector<int> list1;
        vector<int> list2;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            list1.push_back(tmp);
        }
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            list2.push_back(tmp);
        }
        sort(list2.begin(), list2.end());
        for (int j = 0; j < n; j++) {
            vector<int>::iterator low = lower_bound(list2.begin(), list2.end(), list1[j]);
            result += low - list2.begin();
        }
        cout << result << endl;
    }
    return 0;
}