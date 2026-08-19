class Solution {
public:
    double myPow(double x, int n) {
        if(n==1) return x;
        else if(n==0) return 1;
        double result = myPow(x,abs(n)/2);
        if(n>0) return result*result*myPow(x,abs(n)%2);
        else return 1/(result*result*myPow(x,abs(n)%2));
    }
};
