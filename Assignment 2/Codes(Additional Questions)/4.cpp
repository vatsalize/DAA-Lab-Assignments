#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas,
                       vector<int>& cost) {

    int n = gas.size();

    int totalGas = 0;
    int totalCost = 0;

    for(int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
    }

    if(totalGas < totalCost)
        return -1;

    int curr = 0;
    int start = 0;

    for(int i = 0; i < n; i++) {

        curr += gas[i] - cost[i];

        if(curr < 0) {
            start = i + 1;
            curr = 0;
        }
    }

    return start;
}

int main() {

    vector<int> gas  = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << canCompleteCircuit(gas, cost);

    return 0;
}
