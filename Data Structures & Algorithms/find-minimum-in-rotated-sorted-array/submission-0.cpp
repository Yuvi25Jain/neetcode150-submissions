class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_val = nums[0];
        return min_val;
        
    }
};
