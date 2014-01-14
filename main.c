#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

void logAnExpense();
bool iterate_expense(void *data);
void cleanUp();

typedef struct
{
    int amount;
    char item[20];
    char date[12];
} expense;

linkedList expenseList;

int main()
{
    int choice = 0;
    int continueApp = TRUE;
    list_new(&expenseList, sizeof(expense), NULL);

    while(continueApp)
    {
        printf("\nWhat would you like to do? \n");
        printf("1) Log an expense\n");
        printf("2) View logs\n");
        printf("3) Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                logAnExpense();
                break;
            case 2:
                list_for_each(&expenseList, iterate_expense);
                break;
            case 3:
                cleanUp();
                continueApp = FALSE;
                break;
            default:
                printf("\nError: That's not an option! \n");
                break;
        }
    }

    return 0;
}

void logAnExpense()
{
    expense anExpense;

    printf("\nWhat is the item? \n");
    scanf("%s", (char*)anExpense.item);

    printf("\nWhat is the value? \n");
    scanf("%d", &anExpense.amount);

    printf("\nWhat is the date? \n");
    scanf("%s", (char*)anExpense.date);

    list_append(&expenseList, &anExpense);
}

bool iterate_expense(void *data)
{
    expense *ep = ((expense *)data);
    printf("\nItem: %s, Value: %d, Date: %s\n", ep->item, ep->amount, ep->date);
    return TRUE;
}

void cleanUp()
{
    list_destroy(&expenseList);
}





