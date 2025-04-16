#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int number, n, nguess = 1;
    srand(time(0));
    number = rand() % 100 + 1;
    do
    {
        printf("Enter your choice:");
        scanf("%d", &n);
        if (n > number)
        {
            printf("Lower number please!!\n");
        }
        else if (n < number)
        {
            printf("Upper number please!!\n");
        }
        else
        {
            printf("Congratulations!! You got the number in %d times\n", nguess);
        }
        nguess++;
    } while (n != number);
}