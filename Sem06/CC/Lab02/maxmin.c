#include <stdio.h>
#include <limits.h>
int main()
{

    int T, M;
    printf("\nEnter number of machines and tasks\n");
    scanf(" %d %d", &M, &T);

    int maxMin[M][T];
    int tmp[M][T];

    printf("\nFill Data\n");
    for (int i = 0; i < M; i++)
        for (int j = 0; j < T; j++)
        {
            printf("[%d][%d] : ", i, j);
            scanf(" %d", &maxMin[i][j]);
            tmp[i][j] = maxMin[i][j];
        }

    // visualise data
    printf("\nOriginal Data\n");

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < T; j++)
            printf(" % d ", maxMin[i][j]);
        printf("\n");
    }

    int resultTask[T];
    int resultMachine[T];
    int resultTime[T];

    int ptr = -1;

    while (ptr < T - 1)
    {
        int time[T], machine[T];
        for (int j = 0; j < T; j++)
        {
            int minimum = INT_MAX;
            int pos = -1;
            for (int i = 0; i < M; i++)
            {
                if (maxMin[i][j] < minimum)
                {
                    minimum = maxMin[i][j];
                    pos = i;
                }
            }
            time[j] = minimum;
            machine[j] = pos;
        }

        int maximum = INT_MIN;
        int pos = -1;

        for (int j = 0; j < T; j++)
        {
            if (time[j] > maximum && time[j] != INT_MAX)
            {
                maximum = time[j];
                pos = j;
            }
        }

        resultTask[++ptr] = pos;
        resultMachine[ptr] = machine[pos];
        resultTime[ptr] = tmp[machine[pos]][pos];

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < T; j++)
            {
                if (j == resultTask[ptr])
                    maxMin[i][j] = INT_MAX;
                else if (i == resultMachine[ptr] && maxMin[i][j] != INT_MAX)
                    maxMin[i][j] += maximum;
                else
                    continue;
            }
        }
    }

    printf("\nScheduled Task are : \n");
    for (int i = 0; i < T; i++)
    {
        printf("\nTask % d Runs on Machine % d with Time % d units\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
    }

    // printf("\nTotal elapsed time : % d units\n", makespan);
    return 0;
}
