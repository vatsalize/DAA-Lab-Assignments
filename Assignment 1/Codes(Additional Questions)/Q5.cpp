#include <iostream>
using namespace std;

long long canFit(long long x, long long w, long long h, long long n) {
    long long maxw = x / w;
    long long maxh = x / h;
    return maxw * maxh >= n;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long w, h, n;
        cin >> w >> h >> n;

        long long low = 1;
        long long high = max(w, h) * n;
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canFit(mid, w, h, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << "ans="<< ans << endl;
    }

    return 0;
}