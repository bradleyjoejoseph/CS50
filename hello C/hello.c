#include<cs50.h>
#include<stdio.h>
#include<unistd.h>
int main(void)
{
    string name = get_string("What may your name be?");
    printf("Hello %s\n", name);
}