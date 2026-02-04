#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1) {
        arr[k++] = L[i++];
    }
    while(j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int low, int high) {
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        mergeSort(arr, 0, n - 1);

        int l = 0, r = n - 1;
        int remove = n / 2;

        while(remove--) {
            int mid = (l + r) / 2;
            for(int i = mid; i < r; i++)
                arr[i] = arr[i + 1];
            r--;
        }

        int sum = 0;
        for(int i = l; i <= r; i++)
            sum += arr[i];

        cout << "sum="<< sum << endl;
    }

    return 0;
}
