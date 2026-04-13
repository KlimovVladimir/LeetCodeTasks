typedef struct Node {
    char val;
    struct Node* next;
} Node_t;

void addToHead(Node_t** head, char val) {
    Node_t* newNode = (Node_t *) malloc(sizeof(Node_t));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

void freeList(Node_t** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int checkEntry(Node_t* head, char val) {
    Node_t* current = head;
    while (current != NULL) {
        if (current->val == val)
            return 1;
        current = current->next;
    }
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    Node_t* list = NULL;
    int length = strlen(s);
    int currentLength = 0, maxLength = 0;
    char* currString = s;

    for (int i = 0; i < length; i++) {
        currString = s;
        for (int j = i; j < length ; j++) {
            if (checkEntry(list, *currString) == 0) {
                addToHead(&list, *currString);
                currentLength++;

                if (maxLength < currentLength)
                    maxLength = currentLength;
            }
            else {
                if (maxLength < currentLength)
                    maxLength = currentLength;
                
                freeList(&list);
                currentLength = 0;
                break;
            }
            currString++;
        }
        s++;
    }

    freeList(&list);

    return maxLength;
}
