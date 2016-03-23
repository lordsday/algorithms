#include <stdio.h>
#include <string.h>


typedef struct Node Node;
struct Node {
    char    *name;
    int     value;
    Node    *left;  /* lesser */
    Node    *right; /* greater */
};

/* insert: insert newp in treep, return treep */
Node *insert(Node *treep, Node *newp)
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
Node *lookup(Node *treep, char *name)
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
Node *nrlookup(Node *treep, char *name)
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

int main()
{
    Node records[5] = {
        {"AEling", 0x00c6, NULL, NULL},
        {"Aacute", 0x00c1, NULL, NULL},
        {"Acirc",  0x00c2, NULL, NULL},
        {"smiley", 0x263A, NULL, NULL},
        {"zeta",   0x03b6, NULL, NULL}
    };
    Node *treep = NULL;
    Node *node = NULL;
    int i;

    for (i = 0; i < 5; i++) {
        treep = insert(treep, &records[i]);
    }

    node = lookup(treep, "zeta");
    printf("%s\n", node->name);

    return 0;
}
