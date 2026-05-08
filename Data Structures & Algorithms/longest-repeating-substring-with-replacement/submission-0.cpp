class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26,0);
        int n = s.size();
        int l = 0 , max_freq = 0 , ans = 0 ;

        for(int r = 0 ; r<n ; r++){
            cnt[s[r] - 'A']++;
            max_freq = max(max_freq, cnt[s[r]-'A']);

            while((r-l+1) - max_freq >k){
                cnt[s[l] - 'A']--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;

        
    }
};
