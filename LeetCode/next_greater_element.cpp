class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>st;
        unordered_map<int,int>myMap;
        
        for(auto x: nums2) {
            
            while(st.size() && st.top() < x) {
                myMap[st.top()] = x;
                st.pop();
            }
            
            st.push(x);
            
        }
        
        vector<int>ans;
        
        for(auto x : nums1) {
            if(myMap.count(x) != 0) {
                ans.push_back(myMap[x]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
        
    }
};