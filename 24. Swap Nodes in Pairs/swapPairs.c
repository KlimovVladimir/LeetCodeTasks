/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return head;

    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* prev = result;
    struct ListNode* curr = head;

    while (curr && curr->next != NULL) {
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;

        prev = curr;
        curr = curr->next;
    }

    return result->next;
}
