/*
https://leetcode.com/problems/add-two-numbers/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // No need to go through the list backwards, we can just use a bit of
 // recursion, as the question intended.
class Solution {
public:
    int getValue(ListNode* node, int multiplier)
    {
        int child_val = node->next ? getValue(node->next, multiplier * 10) : 0;
        return node->val * multiplier + child_val;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Walk the two linked lists, building as we go.
        int val1 = getValue(l1, 1);
        int val2 = getValue(l2, 1);
        int sum = val1 + val2;
        printf("Val1 = %d\n", val1);
        printf("Val2 = %d\n", val2);
        printf("Sum  = %d\n", sum);

        // Build the result, same style.
        ListNode *top = new ListNode(sum % 10);
        printf("Top created %d\n", sum % 10);
        printf("Top Sum = %d\n", sum);
        ListNode *current = top;
        for (sum /= 10; sum > 0; sum /= 10) {
            current->next = new ListNode(sum % 10);
            printf("Next created %d\n", sum % 10);
            printf("Next sum = %d\n", sum);
            current = current->next;
        }

        return top;
    }
};
