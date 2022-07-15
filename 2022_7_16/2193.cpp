#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long result;
    vector<long long> zeroresultlist;
    vector<long long> oneresultlist;

    cin >> n;

    //for 0
    zeroresultlist.push_back(0);
    oneresultlist.push_back(0);

    //for 1
    zeroresultlist.push_back(0);
    oneresultlist.push_back(1);

    //for 2
    zeroresultlist.push_back(1);
    oneresultlist.push_back(0);

    //for next num
    for (int listidx = 3; listidx <= n; listidx++) {
        zeroresultlist.push_back(zeroresultlist[listidx - 1] + zeroresultlist[listidx - 2]);
        oneresultlist.push_back(oneresultlist[listidx - 1] + oneresultlist[listidx - 2]);
    }

    //print result
    result = zeroresultlist[n] + oneresultlist[n];
    cout << result;

    return 0;
}