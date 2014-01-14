#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "LinkedList.h"

void list_new(linkedList *list, int elementSize, freeFunction freeFn)
{
    assert(elementSize > 0);
    list->length = 0;
    list->elementSize = elementSize;
    list->head = list->tail = NULL;
    list->freeFn = freeFn;
}

void list_destroy(linkedList *list)
{
    listNode *current;

    while(list->head != NULL)
    {
        current = list->head;
        list->head = current->next;

        if(list->freeFn)
        {
            list->freeFn(current->data);
        }

        free(current->data);
        free(current);
    }
}

void list_prepend(linkedList *list, void *element)
{
    listNode *node = malloc(sizeof(listNode));
    node->data = malloc(list->elementSize);
    memcpy(node->data, element, list->elementSize);

    node->next = list->head;
    list->head = node;

    if(!list->tail)
    {
        list->tail = list->head;
    }

    list->length++;
}

void list_append(linkedList *list, void *element)
{
    listNode *node = malloc(sizeof(listNode));
    node->data = malloc(list->elementSize);
    node->next = NULL;

    memcpy(node->data, element, list->elementSize);

    if(list->length == 0)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }

    list->length++;
}

void list_for_each(linkedList *list, listIterator iterator)
{
    assert(list->head != NULL);

    listNode *node = list->head;
    bool result = TRUE;
    while(node != NULL && result)
    {
        result = iterator(node->data);
        node = node->next;
    }
}

void list_head(linkedList *list, void *element, bool removeFromList)
{
    assert(list->head != NULL);

    listNode *node = list->head;
    memcpy(element, node->data, list->elementSize);

    if(removeFromList) {
        list->head = node->next;
        list->length--;

        free(node->data);
        free(node);
    }
}

void list_tail(linkedList *list, void *element)
{
    assert(list->tail != NULL);
    listNode *node = list->tail;
    memcpy(element, node->data, list->elementSize);
}

int list_size(linkedList *list)
{
    return list->length;
}