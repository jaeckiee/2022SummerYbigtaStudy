#include <iostream>
#include <vector>
#include <algorithm> 
#include <set>
using namespace std;

void mergeSort(vector<int>& left, vector<int>& right, vector<int>& bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}

void sort(vector<int>& bar) {
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    vector<int> left;
    vector<int> right;

    for (size_t j = 0; j < mid; j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort(left);
    sort(right);
    mergeSort(left, right, bar);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    int tmp;
    vector<int> num_list;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        num_list.push_back(tmp);
    }
    sort(num_list);
    for (int i = 0; i < q; i++) {
        int result;
        int x, y;
        cin >> x >> y;
        vector<int>::iterator low = lower_bound(num_list.begin(), num_list.end(), x);
        vector<int>::iterator up = upper_bound(num_list.begin(), num_list.end(), y);
        result = up - low;
        printf("%d\n", result);
    }
    return 0;
}