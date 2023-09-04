#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void create(struct node** start, struct node** lt, int num)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = num;
    n->next = NULL;

    if ((*start) == NULL)
    {
        (*start) = n;
        (*lt) = n;
    }
    else
    {
        (*lt)->next = n;
        (*lt) = n;
    }
}
void traverse(struct node** s)
{
    printf("Linked List :\n");
    struct node* temp = (*s);
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void sea_del_ins(struct node** start, int num)
{
    struct node* temp = (*start), * t = NULL;
    struct node* prev = (*start);
    while (temp->data != num && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n The data is not present in the list. \n");
        return;
    }
    else
    {
        t = temp;
        prev->next = temp->next;
    }

    t->next = (*start);
    (*start) = t;
}

void middle(struct node** start)
{
    struct node* tf = (*start);
    struct node* ts = (*start);

    while (tf != NULL && tf->next != NULL)
    {
        tf = tf->next->next;
        ts = ts->next;
    }

    printf("\nThe middle element is %d. \n", ts->data);
}

void reverse_m(struct node** start, int m)
{
    int n = 0;
    struct node* temp = (*start);
    while (temp != NULL)
    {
        temp = temp->next;
        n++;
    }
    temp = (*start);
    if (m == n)
    {
        struct node* t2, * prev = NULL;
        while (temp != NULL)
        {
            t2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = t2;
        }
        (*start) = prev;
    }
    else
    {
        struct node* t2, * prev = NULL, * cnt = (*start), * list_keep, * head_keep;
        while (m > 1)
        {
            cnt = cnt->next;
            m--;
        }
        list_keep = cnt->next;
        cnt->next = NULL;
        head_keep = (*start);
        while (temp != NULL)
        {
            t2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = t2;
        }
        (*start) = prev;
        head_keep->next = list_keep;
    }
}

void checkSort(struct node** start)
{
    struct node* temp = (*start)->next, * prev = (*start);
    while (temp != NULL)
    {
        if (prev->data > temp->data)
        {
            printf("\nThe list is not sorted. \n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nThe list is sorted. \n");
}

void insert_ele_sort(struct node** start, int m)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = m;

    struct node* temp = (*start), * prev;
    if (temp->data > m)
    {
        n->next = (*start);
        (*start) = n;
        return;
    }

    while (temp->next != NULL)
    {
        if (temp->data > m)
        {
            n->next = temp;
            prev->next = n;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}
struct node* reverse_group(struct node* temp, int num)
{
    if (temp == NULL)
        return NULL;

    int c = 0;
    struct node* cur = temp;
    struct node* next = NULL, * prev = NULL;

    while (cur != NULL && c < num)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        c++;
    }

    if (next != NULL)
        temp->next = reverse_group(next, num);

    return prev;
}
void int_point(struct node** st1, struct node** st2, struct node** l2)
{
    struct node* t1 = (*st1);
    create(&(*st2), &(*l2), 5);
    create(st2, l2, 45);
    (*l2)->next = t1->next->next;
    struct node* t2 = (*st2);
    int count1 = 0, count2 = 0;
    while (t1 != NULL)
    {
        count1++;
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        count2++;
        t2 = t2->next;
    }
    t1 = (*st1), t2 = (*st2);
    int d = (count1 >= count2 ? count1 - count2 : count2 - count1);
    if (count1 > count2)
    {
        while (d > 0)
        {
            t1 = t1->next;
            d--;
        }
    }
    else
    {
        while (d > 0)
        {
            t2 = t2->next;
            d--;
        }
    }
    struct node* start = NULL, * lt = NULL;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data == t2->data)
        {
            struct node* n = (struct node*)malloc(sizeof(struct node));
            n->data = t1->data;
            n->next = NULL;
            if (start == NULL)
            {
                start = n;
                lt = n;
            }
            else
            {
                lt->next = n;
                lt = n;
            }
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    struct node* temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void even_odd(struct node** start, struct node** lt)
{
    struct node* temp = (*start), * prev = NULL, * new_end = (*lt);
    while (temp != (*lt))
    {
        if (temp == (*start) && (temp->data) & 1)
        {
            struct node* t = temp;
            (*start) = temp->next;
            temp = temp->next;
            new_end->next = t;
            new_end = t;
            new_end->next = NULL;
        }
        else if (((temp->data) & 1) && temp != (*start))
        {
            struct node* t = temp;
            prev->next = temp->next;
            temp = temp->next;
            new_end->next = t;
            new_end = t;
            new_end->next = NULL;
        }
        else if (temp->data % 2 == 0)
        {
            prev = temp;
            temp = temp->next;
        }
    }
    (*lt) = new_end;
}
void checkcycle(struct node** start, struct node** lt)
{
    struct node* t1 = (*start);
    struct node* t2 = (*start);

    do
    {
        t1 = t1->next;
        t2 = t2->next->next;
    } while (t1 != t2 && t1 != NULL && t2->next != NULL);

    if (t1 == NULL || t2 == NULL)
        printf("\nThe loop not found. \n");
    else
        printf("\nThe loop found\n");
}

void kthNode(struct node** start, int k)
{
    struct node* ptr1 = *start;
    struct node* ptr2 = *start;
    struct node* ptr3 = *start;

    for (int i = 0; i < k - 1; i++)
        ptr1 = ptr1->next;
    ptr3 = ptr1;
    while (ptr3->next != NULL)
    {
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
    }
    int a = ptr2->data;
    ptr2->data = ptr1->data;
    ptr1->data = a;
}

void palindrome(struct node* start)
{
    int count = 0;
    struct node* temp = start;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    temp = start;
    int j = 0;
    int* arr = malloc(sizeof(int) * count);
    while (temp != NULL) {
        arr[j++] = temp->data;
        temp = temp->next;
    }
    int i = 0;
    while (i < count - i - 1) {
        if (arr[i] != arr[count - i - 1]) {
            printf("Not Palindrome");
            return;
        }
        i++;
    }
    printf("Palindrome");
}

void reverseEvenNodes(struct node** start)
{
    struct node* even = NULL;
    struct node* odd = *start;

    if (!odd || !odd->next || !odd->next->next)
        return;

    while (odd && odd->next) {

        struct node* temp = odd->next;
        odd->next = temp->next;
        temp->next = even;
        even = temp;
        odd = odd->next;
    }

    odd = *start;

    while (even) {

        struct node* temp = even->next;
        even->next = odd->next;
        odd->next = even;
        even = temp;
        odd = odd->next->next;
    }
}

void rotateList(struct node** start, struct node** end)
{
    int k;
    printf("Enter value of k to be rotated: ");
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        struct node* temp = *start;
        *start = temp->next;
        (*end)->next = temp;
        *end = temp;
        temp->next = NULL;
    }
}

void main()
{
    struct node* s1 = NULL, * l1 = NULL, * s2 = NULL, * l2 = NULL;
    int ch;
    while (1)
    {
        printf("\n\nMENU ");
        printf("\n1. Create List.");
        printf("\n2. Traverse through the List.");
        printf("\n3. Search, Delete, Insert");
        printf("\n4. Middle node ");
        printf("\n5. Reverse certain amount of elements ");
        printf("\n6. Check list is sorted or not");
        printf("\n7. Insert data in sorted list");
        printf("\n8. Find intersections");
        printf("\n9. All even before odd ");
        printf("\n10. Detect cycle ");
        printf("\n11. Swap kth node ");
        printf("\n12. Reverse group nodes ");
        printf("\n13. Check Palindrome ");
        printf("\n14. Reverse Even Position Nodes ");
        printf("\n15. Rotate Counter-Clockwise ");
        printf("\n16. Exit.\n");
        printf("\nEnter Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int num;
            printf("Enter the number to add to the list: ");
            scanf("%d", &num);
            create(&s1, &l1, num);
            break;
        }
        case 2:
            traverse(&s1);
            break;
        case 3:
        {
            int num;
            printf("Enter number: ");
            scanf("%d", &num);
            sea_del_ins(&s1, num);
            break;
        }
        case 4:
            middle(&s1);
            break;
        case 5:
        {
            int m;
            printf("Enter input: ");
            scanf("%d", &m);
            reverse_m(&s1, m);
            break;

        }
        case 6:
            checkSort(&s1);
            break;
        case 7:
        {
            int num;
            printf("Enter number: ");
            scanf("%d", &num);
            insert_ele_sort(&s1, num);
            break;
        }
        case 8:
            int_point(&s1, &s2, &l2);
            break;
        case 9:
            even_odd(&s1, &l1);
            break;
        case 10:
            checkcycle(&s1, &l1);
            break;
        case 11:
        {
            int num;
            printf("Enter the position: ");
            scanf("%d", &num);
            kthNode(&s1, num);
            break;
        }
        case 12:
        {
            int k;
            printf("Length of group: ");
            scanf("%d", &k);
            struct node* s3 = NULL;
            s3 = reverse_group(s1, k);
            traverse(&s3);
            break;
        }
        case 13:
            palindrome(s1);
            break;

        case 14:
            reverseEvenNodes(&s1);
            break;

        case 15:
            rotateList(&s1, &l1);
            break;

        case 16:
            exit(0);
        }

    }
}
