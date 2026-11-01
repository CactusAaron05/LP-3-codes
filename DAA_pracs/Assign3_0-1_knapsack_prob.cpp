//use dp or branch and bound
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Memoization (Top-Down DP)
int knapsackMemo(int i, int capacity, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (i == 0 || capacity == 0)
        return 0;

    if (dp[i][capacity] != -1)
        return dp[i][capacity];

    // Exclude current item
    int exclude = knapsackMemo(i - 1, capacity, wt, val, dp);

    int include = 0;
    // Include current item if it fits
    if (wt[i - 1] <= capacity) {
        include = val[i - 1] + knapsackMemo(i - 1, capacity - wt[i - 1], wt, val, dp);
    }

    dp[i][capacity] = max(include, exclude);
    return dp[i][capacity];
}

// 2. Tabulation (Bottom-Up DP)
int knapsackTabulation(int n, int capacity, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];

            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of items.\n";
        return 0;
    }

    vector<int> wt(n), val(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
        if (wt[i] <= 0) {
            cout << "Weights must be positive.\n";
            return 0;
        }
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        if (val[i] < 0) {
            cout << "Values cannot be negative.\n";
            return 0;
        }
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Capacity cannot be negative.\n";
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    cout << "Maximum value (Memoization): "
         << knapsackMemo(n, capacity, wt, val, dp) << endl;

    cout << "Maximum value (Tabulation): "
         << knapsackTabulation(n, capacity, wt, val) << endl;

    return 0;
}