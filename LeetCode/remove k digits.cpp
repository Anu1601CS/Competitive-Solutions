class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>st;
        
        for(auto x: num) {
            
            while(!st.empty() && st.top() > x && k) {   
                st.pop();
                --k;
            }
            st.push(x);
        }
        
        string ss;
        
        while(!st.empty() && k){
            st.pop();
            --k;
        }
        
        while(!st.empty()){
            ss += st.top();
            st.pop();
        }
        
        reverse(ss.begin(), ss.end());
        
        if(ss.length() > 0 && ss[0] == '0') {
            
            int i;
            for(i=0; i<ss.length(); i++) {
                if(ss[i] != '0')
                    break;
                
            }
            
            ss = ss.substr(i, ss.length() - i);
        } 
        
        if(ss.length() == 0) {
            ss = "0";
        } 
        
        return ss;
        
    }
};