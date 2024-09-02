#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int length = 1; length <= n; ++length) {
        for (int left = 1; left <= n - length + 1; ++left) {
            int right = left + length - 1;
     
            for (int k = left; k <= right; ++k) {
          
                int coins = nums[left - 1] * nums[k] * nums[right + 1];
           
                coins += dp[left][k - 1] + dp[k + 1][right];
            
                dp[left][right] = max(dp[left][right], coins);
            }
        }
    }

    return dp[1][n];
}

int main() {
  
    vector<int> nums1 = {3, 1, 5, 8};
    cout << "Example 1: " << maxCoins(nums1) << endl;  // Output: 167
    
    vector<int> nums2 = {1, 5};
    cout << "Example 2: " << maxCoins(nums2) << endl;  // Output: 10
    
    return 0;
}
