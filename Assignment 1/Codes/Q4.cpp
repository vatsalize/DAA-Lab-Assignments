#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int left, int mid, int right)
{
    int sum = 0;
    int leftSum = arr[mid];
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    int rightSum = arr[mid + 1];
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubArraySum(int arr[], int left, int right)
{
    if (left == right)
        return arr[left];
    int mid = (left + right) / 2;
    int leftMax = maxSubArraySum(arr, left, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);
    return max(max(leftMax, rightMax), crossMax);
}
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"the maximum subarray sum is "<< maxSubArraySum(arr, 0, n - 1);
    return 0;
}
