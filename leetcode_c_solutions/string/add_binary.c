char * addBinary(char * a, char * b){
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;
    int k = 0;
    char* result = (char*)malloc(sizeof(char) * (fmax(i, j) + 3));

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[k] = '\0';

    // Reverse the result
    int left = 0, right = k - 1;
    while (left < right) {
        char temp = result[left];
        result[left++] = result[right];
        result[right--] = temp;
    }

    return result;
}
