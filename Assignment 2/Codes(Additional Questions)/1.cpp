#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int arr;
    int dep;
    int pref;
};

int main() {

    int K = 3, N = 6;

    vector<Customer> customers;

    customers.push_back({1,4,1});
    customers.push_back({2,5,1});
    customers.push_back({3,6,2});
    customers.push_back({5,7,1});
    customers.push_back({4,8,2});
    customers.push_back({6,9,3});

    vector<vector<pair<int,int>>> groups(K + 1);

    for(int i = 0; i < N; i++) {
        groups[customers[i].pref].push_back(
            {customers[i].arr, customers[i].dep}
        );
    }

    int total = 0;

    for(int i = 1; i <= K; i++) {

        vector<pair<int,int>> &v = groups[i];

        if(v.size() == 0)
            continue;

        sort(v.begin(), v.end(),
            [](pair<int,int> a, pair<int,int> b) {
                return a.second < b.second;
            });

        int count = 1;
        int lastEnd = v[0].second;

        for(int j = 1; j < v.size(); j++) {
            if(v[j].first >= lastEnd) {
                count++;
                lastEnd = v[j].second;
            }
        }

        total += count;
    }

    cout << "Maximum number of customers that can dine = "
        << total << endl;

    return 0;
}
