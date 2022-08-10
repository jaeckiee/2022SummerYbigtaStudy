#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int main() {
    bool tmp;
    int n, m;
    int cnt = 0;
    bool** visited;
    queue<int> xq;
    queue<int> yq;
    int curnum;
    int nextnum;
    string str;
    cin >> n >> m;
    visited = new bool* [n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[m];
    }
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == '1') {
                visited[i][j] = false;
            }
            else {
                visited[i][j] = true;
            }
        }
    }

    xq.push(0);
    yq.push(0);
    visited[0][0] = true;
    curnum = 1;
    while (1) {
        cnt++;
        nextnum = 0;
        for (int i = 0; i < curnum; i++) {
            int x = xq.front();
            int y = yq.front();
            xq.pop();
            yq.pop();
            if (x == n - 1 && y == m - 1) {
                cout << cnt;
                return 0;
            }
            if (x - 1 >= 0 && !visited[x - 1][y]) {
                xq.push(x - 1);
                yq.push(y);
                nextnum++;
                visited[x - 1][y] = true;
            }
            if (x + 1 < n && !visited[x + 1][y]) {
                xq.push(x + 1);
                yq.push(y);
                nextnum++;
                visited[x + 1][y] = true;
            }
            if (y - 1 >= 0 && !visited[x][y - 1]) {
                xq.push(x);
                yq.push(y - 1);
                nextnum++;
                visited[x][y - 1] = true;
            }
            if (y + 1 < m && !visited[x][y + 1]) {
                xq.push(x);
                yq.push(y + 1);
                nextnum++;
                visited[x][y + 1] = true;
            }
        }
        curnum = nextnum;
    }
    cout << cnt;
    return 0;
}