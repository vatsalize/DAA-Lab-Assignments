//binary search(recursive)

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
    // Base case
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearch(arr, mid + 1, high, key);
    else
        return binarySearch(arr, low, mid - 1, key);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        cout << "key found at index " << result;
    else
        cout << "key not found";

    return 0;
}
