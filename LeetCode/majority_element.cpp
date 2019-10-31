class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int,int> myMap;
        
        int ans;
        for(int i=0; i<nums.size(); i++)
        {
            myMap[nums[i]]++;
            
            if(myMap[nums[i]]  > floor(nums.size() / 2))
                ans = nums[i];
        }
        
        
        return ans;
        
    }
};