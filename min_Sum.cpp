/*
 * 给定n个整数组成的序列，现在要求将序列分割为m段，每段子序列中的数在原序列中连续排列。
 * 如何分割才能使这m段子序列的和的最大值达到最小？
*/

/*
 * 此题为动态规划题目：
 * 使用dp[i][j]表示i个数分割为j的解
 * 则dp[i][1] = dp[i-1] + nums[i];
 * 当j>1时，假定前k个数为j-1段，k~i为第j段；
 * 则前j-1段的最小最大值为:dp[k][j-1];
 * 最后一段值为：dp[i][1] - dp[k][1];
 * 这两个数中取最大值，当所有分段情况完成之后，选出最小值即为所求。
*/

#define MAX 100
int X = 10000;
int num[MAX];
int dp[MAX][MAX];
int myfunc(int n, int m) {
    int i, j, k, temp, min;
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i)
        dp[i][1] = dp[i-1][1] + num[i];

    for (i = 2; i <= n; ++i) {
        for (j = 2; j <= m; ++j) {
            for (k = 1, temp = X; k < i; ++k) {
                min = max(dp[i][1]-dp[k][1], dp[k][j-1]);
                if (min < temp)
                    temp = min;
            }
            dp[i][j] = temp;
        }
    }
    return dp[n][m];
}
