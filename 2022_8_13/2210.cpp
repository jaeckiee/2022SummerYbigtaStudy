#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string strarr[5][5];
unordered_set<string> uset;

void dfs(string curstr, int cnt, int x, int y) {
    if (cnt == 6) {
        uset.insert(curstr);
        return;
    }
    if (x - 1 >= 0) {
        dfs(curstr + strarr[x][y], cnt + 1, x - 1, y);
    }
    if (x + 1 < 5) {
        dfs(curstr + strarr[x][y], cnt + 1, x + 1, y);
    }
    if (y - 1 >= 0) {
        dfs(curstr + strarr[x][y], cnt + 1, x, y - 1);
    }
    if (y + 1 < 5) {
        dfs(curstr + strarr[x][y], cnt + 1, x, y + 1);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> strarr[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs("", 0, i, j);
        }
    }

    cout << uset.size();

    return 0;
}