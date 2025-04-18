/*
https://leetcode.com/problems/longest-common-prefix/
*/

// Not a fan of "goto", but it actually made the code simpler, so there you go.
class Solution {
public:
    char get(const string &str, int i) {
        return i < str.size() ? str[i] : '\0';
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        int i = 0;
        string result = "";

        while (true) {
            char target = get(strs[0], i);
            if (target == '\0') {
                goto DONE;
            }

            for (const string &s : strs) {
                if (get(s, i) != target) {
                    goto DONE;
                }
            }

            result += target;
            i++;
        }
    DONE:
        return result;
    }
};
