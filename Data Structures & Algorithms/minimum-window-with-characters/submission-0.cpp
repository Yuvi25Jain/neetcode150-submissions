class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need , have ;
        for(char c : t) need[c]++;

        int req = need.size();
        int formed = 0;
        int l = 0 , r = 0;
        int minLen = INT_MAX , start = 0;

        while(r<s.size()){
            char c  = s[r];
            have[c]++;
            if(need.count(c) && have[c] == need[c]){
                formed++;
            }

            while(l<=r && formed == req){
                if(r-l+1<minLen){
                    minLen = r-l+1;
                    start = l;
                }
                char d = s[l];
                have[d]--;
                if(need.count(d) && have[d]<need[d]){
                    formed--;
                }
                l++;
            }
            r++;
        }

        return minLen == INT_MAX? "": s.substr(start,minLen);
        
    }
};
