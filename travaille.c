#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int a[10] = {12, 255, 351, 210, 999, 1000, 11, 2222, 3, 4};
    int diviseur = 1;

    int max = a[0];
    for (int i = 1; i < 10; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    while (max / diviseur > 0)
    {
        for (int j = 0; j < 10 - 1; j++)
        {
            for (int k = 0; k < 10 - j - 1; k++)
            {
                if ((a[k] / diviseur) % 10 > (a[k + 1] / diviseur) % 10)
                {

                    int temp = a[k];
                    a[k] = a[k + 1];
                    a[k + 1] = temp;
                }
            }
        }

        diviseur *= 10;
    }

    for (int j = 0; j < 10; j++)
    {
        printf("%d  <  ", a[j]);
    }

    return 0;
}
