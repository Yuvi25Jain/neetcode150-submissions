class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char>win;
        int l = 0 , max_len = 0 ;
        for(int r = 0 ; r<n ; r++){
            while(win.count(s[r])){
                win.erase(s[l]);
                l++;
            }
            win.insert(s[r]);
            max_len = max(max_len,r-l+1);
        }
        return max_len;

        
    }
};
