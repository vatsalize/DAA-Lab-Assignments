#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }

    void maxMeetings(int start[], int end[], int n) {

        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), cmp);       // Sort by finish time

        vector<pair<int,int>> selected;

        int count = 1;
        selected.push_back(v[0]);

        int ansEnd = v[0].second;

        for(int i = 1; i < n; i++) {
            if(v[i].first >= ansEnd) {
                count++;
                ansEnd = v[i].second;
                selected.push_back(v[i]);
            }
        }

        cout << "Maximum number of activities = " << count << endl;
        cout << "Selected activities: ";

        for(auto x : selected) {
            cout << "(" << x.first << ", " << x.second << ") ";
        }
    }
};

int main() {

    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};

    int n = 6;

    Solution obj;
    obj.maxMeetings(start, end, n);

    return 0;
}
