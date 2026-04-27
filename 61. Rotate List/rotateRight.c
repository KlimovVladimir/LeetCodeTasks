/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL)
        return head;

    struct ListNode* result = NULL;
    unsigned int length = 1;
    struct ListNode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
        length++;
    }

    k %= length;
    if (k == 0) return head;

    unsigned int shift = length - k - 1;
    curr = head;
    for (int i = 0; i < shift; i++)
        curr = curr->next;

    result = curr->next;
    curr->next = NULL;

    curr = result;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = head;
    
    return result;
}
