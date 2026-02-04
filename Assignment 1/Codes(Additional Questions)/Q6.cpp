#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

bool cmpX(Point a, Point b) {
    return a.x < b.x;
}

bool cmpY(Point a, Point b) {
    return a.y < b.y;
}

double brute(Point P[], int n) {
    double mn = 1e18;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            mn = min(mn, dist(P[i], P[j]));
    return mn;
}

double stripClosest(Point strip[], int size, double d) {
    double mn = d;

    for (int i = 0; i < size; i++)
        for (int j = i + 1;
            j < size && (strip[j].y - strip[i].y) < mn;
            j++)
            mn = min(mn, dist(strip[i], strip[j]));

    return mn;
}

double closestUtil(Point P[], int n) {
    if (n <= 3)
        return brute(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    double dl = closestUtil(P, mid);
    double dr = closestUtil(P + mid, n - mid);

    double d = min(dl, dr);

    Point strip[n];
    int j = 0;

    for (int i = 0; i < n; i++)
        if (fabs(P[i].x - midPoint.x) < d)
            strip[j++] = P[i];

    sort(strip, strip + j, cmpY);

    return min(d, stripClosest(strip, j, d));
}

double closest(Point P[], int n) {
    sort(P, P + n, cmpX);
    return closestUtil(P, n);
}

int main() {
    Point P[] = {
        {9,3}, {2,6}, {15,3}, {5,1},
        {1,2}, {12,4}, {7,2}, {4,7},
        {16,5}, {3,3}, {10,5}, {6,4},
        {14,6}, {8,6}, {11,1}, {13,2}
    };

    int n = sizeof(P) / sizeof(P[0]);

    double ans = closest(P, n);

    cout << ans;

    return 0;
}
