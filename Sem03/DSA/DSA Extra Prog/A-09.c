#include <stdio.h>
#include <stdlib.h>

struct directNode
{
    struct node *point;
    struct directNode *next;
};
struct node
{
    int atm_id;
    int bank_id;
    int city_id;
    int loc_id;
    struct node *next;
    struct directNode *nextNode;
};

void create(struct node **st)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    printf("ATM ID: (Always starts with 1 and is of 4 digits) ");
    scanf("%d", &n->atm_id);
    printf("BANK_ID: (Always starts with 2 and is of 4 digits) ");
    scanf("%d", &n->bank_id);
    printf("CITY ID: (Always starts with 3 and is of 4 digits) ");
    scanf("%d", &n->city_id);
    printf("LOCATION ID: (Always starts with 4 and is of 4 digits) ");
    scanf("%d", &n->loc_id);
    n->next = NULL;
    n->nextNode = NULL;

    if (*st == NULL)
    {
        *st = n;
    }
    else
    {
        struct node *temp = *st;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}
void connect(struct node **st)
{
    int n = 1;
    while (n == 1)
    {
        int atm1, atm2;
        printf("Enter the ATM IDs:\n ");
        printf("1st ATM: ");
        scanf("%d", &atm1);
        printf("2nd ATM: ");
        scanf("%d", &atm2);

        struct node *temp = *st, *atm_id1 = NULL, *atm_id2 = NULL;
        int flag1 = 0, flag2 = 0;
        while (temp != NULL)
        {
            if (temp->atm_id == atm1)
            {
                flag1 = 1;
                atm_id1 = temp;
            }

            if (temp->atm_id == atm2)
            {
                flag2 = 1;
                atm_id2 = temp;
            }
            temp = temp->next;
        }
        if (flag1 != 1)
            printf("ATM with the 1st ATM ID is not present in the program.");
        else if (flag2 != 1)
            printf("ATM with the 2nd ATM ID is not present in the program.");
        else
        {
            struct directNode *n1 = (struct directNode *)malloc(sizeof(struct directNode));
            if (atm_id1->nextNode == NULL)
                atm_id1->nextNode = n1;
            else
            {
                struct directNode *temp = atm_id1->nextNode;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = n1;
            }
            n1->point = atm_id2;
            n1->next = NULL;
            struct directNode *n2 = (struct directNode *)malloc(sizeof(struct directNode));
            if (atm_id2->nextNode == NULL)
                atm_id2->nextNode = n2;
            else
            {
                struct directNode *temp = atm_id2->nextNode;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = n2;
            }
            n2->point = atm_id1;
            n2->next = NULL;
        }

        printf("If want to make more connections, press 1 or 0\n");
        scanf("%d", &n);
        if (n == 0)
            return;
    }
}
void traverse(struct node *st)
{
    int atmID, locID;
    printf("Enter the ATM ID: ");
    scanf("%d", &atmID);
    printf("Enter the LOCATION ID: ");
    scanf("%d", &locID);

    struct node *temp = st;
    while (temp != NULL)
    {
        if (temp->atm_id == atmID && temp->loc_id == locID)
            break;
    }

    if (temp == NULL)
    {
        printf("No ATM present with the entered ATM ID and LOCATION ID.\n");
        return;
    }

    printf("The nearest ATM has these following IDs: \n");
    printf("ATM ID: %d\n", temp->atm_id);
    printf("BANK ID: %d\n", temp->bank_id);
    printf("CITY ID: %d\n", temp->city_id);
    printf("LOCATION ID: %d\n\n", temp->loc_id);

    printf("Subsequent neighbouring ATMs of this ATM: \n");
    struct directNode *t = temp->nextNode;
    while (t != NULL)
    {
        printf("ATM ID: %d\n", t->point->atm_id);
        printf("BANK ID: %d\n", t->point->bank_id);
        printf("CITY ID: %d\n", t->point->city_id);
        printf("LOCATION ID: %d\n\n", t->point->loc_id);
        t = t->next;
    }
}
int main()
{
    struct node *head = NULL;
    int n = 1, ch;
    while (n == 1)
    {
        printf("Choose: \n");
        printf("1. Create the graph\n");
        printf("2. Traverse\n");
        printf("3. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int n;
            printf("Enter the no. of ATMs: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
                create(&head);
            connect(&head);
            break;
        }
        case 2:
        {
            traverse(head);
            break;
        }
        case 3:
            exit(0);
        }
        printf("\nIf want to continue, press 1 or 0.\n");
        scanf("%d", &n);
        if (n == 0)
            exit(0);
    }
}
