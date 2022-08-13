#include <iostream>
#include <vector>

using namespace std;

bool visited[100000] = { false, };
vector<int> jump_num_list;
int resultnum = 0;
int n;

void dfs(int cur) {
    visited[cur] = true;
    resultnum++;
    int jump_num;
    jump_num = jump_num_list[cur];
    if (cur + jump_num < n && !visited[cur + jump_num]) {
        dfs(cur + jump_num);
    }
    if (cur - jump_num >= 0 && !visited[cur - jump_num]) {
        dfs(cur - jump_num);
    }
}

int main() {
    int jump_num;
    int start;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> jump_num;
        jump_num_list.push_back(jump_num);
    }
    cin >> start;
    start = start - 1;
    dfs(start);

    cout << resultnum;

    return 0;
}