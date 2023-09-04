/* Write a program in C to find GCD of two numbers using recursion. Read all pair of numbers from a file and store the result in a separate file. */

#include <stdio.h>
int gcd(int num1, int num2)
{

    if (num2 == 0)
    {
        return num1;
    }
    // Euclidean algorithm
    return gcd(num2, num1 % num2);
}

int main(int argc, char *argv[])
{
    FILE *sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL)
    {
        printf("Error opening the source file '%s'!\n", argv[1]);
        return 1;
    }

    FILE *destinationFile = fopen(argv[2], "w");
    if (destinationFile == NULL)
    {
        printf("Error opening the destination file '%s'!\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    int num1, num2;
    while (fscanf(sourceFile, "%d %d", &num1, &num2) == 2)
    {
        int result = gcd(num1, num2);

        // fprintf(destinationFile, "%d\n", result);
        fprintf(destinationFile, "The GCD of %d and %d is %d\n", num1,num2,result);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("GCD of the numbers are %s.\n", argv[2]);
    return 0;
}

