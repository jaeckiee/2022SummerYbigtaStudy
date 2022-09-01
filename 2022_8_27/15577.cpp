#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    priority_queue <double, vector<double>, greater<double> > grades;
    cin >> num;
    for (int i = 0; i < num; i++) {
        double tmp;
        cin >> tmp;
        grades.push(tmp);
    }
    while (grades.size() > 1) {
        double num1 = grades.top();
        grades.pop();
        double num2 = grades.top();
        grades.pop();
        grades.push((num1+num2) / 2);
    }
    cout << fixed;
    cout << setprecision(6);
    cout << grades.top();
    return 0;
}