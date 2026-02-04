#include <bits/stdc++.h>
using namespace std;

struct Course {
    int s, e;
};

int main() {

    int N = 6;

    vector<Course> courses = {
        {1,3},
        {2,5},
        {4,6},
        {6,7},
        {5,9},
        {8,10}
    };

    int Q = 3;

    vector<int> planStart = {1, 2, 4};
    vector<int> planEnd   = {6, 7, 10};

    for(int qi = 0; qi < Q; qi++) {

        int L = planStart[qi];
        int R = planEnd[qi];

        vector<Course> valid;

        for(int i = 0; i < N; i++) {
            if(courses[i].s >= L && courses[i].e <= R) {
                valid.push_back(courses[i]);
            }
        }

        sort(valid.begin(), valid.end(),
            [](Course a, Course b) {
                return a.e < b.e;
            });

        int count = 0;
        int lastEnd = -1;

        for(int i = 0; i < valid.size(); i++) {
            if(count == 0 || valid[i].s >= lastEnd) {
                count++;
                lastEnd = valid[i].e;
            }
        }

        cout << "Plan " << qi+1
            << ": maximum courses = "
            << count << endl;
    }

    return 0;
}
