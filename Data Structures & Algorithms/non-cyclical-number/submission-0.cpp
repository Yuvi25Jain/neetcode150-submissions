class Solution {
public:

    int digit_sum(int x){
        int sum = 0 ;
        while(x>0){
            int d = x%10;
            sum += d*d;
            x/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n , fast = digit_sum(n);
        while(fast != 1 && slow != fast){
            slow = digit_sum(slow);
            fast = digit_sum(digit_sum(fast));
        }
        return fast ==1;
        
    }
};
