class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0 ;
        sort(nums.begin() , nums.end());
        int lng = 1 , streak = 1 ;
        for(int i =  1 ; i< nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] == nums[i-1]+1){
                streak++;
            }
            else{
                lng = max(lng,streak);
                streak = 1;
            }
        }
        return max(lng,streak);

        
    }
};
