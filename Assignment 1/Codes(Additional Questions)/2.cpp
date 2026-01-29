#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int n1 = mid-low+1, n2 = high-mid;
    int arr1[n1], arr2[n2];
    for(int i=0; i<n1; i++){
        arr1[i] = arr[low+i];
    }
    for(int j=0; j<n2; j++){
        arr2[j] = arr[mid+j+1]; 
    }
    int i=0, j=0, k = low;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        } else {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int low, int high){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int maxArr(int arr[], int size){
    int low = 0, high = size-1;
    mergeSort(arr, low, high);

    int count = 0, left = 0; 
    for(int right=0; right<size; right++){
        while(arr[right]-arr[left]>10) left++; 
        count = max(count, right-left+1);
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int elements = maxArr(arr, n);
    cout<<"elements="<<elements;

    return 0; 
}
