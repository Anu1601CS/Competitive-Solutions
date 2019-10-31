class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char,int> sm;
        map<char,int> st;
        
        if(s.length() != t.length())
            return false;
        
        for(int i=0; i<s.length(); i++)
            sm[s[i]]++;
        
        for(int i=0; i<t.length(); i++)
            st[t[i]]++;
        
        
        for(int i=0; i<s.length(); i++)
        {
            if(sm[s[i]] != st[s[i]])
                return false;
        }
        
        return true;
        
    }
};