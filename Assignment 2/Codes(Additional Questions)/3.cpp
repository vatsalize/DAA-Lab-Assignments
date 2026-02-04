#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

string smallestString(string s, int k) {

    int n = s.size();

    if(isPowerOfTwo(n))
        k = k / 2;
    else
        k = 2 * k;

    vector<char> st;

    for(int i = 0; i < n; i++) {

        while(!st.empty() && k > 0 && st.back() > s[i]) {
            st.pop_back();
            k--;
        }

        st.push_back(s[i]);
    }

    while(k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    string ans = "";
    for(char c : st)
        ans += c;

    return ans;
}

int main() {

    string S = "fooland";
    int k = 2;

    cout << smallestString(S, k);

    return 0;
}
