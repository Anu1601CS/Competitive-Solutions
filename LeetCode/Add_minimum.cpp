class Solution {
public:
    int minAddToMakeValid(string S) {
        
        stack<char>st;
        int count =0;
        for(int i=0; i<S.length(); i++){
            
            if(S[i] == '('){
                st.push(S[i]);
            } else if(S[i] == ')' && !st.empty()) {
                st.pop();
            } else {
                ++count;
            }           
        }
        
        return count + st.size();
        
    }
};