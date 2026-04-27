#include <stdatomic.h>

typedef struct {
    int n;
    atomic_int x;
} FooBar;

// Function declarations. Do not change or remove this line
void printFoo();
void printBar();

static inline void wait_x(FooBar* obj, int value) {
    while (atomic_load(&(obj->x)) != value) {
        usleep(100);
    }
}

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    atomic_store(&(obj->x), 1);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        wait_x(obj, 1);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        atomic_store(&(obj->x), 2);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        wait_x(obj, 2);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        atomic_store(&(obj->x), 1);
    }
}

void fooBarFree(FooBar* obj) {
    free(obj);
}
