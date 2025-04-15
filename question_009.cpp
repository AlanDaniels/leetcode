/*
https://leetcode.com/problems/palindrome-number/
*/

// First, the easy way, doing it as a string.
class Solution1 {
public:
    bool isPalindrome(int x) {
        std::string str = to_string(x);
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

// Second, reversing the number in-place. Much better.
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int reverse = 0;
        int clone = x;
        while (clone > 0) {
            printf("Before: %d , %d\n", clone, reverse);
            reverse += clone % 10;
            clone /= 10;
            if (clone != 0) {
                reverse *= 10;
            }
            printf("After:  %d , %d\n", clone, reverse);
        }

        printf("%d , %d\n", clone, reverse);
        return reverse == x;
    }
};
