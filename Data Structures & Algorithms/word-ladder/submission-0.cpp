class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st{wordList.begin(),wordList.end()};
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord) return level;
            for(int i=0;i<word.size();i++){
                char og = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
};

