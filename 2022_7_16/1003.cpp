#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numtestcase;
    int reqnum;

    cin >> numtestcase;
    for (int idx = 0; idx < numtestcase; idx++) {
        vector<long long> numzerolist;
        vector<long long> numonelist;

        cin >> reqnum;

        //for 0
        numzerolist.push_back(1);
        numonelist.push_back(0);

        //for 1
        numzerolist.push_back(0);
        numonelist.push_back(1);

        //for next nums
        for (int listidx = 2; listidx <= reqnum; listidx++) {
            numzerolist.push_back(numzerolist[listidx - 1] + numzerolist[listidx - 2]);
            numonelist.push_back(numonelist[listidx - 1] + numonelist[listidx - 2]);
        }

        //print result
        cout << numzerolist[reqnum] << ' ' << numonelist[reqnum] << endl;
    }

    return 0;
}