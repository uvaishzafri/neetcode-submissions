class Solution {
public:
    vector<int> partitionLabels(string s) {
        pair<int,int> p[27];
        for(int i=0;i<27;i++){
            p[i]={INT_MAX,INT_MIN};
        }
        for(int i=0;i<s.length();i++){
            p[s[i]-'a'].first=min(p[s[i]-'a'].first,i);
            p[s[i]-'a'].second=max(p[s[i]-'a'].second,i);
        }
        int currmin=0,currmax=0;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            if(p[s[i]-'a'].second>currmax) currmax=p[s[i]-'a'].second;
            if(currmax==i){
                ans.push_back(currmax-currmin+1);
                currmax=i+1;
                currmin=i+1;
            }
        }
        return ans;
        
    }
};