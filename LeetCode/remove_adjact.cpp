class Solution {
public:
    string removeDuplicates(string S) {
        
        stack<char> st;
        
        for(auto x : S) {
            
            if(st.empty()){
                st.push(x);
            } else if(st.top() == x) {
                st.pop();
            } else {
                st.push(x);
            }
        }
        
    string ans="";


    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
        
        return ans;
    }
};