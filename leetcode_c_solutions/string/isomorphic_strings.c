bool isIsomorphic(char * s, char * t){
    int s_map[128] = {0};
    int t_map[128] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        if (s_map[s[i]] != t_map[t[i]]) {
            return false;
        }
        s_map[s[i]] = i + 1;
        t_map[t[i]] = i + 1;
    }

    return true;
}
