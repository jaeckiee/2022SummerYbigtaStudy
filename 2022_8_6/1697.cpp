#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { false, };

int main() {
    int n, k;
    int curnum;
    int nextnum;
    int result = -1;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    curnum = 1;
    while (!visited[k]) {
        nextnum = 0;
        for (int i = 0; i < curnum; i++) {
            int frontnum = q.front();
            q.pop();
            visited[frontnum] = true;
            if (frontnum - 1 >= 0 && !visited[frontnum - 1]) {
                q.push(frontnum - 1);
                nextnum++;
            }
            if (frontnum + 1 < 100001 && !visited[frontnum + 1]) {
                q.push(frontnum + 1);
                nextnum++;
            }
            if (frontnum * 2 < 100001 && !visited[frontnum * 2]) {
                q.push(frontnum * 2);
                nextnum++;
            }
        }
        curnum = nextnum;
        result++;
    }
    cout << result;
    return 0;
}