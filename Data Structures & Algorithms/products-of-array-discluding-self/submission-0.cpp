class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prx(n,1) , srx(n,1), res(n);

        //prefix
        for(int i = 1 ; i<n ; i++){
            prx[i] = prx[i-1]*nums[i-1];
        }

        //suffix
        for(int i = n-2 ; i>=0 ; i--){
            srx[i] = srx[i+1]*nums[i+1];
        }
        //final result
        for(int i = 0 ; i<n ; i++){
            res[i] = prx[i]*srx[i];
        }
        return res;
    }
};
