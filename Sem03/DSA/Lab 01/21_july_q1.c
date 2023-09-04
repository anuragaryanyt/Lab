/*Q1. WAP to create an array that can store max. 50 integers and display the contents of the array.*/

#include <stdio.h>  
void  main()  
{  
    int arr[50]; 
    int i;  	

    printf("Input 50 elements in the array :\n");  
    for(i=0; i<50; i++)  
    {  
        scanf("%d", &arr[i]);  
    }  

    printf("\n Elements in array are: ");  
    for(i=0; i<50; i++)  
    {  
        printf("%d  ", arr[i]);  
    } 
}
