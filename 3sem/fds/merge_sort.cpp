Here is the code without comments:

```cpp
#include <iostream>
using namespace std;

void merge(int a[], int si, int mid, int ei) {
    int arr[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= ei) {
        if (a[idx1] < a[idx2]) {
            arr[x++] = a[idx1++];
        } else {
            arr[x++] = a[idx2++];
        }
    }

    while (idx1 <= mid) {
        arr[x++] = a[idx1++];
    }

    while (idx2 <= ei) {
        arr[x++] = a[idx2++];
    }

    for (int i = 0, j = si; i < (ei - si + 1); i++, j++) {
        a[j] = arr[i];
    }
}

void divide(int a[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    divide(a, si, mid);
    divide(a, mid + 1, ei);
    merge(a, si, mid, ei);
}

int main() {
    int arr[6] = {10, 20, 40, 3, 1, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    divide(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
