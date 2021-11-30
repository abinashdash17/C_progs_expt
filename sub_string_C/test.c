#include <stdio.h>
#include <string.h>

int find_sub_s(char *x, char *ss, int *res)
{
    // printf("%zu %zu",strlen(x),strlen(ss));
    int ind = 0; // keep the count no of matches
    for (int i = 0; i <= strlen(x) - strlen(ss); i++)
    {
        int found = 1;
        for (int j = 0; j < strlen(ss); j++)
        {
            if (x[i + j] != ss[j])
            {
                found = 0;
                break;
            }
        }
        if (found == 1)
        {
            res[ind++] = i;
        }
    }
    return ind;
}
int main()
{
    char x[] = "independence";
    char ss[] = "en";
    int res[100];                            // int array to store the indexes of matched substring
    int no_of_subs = find_sub_s(x, ss, res); // no_of_subs stores no of matches found. 0 means no matches found
    if (no_of_subs != 0)
    {
        printf("index for substring matches\n");
        for (int i = 0; i < no_of_subs; i++)
            printf("%d ", res[i]);
    }
    else
        printf("No matches found\n");
    return 0;
}
