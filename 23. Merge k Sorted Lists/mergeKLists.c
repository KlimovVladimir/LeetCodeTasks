/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode result;
    struct ListNode* tail = &result;
    result.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;
    
    return result.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if (listsSize == 0)
        return NULL;
    else if (listsSize == 1)
        return lists[0];

    struct ListNode* result = lists[0];

    for (int i = 1; i < listsSize; i++) {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
}
