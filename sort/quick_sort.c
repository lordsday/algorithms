#include <stdio.h>
#include <stdlib.h>

/* swap:  interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* quicksort: sort v[0]..v[n-1] into increasing order */
void quicksort(int v[], int n)
{
    int i, last;

    if (n <= 1)  /* nothing to do */
        return;
    swap(v, 0, rand() % n);   /* move pivot elem to v[0] */
    last = 0;
    for (i = 1; i < n; i++)   /* partition */
        if (v[i] < v[0])
            swap(v, ++last, i);
    swap(v, 0, last);         /* restore pivot */
    quicksort(v, last);       /* recursively sort */
    quicksort(v+last+1, n-last-1); /*   each part */
}

int main(int argc, char *argv[])
{
    int v[] = {7, 8, 9, 10, 3, 1, 4, 2, 5, 6};
    int len;
    int i;

    len = sizeof(v)/sizeof(int);
    printf("size: %d\n", len);
    quicksort(v, len);

    for (i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
    puts("");

    return 0;
}
