//priority queue method

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int toMinutes(string t)
        {
        int h = stoi(t.substr(0,2));
        int m = stoi(t.substr(3,2));
        return h * 60 + m;
        }

    void minPlatformsPQ(vector<string> ATs,vector<string> DTs,int n)
    {
        vector<pair<int,int>> trains;

        for(int i = 0; i < n; i++) 
        {
            trains.push_back({toMinutes(ATs[i]),toMinutes(DTs[i]) });
        }

        sort(trains.begin(), trains.end());                        // Sort by arrival time

        priority_queue<int, vector<int>, greater<int>> pq;        // Min-heap of departure times

        int maxPlatforms = 0;

        for(int i = 0; i < n; i++)
        {

            int arr = trains[i].first;
            int dep = trains[i].second;

            if(!pq.empty() && pq.top() < arr) {
                pq.pop();
            }

            pq.push(dep);

            maxPlatforms = max(maxPlatforms, (int)pq.size());
        }

        cout << "Minimum number of platforms required = "<< maxPlatforms << endl;
    }
};

int main() {

    vector<string> AT = {"09:00", "09:10", "09:20","11:00", "11:20"};

    vector<string> DT = {"09:40", "12:00", "09:50","11:30", "11:40"};

    int n = AT.size();

    Solution obj;
    obj.minPlatformsPQ(AT, DT, n);

    return 0;
}
