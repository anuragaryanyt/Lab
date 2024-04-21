#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};
void heapify(struct Item arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;
    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;
    if (largest != i)
    {
        struct Item temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(struct Item arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        struct Item temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
void fractionalKnapsack(struct Item items[], int n, double capacity)
{
    heapSort(items, n);
    double total_profit = 0.0;
    double knapsack[n];
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].item_weight)
        {
            knapsack[items[i].item_id - 1] = 1.0;
            capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
        }
        else
        {
            double fraction = capacity / items[i].item_weight;
            knapsack[items[i].item_id - 1] = fraction;
            total_profit += items[i].item_profit * fraction;
            break;
        }
    }
    printf("Item No\tprofit\tWeight\tAmount to be taken\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, knapsack[items[i].item_id - 1]);
    }
    printf("Maximum profit : %.6f\n", total_profit);
}
int main()
{
    int num_items;
    printf("Enter the number of items : ");
    scanf("%d", &num_items);
    struct Item items[num_items];
    for (int i = 0; i < num_items; i++)
    {
        printf("Enter the profit and weight of item no %d : ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }
    double capacity;
    printf("Enter the capacity of knapsack : ");
    scanf("%lf", &capacity);
    fractionalKnapsack(items, num_items, capacity);
    return 0;
}