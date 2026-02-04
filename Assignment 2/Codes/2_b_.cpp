//normal for loop i j method

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int toMinutes(string t) {
        int h = stoi(t.substr(0,2));
        int m = stoi(t.substr(3,2));
        return h * 60 + m;
    }

    void minPlatformsTwoPointer(vector<string> ATs, vector<string> DTs,int n) {

        vector<int> arrival, departure;

        for(int i = 0; i < n; i++) {
            arrival.push_back(toMinutes(ATs[i]));
            departure.push_back(toMinutes(DTs[i]));
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int i = 0, j = 0;
        int platforms = 0;
        int maxPlatforms = 0;

        while(i < n && j < n) {

            if(arrival[i] <= departure[j]) {
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            }
            else {
                platforms--;
                j++;
            }
        }

        cout << "Minimum number of platforms required = "<< maxPlatforms << endl;
    }
};

int main() {

    vector<string> AT = {"09:00", "09:10", "09:20","11:00", "11:20"};

    vector<string> DT = {"09:40", "12:00", "09:50","11:30", "11:40"};

    int n = AT.size();

    Solution obj;
    obj.minPlatformsTwoPointer(AT, DT, n);

    return 0;
}
