class Solution {
public:
    int findmazx(vector<int>&piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0 ; i<n; i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    int total_hr(vector<int>& piles , int hr){
        int total_hr =0;
        int n = piles.size();
        for(int i = 0; i<n ; i++){
            total_hr += ceil((double)piles[i]/(double)hr);
        }
        return total_hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = findmazx(piles);
        while(l<=r){
            int mid = l + (r-l)/2;
            int total_m = total_hr(piles,mid);
            if(total_m <= h){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
