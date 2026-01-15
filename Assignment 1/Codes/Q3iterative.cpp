#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
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

void iterativeQuickSort(int arr[], int low, int high)
{
    stack<int> st;
    st.push(low);
    st.push(high);

    while (!st.empty())
    {
        high = st.top();
        st.pop();
        low = st.top();
        st.pop();

        int pi = partition(arr, low, high);

        if (pi - 1 > low)
        {
            st.push(low);
            st.push(pi - 1);
        }

        if (pi + 1 < high)
        {
            st.push(pi + 1);
            st.push(high);
        }
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    iterativeQuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
