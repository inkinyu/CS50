#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
/*this is a encrypt machine but you can */

int main(int argc, string argv[])
{
    //first of all, check base case
    if (argc != 2)
    {
        printf("Usage: ./vigenere k \n");
        return 1;
    }
    else
    {
        //need atoi to keep argv
        int key[strlen(argv[1])];
        char *tmp = argv[1];
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (islower(tmp[i]))
            {
                key[i] = tmp[i] - 'a';
            }
            //this case is for capital
            else if (isupper(tmp[i]))
            {
                key[i] = tmp[i] - 'A';
            }
            else
            {
                return 1;
            }
        }
        int m = strlen(tmp);
        //get plaintext from user
        char *s;
        s = get_string("plaintext: ");
        //show time
        printf("ciphertext: ");
        //now go over the string
        int j = 0;
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            //first check lower case
            if (islower(s[i]))
            {
                //pattern: get c -> get ASCII -> get after ASCII -> show ciphertext
                char c = s[i];
                int before = c;
                int after = (before + key[(j % m)] - 'a') % 26;
                printf("%c", 'a' + after);
                j++;
            }
            //this case is for capital
            else if (isupper(s[i]))
            {
                char c = s[i];
                int before = c;
                int after = (before +  key[(j % m)] - 'A') % 26;
                printf("%c", 'A' + after);
                j++;
            }
            //not anything to do with alphabets
            else if (s[i] == ' ')
            {
                printf("%c", s[i]);
                j--;
            }
            else
            {
                printf("%c", s[i]);
                j++;
            }
        }
        //end of code and return workspace
        printf("\n");
    }
}
