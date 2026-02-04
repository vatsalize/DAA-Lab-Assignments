#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:

    static bool cmp(pair<double, Item> a,pair<double, Item> b) {
        return a.first > b.first;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {

        vector<pair<double, Item>> v;

        for(int i = 0; i < n; i++) {
            double perUnitValue =(1.0 * arr[i].value) / arr[i].weight;           // Store (value/weight, item)
            v.push_back({perUnitValue, arr[i]});
        }

        sort(v.begin(), v.end(), cmp);

        double totalValue = 0.0;

        for(int i = 0; i < n; i++)
        {
            if(v[i].second.weight <= W) {
                totalValue += v[i].second.value;
                W -= v[i].second.weight;
            }
            else {
                totalValue += W * v[i].first;
                break;  
            }
        }
        return totalValue;
    }
};

int main() 
{
    int N = 3;
    int W = 50;

    Item arr[] = {{100, 20},{60, 10},{120, 40}};

    Solution obj;

    double ans = obj.fractionalKnapsack(W, arr, N);

    cout << "Maximum value = " << ans << endl;

    return 0;
}
