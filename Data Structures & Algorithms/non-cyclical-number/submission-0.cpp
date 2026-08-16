class Solution {
public:
    int countDigitsSquareSum(int n){
        int result = 0;
        while(n>0){
            int modulo = n%10;
            result += (modulo*modulo);
            n/=10;
        }
        return result;
    }
    bool isHappy(int n) {
        set<int> seen;
        seen.insert(n);
        while(n!=1){
            int sum = countDigitsSquareSum(n);
            if(seen.contains(sum)) return false;
            seen.insert(sum);
            n= sum;
        }
        return true;

    }
};
