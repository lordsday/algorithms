#include <stdio.h>
#include <string.h>


typedef struct Nameval Nameval;
struct Nameval {
    char    *name;
    int     value;
    Nameval *left;  /* lesser */
    Nameval *right; /* greater */
};

/* insert: insert newp in treep, return treep */
Nameval *insert(Nameval *treep, Nameval *newp)
{
    int cmp;

    if (treep == NULL)
        return newp;
    cmp = strcmp(newp->name, treep->name);
    if (cmp == 0)
        printf("insert: duplicate entry %s ignored",
                 newp->name);
    else if (cmp < 0)
        treep->left = insert(treep->left, newp);
    else
        treep->right = insert(treep->right, newp);
    return treep;
}

/* lookup: look up name in tree treep */
Nameval *lookup(Nameval *treep, char *name)
{
    int cmp;

    if (treep == NULL)
        return NULL;
    cmp = strcmp(name, treep->name);
    if (cmp == 0)
        return treep;
    else if (cmp < 0)
        return lookup(treep->left, name);
    else
        return lookup(treep->right, name);
}

/* nrlookup: non-recursively look up name in tree treep */
Nameval *nrlookup(Nameval *treep, char *name)
{
    int cmp;

    while (treep != NULL) {
        cmp = strcmp(name, treep->name);
        if (cmp == 0)
            return treep;
        else if (cmp < 0)
            treep = treep->left;
        else
            treep = treep->right;
    }
    return NULL;
}


/* int main(int argc, char *argv[]) { */
int main() {
    Nameval records[5] = {
        {"AEling", 0x00c6, NULL, NULL},
        {"Aacute", 0x00c1, NULL, NULL},
        {"Acirc",  0x00c2, NULL, NULL},
        {"smiley", 0x263A, NULL, NULL},
        {"zeta",   0x03b6, NULL, NULL}
    };
    Nameval *treep = NULL;
    Nameval *value = NULL;
    int i;

    for (i = 0; i < 5; i++) {
        treep = insert(treep, &records[i]);
    }

    value = lookup(treep, "zeta");
    printf("%s\n", value->name);

    return 0;
}
