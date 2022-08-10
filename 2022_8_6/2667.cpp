#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool visited[25][25];

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int> > pq;
    string tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            if (tmp[j] == '0') {
                visited[i][j] = true;
            }
            else {
                visited[i][j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int cnt = 0;
                queue<int> xq;
                queue<int> yq;
                xq.push(i);
                yq.push(j);
                visited[i][j] = true;
                cnt++;
                while (!xq.empty()) {
                    int x = xq.front();
                    int y = yq.front();
                    xq.pop();
                    yq.pop();
                    if (x - 1 >= 0 && !visited[x - 1][y]) {
                        xq.push(x - 1);
                        yq.push(y);
                        cnt++;
                        visited[x - 1][y] = true;
                    }
                    if (x + 1 < n && !visited[x + 1][y]) {
                        xq.push(x + 1);
                        yq.push(y);
                        cnt++;
                        visited[x + 1][y] = true;
                    }
                    if (y - 1 >= 0 && !visited[x][y - 1]) {
                        xq.push(x);
                        yq.push(y - 1);
                        cnt++;
                        visited[x][y - 1] = true;
                    }
                    if (y + 1 < n && !visited[x][y + 1]) {
                        xq.push(x);
                        yq.push(y + 1);
                        cnt++;
                        visited[x][y + 1] = true;
                    }
                }
                pq.push(cnt);
            }
        }
    }
    cout << pq.size() << endl;
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}