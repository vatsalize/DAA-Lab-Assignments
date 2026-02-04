#include <bits/stdc++.h>
using namespace std;

struct Job {
    string id;
    int dead;
    int profit;
};

class Solution {
public:

    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }

    void jobScheduling(Job arr[], int n) {

        sort(arr, arr + n, cmp);

        int maxiDeadline = INT_MIN;                     // Find maximum deadline
        for(int i = 0; i < n; i++) {
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }

        vector<string> schedule(maxiDeadline + 1, "");            // Slot array: empty slot = ""

        int count = 0;
        int maxProfit = 0;

        for(int i = 0; i < n; i++) {

            string currJobID = arr[i].id;
            int currProfit = arr[i].profit;
            int currDead = arr[i].dead;

            for(int k = currDead; k > 0; k--) {

                if(schedule[k] == "") {
                    schedule[k] = currJobID;

                    count++;
                    maxProfit += currProfit;
                    break;
                }
            }
        }

        cout << "Total number of jobs completed = " << count << endl;
        cout << "Selected Jobs: [ ";
        for(int i = 1; i <= maxiDeadline; i++) {
            if(schedule[i] != "")
                cout << schedule[i] << " ";
        }
        cout << "]"<< endl;

        cout << "Maximum Profit = " << maxProfit << endl;
    }
};

int main() {

    int N = 5;

    Job jobs[] = {
        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };

    Solution obj;
    obj.jobScheduling(jobs, N);

    return 0;
}
