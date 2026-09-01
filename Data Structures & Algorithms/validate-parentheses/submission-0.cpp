class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it=='['||it=='{'||it=='(') st.push(it);
            else if(it==']'||it=='}'||it==')'){
                if(st.size()==0) return false;
                char top = st.top(); st.pop();
                if(it==']'&&top!='[') return false;
                if(it==')'&&top!='(') return false;
                if(it=='}'&&top!='{') return false;
            }
        }
        return st.size()==0;
    }
};
