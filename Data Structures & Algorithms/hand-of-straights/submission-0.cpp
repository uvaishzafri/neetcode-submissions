class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> cnt;

        for(auto it:hand) cnt[it]++;

        for(auto it:cnt){
            while(cnt[it.first]>0)
            for(int i=0;i<groupSize;i++){
                if(cnt[it.first+i]>0){
                    cnt[it.first+i]-=1;
                }
                else{
                    //cout<<it.first<<" "<<it.second<<endl;
                    return false;
                }
            }
        }
        return true;

    }
};
