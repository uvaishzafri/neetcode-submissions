class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupedAnagrams;
        map<string, vector<string>> anagrams;
        
        for(auto it: strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            anagrams[temp].push_back(it);
        }
        for(auto it:anagrams){
            groupedAnagrams.push_back(it.second);
        }
        return groupedAnagrams;
    }
};
