// Wap to check for palindrome using double ended queue.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define SIZE 5

char LeftPop(char q[5],int *front,int *rear)
{
    char t=q[*front];
    (*front)++;
    return t;
}

char RightPop(char q[5],int *front,int *rear)
{
    char t=q[*rear];
    (*rear)--;
    return t;
}

void main()
{
    char q[5];
    printf("Enter String: ");
    scanf("%s",q);

    int front=0,rear=strlen(q)-1;

    while(front!=rear)
    {
        if(LeftPop(q,&front,&rear) != RightPop(q,&front,&rear))
        {
            printf("Not a Palindrome");
            exit(0);
        }
    }
    printf("It is Palindrome");
}

