class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);

        for(char c : t)
            need[c]++;

        int left = 0;
        int right = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()) {

            if(need[s[right]] > 0)
                count--;

            need[s[right]]--;

            right++;

            while(count == 0) {

                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                need[s[left]]++;

                if(need[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};