class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        unordered_map<int,bool>myMap;
        
   
        stack<int>st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]== ')'){
                if(st.empty()){
                    myMap[i] = true;
                } else {
                    st.pop();
                }
            }
        }
        
        while(!st.empty())
        {
            myMap[st.top()] = true;
            st.pop();
        }
        
        string ans = "";
        for(int i=0;i<s.length(); i++){
            if(myMap[i]) {
                continue;
            } else {
                ans = ans + s[i];
            }
        }
        
        return ans;
    }
};