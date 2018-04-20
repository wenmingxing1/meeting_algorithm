/*最长公共子序列*/

#include<iostream>
#include<string>

using namespace std;

int Max(int a, int b) {
    return a>b?a:b;
}

int LongestCommonSubsequence (const string& str1, const string& str2) {
    int length1 = str1.size();
    int length2 = str2.size();
    if (length1 == 0 || length2 == 0) return 0;
    int dp[length1+1][length2+1] = {};

    //i与j从1算起是考虑到dp中的i-1与j-1
    for (int i = 1; i <= length1; ++i) {
        for (int j = 1; j <= length2; ++j) {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = Max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[length1][length2];
}


int main() {
    string str1 = "abc";
    string str2 = "acb";


    int res = LongestCommonSubsequence(str1, str2);

    cout << res << endl;

    return 0;
}
