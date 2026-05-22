class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    if (len <= 3) {
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }

                if (dp[i][j] && len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};