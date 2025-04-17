/*
https://leetcode.com/problems/roman-to-integer/
*/

// No multiple approaches here. This is as good as it gets.
class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int result = 0;

        int i = 0;
        while (i < len) {
            char ch = s[i];
            char next = '\0';
            if (i < (len -1)) {
                next = s[i + 1];
            }

            switch (ch)
            {
                case 'I':
                    switch (next) {
                        case 'V': result += 4; i += 2; break;
                        case 'X': result += 9; i += 2; break;
                        default:  result += 1; i++; break;
                    }
                    break;

                case 'X':
                    switch (next) {
                        case 'L': result += 40; i += 2; break;
                        case 'C': result += 90; i += 2; break;
                        default:  result += 10; i++; break;
                    }
                    break;

                case 'C':
                    switch (next) {
                        case 'D': result += 400; i += 2; break;
                        case 'M': result += 900; i += 2; break;
                        default:  result += 100; i++; break;
                    }
                    break;

                case 'V': result += 5; i++; break;
                case 'L': result += 50; i++; break;
                case 'D': result += 500; i++; break;
                case 'M': result += 1000; i++; break;

                default:
                    printf("Unexpected character: %c\n", ch);
                    i++;
            }
        }
        return result;
    }
};
