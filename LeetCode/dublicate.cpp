
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     
        map<int,int> myMap;
        
        for(auto a: nums)
        {
            myMap[a]++;
            
            if(myMap[a] >=2)
                return true;
        }
        
        
        return false;
        
    }
};