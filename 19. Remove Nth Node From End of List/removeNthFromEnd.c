/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    int listLength = 1;
    struct ListNode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
        listLength++;
    }

    if (listLength == 1)
        return NULL;

    int indexToDelete = listLength - n;

    if (n == listLength) {
        head = head->next;
        return head;
    }

    listLength = 1;
    curr = head;
    while (listLength < indexToDelete) {
        curr = curr->next;
        listLength++;
    }

    if (curr->next != NULL)
        curr->next = (curr->next)->next;
    else
        curr->next = NULL;

    return head;
}
