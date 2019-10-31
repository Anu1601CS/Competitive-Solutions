class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int l = nums.size();
        
        int zero;
        
        for(int i=0; i<l; i++)
        { 
            if( nums[i] == 0)
            {
                zero = i;
                break;
            }
        }
        
        int till = zero;
        for(int i = zero; i<l; i++) 
        {
            if(nums[i] != 0) 
            {
                nums[till] = nums[i];
                nums[i] = 0;
                till++;
            } 
            
        }
    }
};