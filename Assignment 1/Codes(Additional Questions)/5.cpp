#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n], arrSort[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arrSort[i] = arr[i];
    }

    quickSort(arrSort, 0, n - 1);

    int specialty = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0 && arrSort[i] == arrSort[i - 1])
            continue;

        int x = arrSort[i];

        int left = 0, count = 0;
        bool special = false;

        for(int right = 0; right < n; right++) {
            if(arr[right] > x)
                count++;

            while(count > k) {
                if(arr[left] > x)
                    count--;
                left++;
            }

            if(count == k) {
                special = true;
                break;
            }
        }

        if(special)
            specialty += x;
    }

    cout << "speciality="<< specialty;
    return 0;
}
