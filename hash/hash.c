#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

typedef struct Item Item;
struct Item {
    char    *name;
    int     value;
    Item    *next; /* in chain */
};

#define NHASH   10
Item *symtab[NHASH]; /* a symbol table */

enum { MULTIPLIER = 31 };

/* hash: compute hash value of string */
unsigned int hash(char *str)
{
    unsigned int h;
    unsigned char *p;

    h = 0;
    for (p = (unsigned char *) str; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    return h % NHASH;
}

/* lookup: find name in symtab, with optional create */
Item* lookup(char *name, int create, int value)
{
    int h;
    Item *sym;

    h = hash(name);
    for (sym = symtab[h]; sym != NULL; sym = sym->next)
        if (strcmp(name, sym->name) == 0)
            return sym;

    if (create) {
        sym = (Item *)malloc(sizeof(Item));
        sym->name = name; /* assumed allocated elsewhere */
        sym->value = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }

    return sym;
}

Item* additem(char *name, int value)
{
    Item *sym;
    int h;

    h = hash(name);

    sym = (Item *)malloc(sizeof(Item));
    sym->name = name; /* assumed allocated elsewhere */
    sym->value = value;
    sym->next = symtab[h];
    symtab[h] = sym;

    return sym;
}

void init()
{
    int i;
    for (i = 0; i < NELEMS(symtab); i++) {
        symtab[i] = NULL;
    }
}

void final()
{
    int i;
    for (i = 0; i < NELEMS(symtab); i++) {
        if (symtab[i]) free(symtab[i]);
    }
}

int main(int argc, char *argv[]) {
    Item *sym;

    init();

    additem("a", 1);
    additem("b", 2);
    additem("c", 3);
    additem("d", 4);
    additem("e", 5);

    sym = lookup("c", 0, 1);
    printf("Found: %s\n", sym->name);

    final();

    return 0;
}
