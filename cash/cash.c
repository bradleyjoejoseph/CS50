#include<cs50.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
int main(void)
{
    int coinCount = 0;
    float money = get_float("Change owed: ");
    while (money <= 0)
    {
        money = get_float("Change owed: ");
    }
    int moneyRounded = round(money * 100);

    while (moneyRounded > 0)
    {

        if (moneyRounded - 25 >= 0)
        {
            coinCount += 1;
            moneyRounded -= 25;
        }
        else if (moneyRounded - 10 >= 0)
        {
            coinCount += 1;
            moneyRounded -= 10;
        }
        else if (moneyRounded - 5 >= 0)
        {
            coinCount += 1;
            moneyRounded -= 5;
        }
        else if (moneyRounded - 1 >= 0)
        {
            coinCount += 1;
            moneyRounded -= 1;
        }


    }

    printf("Coins: %i\n", coinCount);
}
