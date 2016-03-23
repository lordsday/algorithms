#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Item Item;
struct Item {
    char *name;
    int value;
    Item *next;  /* in list */
};

/* newitem: create new item from name and value */
Item *newitem(char *name, int value)
{
    Item *newp;
    newp = (Item *)malloc(sizeof(Item));
    newp->name = name;
    newp->value = value;
    newp->next = NULL;
    return newp;
}

/* addfront: add newp to front of listp */
Item *addfront(Item *listp, Item *newp)
{
    newp->next = listp;
    return newp;
}

/* addend: add newp to end of listp */
Item *addend(Item *listp, Item *newp)
{
    Item *p;
    if (listp == NULL)
        return newp;
    for (p = listp; p->next != NULL; p = p->next)
        ;
    p->next = newp;
    return listp;
}

/* lookup: sequential search for name in listp */
Item *lookup(Item *listp, char *name)
{
    for ( ; listp != NULL; listp = listp->next)
        if (strcmp(name, listp->name) == 0)
            return listp;
    return NULL;  /* no match */
}

/* freeall: free all elements of listp */
void freeall(Item *listp)
{
    Item *next;

    for ( ; listp != NULL; listp = next) {
        next = listp->next;
        /* assumes name is freed elsewhere */
        free(listp);
    }
}

/* delitem: delete first "name" from listp */
Item *delitem(Item *listp, char *name)
{
    Item *p, *prev;

    prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (strcmp(name, p->name) == 0) {
            if (prev == NULL)
                listp = p->next;
            else
                prev->next = p->next;
            free(p);
            return listp;
        }
        prev = p;
    }
    printf("delitem: %s not in list", name);
    return NULL;  /* can't get here */
}

/* apply: execute fn for each element of listp */
void apply(Item *listp, void (*fn)(Item*, void*), void *arg)
{
    for ( ; listp != NULL; listp = listp->next)
        (*fn)(listp, arg); /* call the function */
}

/* printnv: print name and value using format in arg */
void printnv(Item *p, void *arg)
{
    char *fmt;

    fmt = (char *) arg;
    printf(fmt, p->name, p->value);
}

int main(int argc, char *argv[])
{
    Item *list = newitem("a", 1);

    list = addend(list, newitem("b", 2));
    list = addend(list, newitem("c", 3));
    list = addend(list, newitem("d", 4));

    apply(list, printnv, "%s: %x\n");

    return 0;
}
