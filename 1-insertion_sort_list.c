#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @head: Pointer to the head of the list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    else
        *head = node2;
    
    if (node2->next)
        node2->next->prev = node1;
    
    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;
    
    if (!list || !*list || !(*list)->next)
        return;
    
    current = (*list)->next;
    
    while (current)
    {
        temp = current;
        while (temp->prev && temp->n < temp->prev->n)
        {
            swap_nodes(list, temp->prev, temp);
            print_list(*list);
        }
        current = current->next;
    }
}

