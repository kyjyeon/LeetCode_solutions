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
    ListNode* sortList(ListNode* head) {
        //Use priority_queue to automatically sort value
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode* value = head;
        while (head) {
            pq.push(value->val);
            if (value->next)
                value = value->next;
            else
                break;
        }
        value = head;
        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            value->val = top;
            value = value->next;
        }

        return head;
    }
};