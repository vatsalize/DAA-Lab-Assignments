#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int N;
    cout << "enter the size of the array" << endl;
    cin >> N;
    cout << "enter the values" << endl;
    int A[200000];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    quickSort(A, 0, N - 1);

    int l = 0;
    int ans = 0;

    for (int r = 0; r < N; r++) {
        while (A[r] - A[l] > 10)
            l++;

        int len = r - l + 1;
        if (len > ans)
            ans = len;
    }

    cout << "answer = "<< ans;
    return 0;
}
