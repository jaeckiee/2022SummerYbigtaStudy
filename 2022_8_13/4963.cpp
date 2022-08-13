#include <iostream>

using namespace std;

int w, h;
bool map[51][51];

void dfs(int x, int y) {
    if (map[x][y] == false)
        return;
    if (x < 0 || x >= h)
        return;
    if (y < 0 || y >= w)
        return;
    map[x][y] = false;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x - 1, y - 1);
    dfs(x - 1, y + 1);
    dfs(x + 1, y - 1);
    dfs(x + 1, y + 1);
}

int main() {
    cin >> w >> h;
    while (w != 0 || h != 0) {
        int result = 0;
        if (w == 0 || h == 0) {
            cout << result << endl;
            continue;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool tmp;
                cin >> tmp;
                map[i][j] = tmp;
            }
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == true) {
                    result++;
                    dfs(i, j);
                }
            }
        }
        cout << result << endl;
        cin >> w >> h;
    }
    return 0;
}