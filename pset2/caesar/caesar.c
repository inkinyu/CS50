#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
/*this is a encrypt machine*/

int main(int argc, string argv[])
{
    int key = -1;
    //first of all, check base
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    else
    {
        //need atoi to keep argv
        key = atoi(argv[1]);
        if (key > 0 || key < 27)
        {
            //get plaintext from user
            char *s;
            s = get_string("plaintext: ");
            //show time
            printf("ciphertext: ");
            //now go over the string
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                //first check lower case
                if (islower(s[i]))
                {
                    //pattern: get c -> get ASCII -> get after ASCII -> show ciphertext
                    char c = s[i];
                    int before = c;
                    int after = (before + key - 'a') % 26;
                    printf("%c", 'a' + after);
                }
                //this case is for capital
                else if (isupper(s[i]))
                {
                    char c = s[i];
                    int before = c;
                    int after = (before + key - 'A') % 26;
                    printf("%c", 'A' + after);
                }
                //not anything to do with alphabets
                else
                {
                    printf("%c", s[i]);
                }
            }
            //end of code and return workspace
            printf("\n");
        }
    }
}
