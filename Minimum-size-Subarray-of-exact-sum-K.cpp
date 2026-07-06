#include <bits/stdc++.h>
using namespace std;

// Your original function with -1 for no subarray
int minSubArrayLen(int target, vector<int>& nums) {

    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int minLen = INT_MAX;

    while(j < n) {

        sum += nums[j];

        while (i <= j && sum > target) {  
            sum -= nums[i];
            i += 1;
        }

        while (i <= j && sum == target) {  
            minLen = min(minLen, j - i + 1);
            sum -= nums[i];
            i += 1;
        }

        j += 1;
    }
    
    return minLen == INT_MAX ? -1 : minLen;
}

int main() {
    // 10 test cases
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5}, 9},       // Normal case, subarray [4,5]
        {{1, 1, 1, 1, 1}, 3},       // Multiple same numbers
        {{5, 1, 2, 3, 1}, 8},       // Subarray in middle
        {{1, 2, 3}, 7},             // No subarray sum equals target
        {{0, 0, 0, 0}, 0},          // All zeros, target 0
        {{0, 0, 0, 0}, 1},          // All zeros, target > 0
        {{10}, 10},                  // Single element matches
        {{10}, 5},                   // Single element, no match
        {{1, 2, 3, 4, 5}, 15},      // Whole array sums to target
        {{1, 2, 2, 2, 1}, 4}        // Multiple small subarrays
    };

    for (int t = 0; t < testCases.size(); ++t) {

        vector<int> nums = testCases[t].first;
        int target = testCases[t].second;
        int result = minSubArrayLen(target, nums);

        cout << "Test Case " << t+1 << ": ";

        if (result == -1) {
            cout << "No subarray with sum " << target << " exists." << endl;
        }
        else {
            cout << "Minimal length = " << result << endl;
        }

    }

    return 0;
}
