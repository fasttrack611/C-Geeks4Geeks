bool isValid(char * s){
    int len = strlen(s);
    if (len % 2 != 0) {
        return false;
    }

    char* stack = (char*)malloc(sizeof(char) * len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) {
                return false;
            }
            char c = stack[top--];
            if (s[i] == ')' && c != '(') {
                return false;
            }
            if (s[i] == '}' && c != '{') {
                return false;
            }
            if (s[i] == ']' && c != '[') {
                return false;
            }
        }
    }

    return top == -1;
}
