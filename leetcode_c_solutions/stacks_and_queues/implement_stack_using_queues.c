typedef struct {
    int* queue1;
    int head1;
    int tail1;
    int* queue2;
    int head2;
    int tail2;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->size = 100;
    obj->queue1 = (int*)malloc(obj->size * sizeof(int));
    obj->queue2 = (int*)malloc(obj->size * sizeof(int));
    obj->head1 = -1;
    obj->tail1 = -1;
    obj->head2 = -1;
    obj->tail2 = -1;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue2[++obj->tail2] = x;
    while (obj->head1 != -1) {
        obj->queue2[++obj->tail2] = obj->queue1[++obj->head1];
    }
    int* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
    obj->head1 = obj->head2;
    obj->tail1 = obj->tail2;
    obj->head2 = -1;
    obj->tail2 = -1;
}

int myStackPop(MyStack* obj) {
    return obj->queue1[obj->head1++];
}

int myStackTop(MyStack* obj) {
    return obj->queue1[obj->head1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->head1 == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
