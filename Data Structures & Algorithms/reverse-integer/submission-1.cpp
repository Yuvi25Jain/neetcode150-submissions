class Solution {
public:
    int reverse(int x) {
        long long ans = 0; // use long long to check overflow
        while(x != 0){
            int digit = x % 10;   // extract last digit
            ans = ans * 10 + digit; // build reversed number
            x /= 10;              // remove last digit
        }
        if(ans < INT_MIN || ans > INT_MAX) return 0; // overflow check
        return (int)ans;
    }
};
