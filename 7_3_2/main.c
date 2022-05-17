#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element * utworz()
{
    return NULL;
};


// ta funkcja realizuje literalnie polecenie i jest procedura
// jednak sensowniej by przy usuwaniu ustawic wskaznik listy na NULL (ta funkcja tego nie robi)
void wyczysc(struct element *Lista)
{
    struct element * wsk=Lista;
    while(Lista!=NULL)
    {
        Lista=Lista->next;
        free(wsk);
        wsk=Lista;
    }
}

int main()
{
    struct element* example = utworz();
    wyczysc(example);
    return 0;
}
