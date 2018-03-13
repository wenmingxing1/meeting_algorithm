/*
 * ����n��������ɵ����У�����Ҫ�����зָ�Ϊm�Σ�ÿ���������е�����ԭ�������������С�
 * ��ηָ����ʹ��m�������еĺ͵����ֵ�ﵽ��С��
*/

/*
 * ����Ϊ��̬�滮��Ŀ��
 * ʹ��dp[i][j]��ʾi�����ָ�Ϊj�Ľ�
 * ��dp[i][1] = dp[i-1] + nums[i];
 * ��j>1ʱ���ٶ�ǰk����Ϊj-1�Σ�k~iΪ��j�Σ�
 * ��ǰj-1�ε���С���ֵΪ:dp[k][j-1];
 * ���һ��ֵΪ��dp[i][1] - dp[k][1];
 * ����������ȡ���ֵ�������зֶ�������֮��ѡ����Сֵ��Ϊ����
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
