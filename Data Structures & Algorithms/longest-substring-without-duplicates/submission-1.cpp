class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxSize = 0;

        unordered_map<char, int> seen;

        while (r < s.size()) {

            if (seen.find(s[r]) != seen.end() && seen[s[r]] >= l) {
                l = seen[s[r]] + 1;
            }

            seen[s[r]] = r;

            maxSize = max(maxSize, r - l + 1);

            r++;
        }

        return maxSize;
    }
};