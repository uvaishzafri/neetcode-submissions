class Solution {
   public:
    bool isPermutation(vector<int> count1, vector<int> count2) {
        for (int i = 0; i < 26; i++)
            if (count2[i] != count1[i]) {
                return false;
            }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for(auto it:s1) count1[it-'a']+=1;
        int n = s1.size();
        for(int i=0;i<n;i++){
            count2[s2[i]-'a']+=1;
        }
        if(isPermutation(count1, count2)) return true;

        for(int i=n;i<s2.size();i++){
            count2[s2[i]-'a']+=1;
            count2[s2[i-n]-'a']-=1;
            if(isPermutation(count1, count2)) return true;
        }


        return false;
    }
};
