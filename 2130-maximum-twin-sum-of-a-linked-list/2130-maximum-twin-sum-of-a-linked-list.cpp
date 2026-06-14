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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>ans;
        while(head){
            ans.push_back(head->val);
            head= head->next;
        }
        int s = 0;
        int e = ans.size()-1;
        int maxi = 0;
        while(s < e){
           maxi = max(maxi, ans[s]+ans[e]);
           s++;
           e--;
        }
        return maxi;
    }
};