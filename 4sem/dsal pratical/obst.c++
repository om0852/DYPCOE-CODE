// C++ program for recursive implementation of
// optimal binary search tree
#include<iostream>
#include<vector>
using namespace std;

// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(vector<int> &freq, int i, int j) {

    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// A recursive function to calculate
// cost of optimal binary search tree
int optCost(vector<int> &freq, int i, int j) {

    // no elements in this subarray
    if (j < i)
        return 0;

    // one element in this subarray
    if (j == i)
        return freq[i];

    // Get sum of freq[i], freq[i+1], ... freq[j]
    int fsum = sum(freq, i, j);

    // Initialize minimum value
    int min = INT_MAX;

    // One by one consider all elements
    // as root and recursively find cost
    // of the BST, compare the cost with
    // min and update min if needed
    for (int r = i; r <= j; ++r) {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }

    // Return minimum value
    return min + fsum;
}

int optimalSearchTree(vector<int> &keys, vector<int> &freq) {

    int n = keys.size();
    return optCost(freq, 0, n - 1);
}

int main() {

    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    cout << optimalSearchTree(keys, freq);
    return 0;
}