#include <stdio.h>
#include <string.h>


#define NELEMS(array) (sizeof(array) / sizeof(array[0]))


typedef struct Elem Elem;
struct Elem {
    char    *name;
    int     value;
};


Elem elems[] = {
    "AElig",    0x00c6,
    "Aacute",   0x00c1,
    "Acirc",    0x00c2,
    /* ... */
    "zeta",     0x03b6
};


/* lookup: binary search for name in tab; return index */
int lookup(char *name, Elem tab[], int ntab)
{
    int low, high, mid, cmp;

    low = 0;
    high = ntab - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        cmp = strcmp(name, tab[mid].name);

        if (cmp < 0)
            high = mid - 1;
        else if (cmp > 0)
            low = mid + 1;
        else
            /* found match */
            return mid;
    }

    return -1;  /* no match */
}


int main(int argc, char *argv[]) {
    int idx;

    printf("The table has %ld words\n", NELEMS(elems));
    idx = lookup("Acirc", elems, NELEMS(elems));
    printf("Found: %s\n", elems[idx].name);
    return 0;
}
