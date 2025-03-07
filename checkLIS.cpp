#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/// this code finds the longest Increasing subarray

int length_of_LIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int n = nums.size();
    vector<int> dp(n, 1);  // Initialize DP array with 1, as the minimum LIS length is 1 for any element.

    // Fill DP array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in the DP array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = length_of_LIS(nums);
    cout << "Length of the Longest Increasing Subsequence: " << result << endl;

    return 0;
}
