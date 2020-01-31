/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int count = 0;
        ListNode* curNode = head;
        vector<int>vec;
        while (curNode != NULL) {
            vec.push_back(curNode->val);
            curNode = curNode->next;
            ++count;
        }
        int size = vec.size();
        int total = 0;
        for (int i = 0; i < size; i++) {
            if (vec[i] == 1) {
                total += pow(2, size - 1 - i);
            }
        }
        cout << total;
        return total;
    }
};