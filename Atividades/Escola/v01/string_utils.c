#include <string.h>
#include <ctype.h>

void remove_nova_linha_fgets(char* string) {
    size_t length = strlen(string);
    if((length > 0) && (string[length-1] == '\n'))
        string[length-1] ='\0';
}