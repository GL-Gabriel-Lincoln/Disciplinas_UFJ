typedef struct
{
    char *characters;
    int length;
} String;

void inicializaString(String *s, char *str);
void concatenaString(String *s1, String *s2);
int comparaString(String *s1, String *s2);