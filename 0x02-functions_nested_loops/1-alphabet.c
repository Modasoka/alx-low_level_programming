#include "main.h"
/**
 * print_function - function that prints letters in lowercase from a to z
 * 
 * Return: 0-success, -1 -error
 */
void print_alphabet(void)
{
 char alphabet;
 for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
 {
    _putchar(alphabet);
 }
 _putchar("\n");
}