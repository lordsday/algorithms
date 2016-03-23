#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Item Item;
struct Item {
    char    *name;
    int     value;
};

struct NVtab {
    int     nval; /* current number of values */
    int     max; /* allocated number of values */
    Item *nameval; /* array of name-value pairs */
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };

/* addname: add new name and value to nvtab */
int addname(Item newname)
{
    Item *nvp;

    if (nvtab.nameval == NULL) { /* first time */
        nvtab.nameval =
            (Item *)malloc(NVINIT * sizeof(Item));
        if (nvtab.nameval == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) { /* grow */
        nvp = (Item *)realloc(nvtab.nameval,
                                 (NVGROW*nvtab.max) * sizeof(Item));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

/* delname: remove first matching nameval from nvtab */
int delname(char *name)
{
    int i;
    for (i = 0; i < nvtab.nval; i++)
        if (strcmp(nvtab.nameval[i].name, name) == 0) {
            memmove(nvtab.nameval+i, nvtab.nameval+i+1,
                    (nvtab.nval-(i+1)) * sizeof(Item));
            nvtab.nval--;
            return 1;
        }
    return 0;
}

int main(int argc, char *argv[])
{
    Item item;

    item.name = "a";
    item.value = 1;
    addname(item);
    return 0;
}
