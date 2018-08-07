#include <stdio.h>
#include <cs50.h>
/*this is a Super Mario pyramid maker */
int main(void)
{
    //get height from user
    int height;
    //do while (get_int, [0.23])
    do
    {
        height = get_int("Height = ");
    }
    while
    (
        height < 0 || height > 23
    );
    //for each row do...
    for (int i = 0; i < height; i++)
    {
        //print space
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        //print #
        for (int k = 0; k < i + 2 ; k++)
        {
            printf("#");
        }
        //print \n
        printf("\n");
    }



}
