#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int m;
    int tmp;
    vector<int> own_list;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        own_list.push_back(tmp);
    }
    sort(own_list.begin(), own_list.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (binary_search(own_list.begin(), own_list.end(), tmp)) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }
    return 0;
}