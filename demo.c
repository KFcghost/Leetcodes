#include "inc/uthash.h"
#include <stdio.h>
#include <malloc/malloc.h>

struct mystruct
{
    char *key;
    int index;
    UT_hash_handle hh;
};
struct mystruct* ge = NULL;

int main()
{
    char **str =  (char **)malloc(sizeof(char *) * 4);
    str[0] = "abc";
    str[1] = "abb";
    str[2] = "abd";
    str[3] = "abc";

    for (int i = 0;i < 4; ++i) {
        struct mystruct* temp = NULL;
        HASH_FIND_STR(ge, str[i], temp);
        if (temp == NULL) {
            temp = (struct mystruct*)malloc(sizeof(struct mystruct*));
            temp->key = str[i];
            temp->index = 1;
            char *key = str[i];
            HASH_ADD_STR(ge, key, temp);
        }   else {
            temp->index++;
        }
    }

    for(int i = 0; i < 4; ++i) {
        struct mystruct* temp = NULL;
        HASH_FIND_STR(ge, str[i], temp);
        if (temp != NULL)
        printf("findhash:str=%s,index=%d\n",temp->key,temp->index);
    }
    struct mystruct *temp1,*temp2;
    HASH_ITER(hh, ge, temp1, temp2) {
        printf("ITER:str=%s,index=%d\n",temp1->key,temp1->index);
    }
}