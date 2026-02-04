#include <bits/stdc++.h>
using namespace std;

int main() {

    int m = 3, n = 3;

    vector<int> x = {2, 1};
    vector<int> y = {3, 1};

    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    int hPieces = 1;
    int vPieces = 1;

    int i = 0, j = 0;
    int cost = 0;

    while(i < x.size() && j < y.size()) {

        if(x[i] >= y[j]) {
            cost += x[i] * vPieces;
            hPieces++;
            i++;
        }
        else {
            cost += y[j] * hPieces;
            vPieces++;
            j++;
        }
    }

    while(i < x.size()) {
        cost += x[i] * vPieces;
        i++;
    }

    while(j < y.size()) {
        cost += y[j] * hPieces;
        j++;
    }

    cout << "Minimum total cost = " << cost << endl;

    return 0;
}
