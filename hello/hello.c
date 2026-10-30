#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask the user for their name.
    string name = get_string("what is your name? ");
    // print the greeting with the username.
    printf("hello, %s\n", name);
}