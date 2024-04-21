// Q7. WAP to add two distances (in km-m) by passing structure to a function

#include <stdio.h>
struct Distance
{
    int km;
    int meter;
};

void addDistance(struct Distance dist[])
{
    struct Distance result;
    result.km = dist[0].km + dist[1].km;
    result.meter = dist[0].meter + dist[1].meter;

    while (result.meter >= 1000)
    {
        result.meter = result.meter - 1000;
        result.km++;
    }
    printf("\nSum of distances = %d km %d m", result.km, result.meter);
}

int main()
{
    struct Distance dist[2];
    printf("Enter 1st distance\n");
    printf("Enter km: ");
    scanf("%d", &dist[0].km);
    printf("Enter meter: ");
    scanf("%d", &dist[0].meter);

    printf("\nEnter 2nd distance\n");
    printf("Enter km: ");
    scanf("%d", &dist[1].km);
    printf("Enter meter: ");
    scanf("%d", &dist[1].meter);

    addDistance(dist);

    return 0;
}

/*
#include <stdio.h>

struct Distance
{
    int km;
    float meter;
} d1, d2, result;

int main()
{
    printf("Enter 1st distance\n");
    printf("Enter km: ");
    scanf("%d", &d1.km);
    printf("Enter meter: ");
    scanf("%f", &d1.meter);

    printf("\nEnter 2nd distance\n");
    printf("Enter km: ");
    scanf("%d", &d2.km);
    printf("Enter meter: ");
    scanf("%f", &d2.meter);

    result.km = d1.km + d2.km;
    result.meter = d1.meter + d2.meter;

    while (result.meter >= 1000.0)
    {
        result.meter = result.meter - 1000.0;
        result.km++;
    }
    printf("\nSum of distances = %d km %.1f m", result.km, result.meter);
    return 0;
}
*/