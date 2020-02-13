class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {     
        stack<pair<int,int>>st;
        unordered_map<int,int>myMap;
        vector<int>ans;
        
        int i = 0;
        for(auto x: T) {
            
            while(!st.empty() && st.top().first < x){
                myMap[st.top().second] = abs(st.top().second - i);
                st.pop();
            }
            
            st.push(make_pair(x, i));
            i++;
        }
        
        for(int i=0; i<T.size(); i++){
            ans.push_back(myMap[i]);
        }
        
        return ans;
            
    }
};