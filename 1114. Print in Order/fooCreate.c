typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t first;
    pthread_mutex_t second;
    
} Foo;

// Function Declaration, do not remove
void printFirst();
void printSecond();
void printThird();

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    pthread_mutex_init(&(obj->first), NULL);
    pthread_mutex_init(&(obj->second), NULL);

    pthread_mutex_lock(&(obj->first));
    pthread_mutex_lock(&(obj->second));
    
    // Initialize user defined data here.
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_unlock(&(obj->first));
}

void second(Foo* obj) {
    pthread_mutex_lock(&(obj->first));
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    pthread_mutex_unlock(&(obj->second));
}

void third(Foo* obj) {
    pthread_mutex_lock(&(obj->second));
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    pthread_mutex_unlock(&(obj->second));
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&(obj->first));
    pthread_mutex_destroy(&(obj->second));
    free(obj);
}
