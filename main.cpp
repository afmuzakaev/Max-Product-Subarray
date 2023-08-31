#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductSubarray(int arr[], int n) {
    int maxEndingHere = 1;
    int minEndingHere = 1;
    int maxSoFar = 1;
    bool anyPositive = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            maxEndingHere *= arr[i];
            minEndingHere = min(minEndingHere * arr[i], 1);
            anyPositive = true;
        } else if (arr[i] == 0) {
            maxEndingHere = 1;
            minEndingHere = 1;
        } else {
            int temp = maxEndingHere;
            maxEndingHere = max(minEndingHere * arr[i], 1);
            minEndingHere = temp * arr[i];
        }

        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }

    if (!anyPositive && maxSoFar == 1)
        return 0;

    return maxSoFar;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = maxProductSubarray(arr, n);
    cout << "Maximum product subarray: " << result << endl;

    return 0;
}
