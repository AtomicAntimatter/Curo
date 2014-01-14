#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum { FALSE, TRUE } bool;          // Reimplement boolean type
typedef void (*freeFunction)(void *);       // function to use to delete elements in LinkedList
typedef bool (*listIterator)(void *);       // function to use when iterating through elements in LinkedList

// Node in the LinkedList
typedef struct _node
{
    void *data;
    struct _node *next;
} listNode;

// LinkedList
typedef struct
{
    int length;
    int elementSize;
    listNode *head;
    listNode *tail;
    freeFunction freeFn;
} linkedList;

void list_new(linkedList *list, int elementSize, freeFunction freeFn);     // Init list with size and function to use to delete node
void list_destroy(linkedList *list);                                       // frees nodes
void list_prepend(linkedList *list, void *element);                        // adds node to head of list
void list_append(linkedList *list, void *element);                         // adds node to tail of list
int list_size(linkedList *list);                                           // returns number of items in the list
void list_for_each(linkedList *list, listIterator aIterator);              // calls the iterator function with element of each node
void list_head(linkedList *list, void *element, bool removeFromList);      // returns the head of the list with option to remove
void list_tail(linkedList *list, void *element);                           // returns the tail of the list

#endif
