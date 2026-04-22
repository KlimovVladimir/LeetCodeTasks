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

char takeFromHead(Node_t** head) {
    if (head == NULL || *head == NULL) {
        return '\0';
    }

    struct Node* next;
    char ret = (*head)->val;
    next = (*head)->next;
    free(*head);
    *head = next;
    
    return ret;
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

bool isValid(char* s) {
    Node_t* stack = NULL;
    int length = strlen(s);

    if (length % 2 != 0)
        return false;

    for (int i = 0; i < length; i++) {
        if (*s == '(' || *s == '[' || *s == '{')
            addToHead(&stack, *s);
        else if (*s == ')' || *s == ']' || *s == '}') {
            char tmp = takeFromHead(&stack);
            if (*s == ')' && tmp != '(')
                return false;
            else if (*s == ']' && tmp != '[')
                return false;
            else if (*s == '}' && tmp != '{')
                return false;
        }
        else 
            return false;
        s++;
    }

    bool result = (stack == NULL);
    freeList(&stack);
    return result;
}
