class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> freq_s , freq_t;

        for(char c : s){
            freq_s[c]++;
        }
        for(char c : t){
            freq_t[c]++;
        }
        return freq_s == freq_t;
    }
};
