class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &tok : tokens){
            if(tok == "+" || tok == "-"|| tok == "*" || tok == "/"){
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();


                int res = 0 ;
                if(tok == "+") res = left+right;
                else if(tok == "-") res = left-right;
                else if(tok == "*") res = left*right;
                else if(tok == "/") res = left/right;
                st.push(res);
            
            } else{
                st.push(stoi(tok));
            }
        }
        return st.top();
    }
};
