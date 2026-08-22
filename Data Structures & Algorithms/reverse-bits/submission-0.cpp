class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<char> s(32,'0');
        int i=0;
        while(n){
            if(n&1) s[31-i]='1';
            i+=1;
            n/=2;
            
        }
        reverse(s.begin(),s.end());
        uint32_t result=0, curr=1;
        for(int i=31;i>-1;i--){
            if(s[i]=='1') result+=curr;
            curr*=2;
        }
        return result;
    }
};
