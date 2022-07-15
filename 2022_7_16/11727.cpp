#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int tmpres;
    vector<int> resultlist;

    cin >> n;

    //for 0
    resultlist.push_back(0);

    //for 1
    resultlist.push_back(1);

    //for 2
    resultlist.push_back(3);

    //for next num
    for (int listidx = 3; listidx <= n; listidx++) {
        tmpres = (resultlist[listidx - 1] + resultlist[listidx - 2] * 2) % 10007;
        resultlist.push_back(tmpres);
    }

    cout << resultlist[n];

    return 0;
}