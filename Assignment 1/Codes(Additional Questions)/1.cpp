#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(int arr[], int n){
    for(int i=0; i<n-3; i+=2){
        for(int j=0; j<n-i-1; j+=2){
            if(arr[j]>arr[j+2]){
                swap(arr[j], arr[j+2]);
                swap(arr[j+1], arr[j+3]);
            }
        }
    }
}

int overlap(int arr[], int n){
    sort(arr, n);
    int count = 0, mincost = n;
    for(int i=0; i<n; i+=2){
        int l1 = arr[i], r1 = arr[i+1];
        count = 0;

        for(int j=0; j<n; j+=2){
            if(i==j) continue;
            int l2 = arr[j], r2 = arr[j+1];
            if(max(l1,l2) <= min(r1, r2)) {
                count++;
            }
        }
        mincost = min(count, mincost);
    }
    return mincost;
}
int main() {
	int n;
    cin>>n;
    int arr[2*n];
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
    }

    int overlaps = overlap(arr, 2*n);
    cout<<"overlaps="<<overlaps;

    return 0;
}