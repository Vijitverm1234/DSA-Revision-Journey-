#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void upperBound(const vector<int> &arr)
{
    int x;
    cout << "\nEnter the element to find its upper bound: ";
    cin >> x;

    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (low < arr.size())
        cout << "Upper Bound: " << arr[low] << "\n";
    else
        cout << "Upper Bound does not exist.\n";
}

void lowerBound(const vector<int> &arr)
{
    int x;
    cout << "\nEnter the element to find its lower bound: ";
    cin >> x;

    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (low < arr.size())
        cout << "Lower Bound: " << arr[low] << "\n";
    else
        cout << "Lower Bound does not exist.\n";
}

void search(vector<int> arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int x;
    cout << "\nEnter the element to be found :";
    cin >> x;
    int res = -1;
    bool flag = false;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            res = mid;
            flag = true;
            break;
        }
        if (arr[mid] <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (flag)
    {
        cout << "\nElement Found at " << res;
    }
    else
    {
        cout << "\nElement Not Found";
    }
}

int main()
{
    vector<int> arr = {12, 34, 13, 56, 66, 90, 100};
    sort(arr.begin(), arr.end());
    int n = arr.size();
    cout << "\nEntered array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    search(arr);
    upperBound(arr);
    lowerBound(arr);
}