/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* resultList = NULL;
    struct ListNode* current = NULL;
    unsigned int digit = 0, result = 0;
    
    while (l1 != NULL || l2 != NULL || result != 0) {
        if (l1 != NULL) {
            digit += l1->val;
            l1 = l1->next; 
        }

        if (l2 != NULL) {
            digit += l2->val;
            l2 = l2->next; 
        }

        result += digit;

        digit = result % 10;

        result = (result - digit) / 10;

        struct ListNode* newListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newListNode->val = digit;
        newListNode->next = NULL;
        digit = 0;
        if (resultList == NULL) {
            resultList = newListNode;
        }
        else {
            current = resultList;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newListNode;
        }
    }

    return resultList;
}
