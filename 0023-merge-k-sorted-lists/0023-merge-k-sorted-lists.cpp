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
private:
    void _emplaceBackInList(ListNode *list, int value) {
        while (list->next != nullptr) {
            list = list->next;
        }
        list->next = new ListNode(value);
    }

    bool _returnEarly(vector<ListNode *> &lists) const {
        if (lists.empty()) return true;

        for (auto &list: lists) {
            if (list != nullptr) return false;
        }
        return true;
    }


public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        if (_returnEarly(lists)) {
            return nullptr;
        }

        auto *ans = new ListNode();

        // heap to keep the value (used for sorting) and the node
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<>> pq;

        // find the minimum value in the first element of each list
        for (auto &list: lists) {
            if (list != nullptr) pq.emplace(list->val, list);
        }

        ans->val = pq.top().first;

        ListNode *currentNode;
        while (!pq.empty()) {
            currentNode = pq.top().second;
            pq.pop();

            currentNode = currentNode->next;
            if (currentNode != nullptr) {
                pq.emplace(currentNode->val, currentNode);
            }
            if (!pq.empty()) {
                _emplaceBackInList(ans, pq.top().first);
            }
        }

        return ans;
    }

};