char * intToRoman(int num){
    char* thousands[] = {"", "M", "MM", "MMM"};
    char* hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char* ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    char* result = (char*)malloc(sizeof(char) * 16);
    strcpy(result, thousands[num / 1000]);
    strcat(result, hundreds[(num % 1000) / 100]);
    strcat(result, tens[(num % 100) / 10]);
    strcat(result, ones[num % 10]);

    return result;
}
