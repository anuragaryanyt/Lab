/* Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. Store the binary value in a separate disc file. */

#include <stdio.h>

void decimalToBinary(int decimalNum, FILE *outputFile) {

    if (decimalNum == 0) {
        fprintf(outputFile, "0");
        return;
    }

    decimalToBinary(decimalNum / 2, outputFile);
    fprintf(outputFile, "%d", decimalNum % 2);
}

int main() {

    const char inputFilePath[] = "input_file.dat";
    const char outputFilePath[] = "output_file.dat";

    FILE *inputFile = fopen(inputFilePath, "r");
    FILE *outputFile = fopen(outputFilePath, "w");

    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int decimalNum;
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &decimalNum);
        decimalToBinary(decimalNum, outputFile);
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion done at %s :\n", outputFilePath);
    return 0;
}



