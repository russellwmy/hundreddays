#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int stream[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", stream[i]);
    printf("\n");
}

void select_k_items(int stream[], int n, int k)
{
    int i; // index for elements in stream[]
    int reservoir[k];
    for (i = 0; i < k; i++)
        reservoir[i] = stream[i];
    srand(time(NULL));

    for (; i < n; i++)
    {
        int j = rand() % (i + 1);
        if (j < k)
            reservoir[j] = stream[i];
    }

    printf("Following are k randomly selected items \n");
    print_array(reservoir, k);
}