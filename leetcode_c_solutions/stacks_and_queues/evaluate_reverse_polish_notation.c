int evalRPN(char ** tokens, int tokensSize){
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0) {
            stack[top-1] += stack[top];
            top--;
        } else if (strcmp(tokens[i], "-") == 0) {
            stack[top-1] -= stack[top];
            top--;
        } else if (strcmp(tokens[i], "*") == 0) {
            stack[top-1] *= stack[top];
            top--;
        } else if (strcmp(tokens[i], "/") == 0) {
            stack[top-1] /= stack[top];
            top--;
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    return stack[top];
}
