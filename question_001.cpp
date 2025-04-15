/*
https://leetcode.com/problems/two-sum/
*/

// The brute force solution. O(n) = n squared. We can do better.
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int> {i, j};
                }
            }
        }

        // No match.
        return vector<int>{};
    }
}; 


// Use a lookup of value back to index. Much faster.
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Build the lookup table.
        std::map<int, int> lookup;
        for (int idx = 0; idx < nums.size(); idx++) {
            lookup[nums[idx]] = idx;
        }

        // Search the table for matches.
        for (int idx = 0; idx < nums.size(); idx++) {
            int diff = target - nums[idx];
            auto iter = lookup.find(diff);
            if (iter != lookup.end() && iter->second != idx) {
                return vector<int> {idx, iter->second};
            }
        }

        // No match.
        return vector<int> {};
    }
};
