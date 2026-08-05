class Solution {
public:

    string encode(vector<string>& strs) {
            string result="";
            for(auto it: strs){
                result+=";";
                result+=it;
            }
            return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int n = s.size();
        for(int i =0;i<n;){
            string temp ="";
            if(s[i]==';'){
                i+=1;
                cout<<s[i]<<endl;
            while(s[i]!=';' && i<n){
                
                temp+=s[i];
                i++;}
            }
            result.push_back(temp);

        }
        
        return result;

    }
};
