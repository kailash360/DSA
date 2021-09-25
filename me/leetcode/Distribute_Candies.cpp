class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int count = 0;
        unordered_set<int> s;
        
        for(int i=0;i<n;i++){
            if(s.find(candyType[i]) == s.end()){
                s.insert(candyType[i]);
                count++;
            }
        }
        
        if(count >= (n/2))
            return n/2;
        else
            return count;
    }
};