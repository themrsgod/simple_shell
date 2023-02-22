
/* Tokenize user input into arguments, handling special characters */
int tokenize(char *buffer, char **args) {
    int i = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        /* Handle special characters */
        if (is_special(token[0])) {
            args[i] = token;
            i++;
        } else {
            /* Tokenize argument */
            args[i] = strtok(token, "\"'`\\*&#");
            while (args[i] != NULL) {
                i++;
                args[i] = strtok(NULL, "\"'`\\*&#");
            }
        }
        token = strtok(NULL, " ");
    }
    args[i] = NULL; /* Null-terminate argument list */
    return i;
}