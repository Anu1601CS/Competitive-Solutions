class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int>indeg(N+1, 0);
        vector<int>outdeg(N+1, 0);
        int ans = -1;
        
        for(int i=0;i<trust.size(); i++) {
            int f = trust[i][0];
            int s = trust[i][1];
            
            indeg[s]++;
            outdeg[f]++;
        }
        
        for(int i=1; i<=N; i++) {
            if(indeg[i] == N-1 && outdeg[i] == 0)  {
                ans = i;   
            }
        }
        
        return ans;
    }
};Ï