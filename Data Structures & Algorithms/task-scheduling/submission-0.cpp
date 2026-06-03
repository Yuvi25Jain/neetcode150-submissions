class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char t : tasks){
            freq[t]++;
        }
        priority_queue<int>maxHeap;
        for(auto &p : freq) maxHeap.push(p.second);
        int ans = 0 ;
        while(!maxHeap.empty()){
            vector<int>temp;
            int cycle = n+1;
            for(int i = 0 ; i<cycle && !maxHeap.empty();i++){
                temp.push_back(maxHeap.top());
                maxHeap.pop();
            }
            for(int count : temp){
                if(--count>0) maxHeap.push(count);
            }
            ans += maxHeap.empty()? temp.size() : cycle;
        }
        return ans;
    }
};
