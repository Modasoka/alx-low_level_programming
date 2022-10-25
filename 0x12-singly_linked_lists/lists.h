#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct list_s - a singly-linked list
 * @str: string that has been malloc_checked
 * @len: string length
 * @next: points to the node that comes after
 * 
 * Description: a structure of a singly linked list node
*/

typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

size_t print_list(const list_t);
size_t liste_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
int _putchar(char c);

#endif 