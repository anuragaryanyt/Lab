#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int arr[], int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && arr[index] < arr[parent])
    {
        swap(&arr[index], &arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}
void insertElement(int arr[], int *size, int value)
{
    if (*size == 0)
    {
        arr[0] = value;
        (*size)++;
        return;
    }

    if (*size >= 100)
    {
        printf("Heap is full.\n");
        return;
    }

    arr[*size] = value;
    (*size)++;
    heapifyUp(arr, *size - 1);
}
void heapify(int arr[], int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, size, smallest);
    }
}
void heapSort(int arr[], int size)
{
    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    // Extract elements one by one from the heap
    for (int i = size - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void pline(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("-");
    }
    printf("\n");
}
struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

struct person *createPerson(int id, const char *name, int age, int height, int weight)
{
    struct person *p = (struct person *)malloc(sizeof(struct person));
    p->id = id;
    p->name = strdup(name);
    p->age = age;
    p->height = height;
    p->weight = weight;
    return p;
}
int main()
{
    struct person **students = (struct person **)malloc(10 * sizeof(struct person *));
    FILE *file = fopen("data.txt", "r");
    for (int i = 0; i < 7; i++)
    {
        int id, age, height, weight;
        char name[100];
        fscanf(file, "%d %s %d %d %d", &id, name, &age, &height, &weight);
        students[i] = createPerson(id, name, age, height, weight);
    }
    fclose(file);

    int a[10];
    int w[10];

    int choice;
    while (1)
    {
        pline(40);
        printf("MAIN MENU (HEAP)\n");
        pline(40);
        printf("1.Read Data\n");
        printf("2.Create a Min-heap based on the age\n");
        printf("3.Create a Max-heap based on the weight\n");
        printf("4.Display weight of the youngest person\n");
        printf("5.Insert a new person into the Min-heap\n");
        printf("6.Delete the oldest person\n");
        printf("7.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("ID\tName\t\tAge\tHeight\tWeight\t\n");
            pline(47);
            for (int i = 0; i < 7; i++)
            {
                printf("%d\t%s\t%d\t%d\t%d\n", students[i]->id, students[i]->name, students[i]->age, students[i]->height, students[i]->weight);
            }
            break;
        }
        case 2:
        {
            int a[10];
            for (int i = 0; i < 7; i++)
            {
                a[i] = students[i]->age;
            }
            heapSort(a, 7);
            printf("Min-heap based on age: ");
            for (int i = 6; i >= 0; i--)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        }
        case 3:
        {
            int w[10];
            for (int i = 0; i < 7; i++)
            {
                w[i] = students[i]->weight;
            }
            heapSort(w, 7);
            printf("Max-heap based on weight: ");
            for (int i = 0; i < 7; i++)
            {
                printf("%d ", w[i]);
            }
            printf("\n");
            break;
        }
        case 4:
        {
            int wy;
            for (int i = 0; i < 7; i++)
            {
                a[i] = students[i]->age;
            }
            heapSort(a, 7);
            printf("Youngest age is: %d\n", a[6]);
            for (int i = 0; i < 7; i++)
            {
                if (students[i]->age == a[6])
                {
                    // printf("Correspondence ID: %d\n", students[i]->id);
                    wy = students[i]->weight;
                }
            }
            printf("Weight of the youngest person: %d\n", wy);
            break;
        }
        case 5:
        {
            // printf("Enter details of students:\n");
            // int num = 7;
            // for (int i = num; i < num + 1; i++)
            // {
            //     int id, age, height, weight;
            //     char name[100];
            //     scanf("%d", &id);
            //     scanf("%s", name);
            //     scanf("%d", &age);
            //     scanf("%d", &height);
            //     scanf("%d", &weight);
            //     students[i] = createPerson(id, name, age, height, weight);
            // }
            // for (int i = 0; i < 7+num; i++)
            // {
            //     printf("%d ", students[i]->age);
            // }
            // printf("\n");
            break;
        }
        case 6:
        {

            break;
        }
        default:
            break;
        }
        if (choice == 7)
        {
            break;
        }
    }
    printf("Exited!\n");
    for (int i = 0; i < 10; i++)
    {
        free(students[i]->name);
        free(students[i]);
    }
    free(students);

    return 0;
}

