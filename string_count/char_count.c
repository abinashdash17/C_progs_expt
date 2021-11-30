#include <stdio.h>
#include <string.h>

void enc_str(char *str)
{
    int l = strlen(str);
    int ch_count[52]; // 52 (for capital and small letters)
    char ch_list[52];
    int ind = 1;
    ch_list[0] = str[0];
    ch_count[0] = 1;
    for (int i = 1; i < l; i++)
    {
        char ch = str[i];
        int isMatched = 0;
        for (int j = 0; j < ind; j++)
        {
            if (ch == ch_list[j])
            {
                ch_count[j]++;
                isMatched = 1;
                break;
            }
        }
        if (isMatched == 0)
        {
            ch_list[ind] = ch;
            ch_count[ind] = 1;
            ind++;
        }
    }
    // printf("%d", l);
    for (int i = 0; i < ind; i++)
    {
        printf("%c", ch_list[i]);
        if(ch_count[i] != 1) printf("%d", ch_count[i]) ;
    }
}

int main()
{
    char ip[] = "ccvVartttvVa";
    enc_str(ip);
    // printf("%s", ip);
    return 0;
}