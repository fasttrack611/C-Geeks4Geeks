typedef struct {
    int* queue;
    int head;
    int tail;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->size = k;
    obj->queue = (int*)malloc(obj->size * sizeof(int));
    obj->head = -1;
    obj->tail = -1;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->tail + 1) % obj->size == obj->head) {
        return false;
    }
    if (obj->head == -1) {
        obj->head = 0;
    }
    obj->tail = (obj->tail + 1) % obj->size;
    obj->queue[obj->tail] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->head == -1) {
        return false;
    }
    if (obj->head == obj->tail) {
        obj->head = -1;
        obj->tail = -1;
    } else {
        obj->head = (obj->head + 1) % obj->size;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->head == -1) {
        return -1;
    }
    return obj->queue[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->tail == -1) {
        return -1;
    }
    return obj->queue[obj->tail];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->head == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail + 1) % obj->size == obj->head;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
