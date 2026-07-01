#include "lists.h"

int main(void)
{
    listint_t *head = NULL;

    insert_node(&head, 5);
    insert_node(&head, 2);
    insert_node(&head, 8);

    return (0);
}
