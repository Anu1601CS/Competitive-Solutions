
// public class Solution
// {

//     public int maxOfMinAltitudes(
//                                  int[][] grid)
//     {

//         int r = grid.length, c = grid[0].length;
//         int[] dp = new int[c];

//         if(r == 1 && c==1 )
//             return grid[0][0];

//         dp[0] = Integer.MAX_VALUE;
//         for (int j = 1; j < c; ++j)
//          dp[j] = Math.min(dp[j - 1], grid[0][j]);

//         for (int i = 1; i < r; ++i) {

//         dp[0] = Math.min(dp[0], grid[i][0]);

//         for (int j = 1; j < c; ++j)
//         {
//             if (i == r - 1 && j == c - 1)
//             {
//               dp[j] = Math.max(dp[j - 1], dp[j]);
//             }
//             else
//             {
//               int score1 = Math.min(dp[j - 1], grid[i][j]);
//               int score2 = Math.min(dp[j], grid[i][j]);
//               dp[j] = Math.max(score1, score2);
//             }
//       }
//      }
//     return dp[c - 1];
//     }
// }