#include "main.h"

/**
 * main - entry point for program, checks the code
 * _isupper: checks for an uppercase letter
 * @c: letter to be checked by _isupper function
 * Return: 0 (success), -1 (error)
 */
int _isupper(int c)
{
    if(c => 'A' && c <= 'Z')
    {
        return(1);
    }
    else
    return(0);
}