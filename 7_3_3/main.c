#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element* dodaj(struct element*Lista, int a)
{
    struct element * wsk = malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=Lista;
    return wsk;
};

struct element * utworz()
{
    return NULL;
};

void wyswietlListeBezGlowy(struct element*Lista)
{
    struct element*temp=Lista;
    if(temp==NULL)
    {
        printf("Lista jest pusta\n");
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->i);
        temp=temp->next;
    }
    printf("----\n");
}

int main()
{
    struct element* l1 = utworz();
    l1 = dodaj(l1,2);
    l1 = dodaj(l1,4);
    l1 = dodaj(l1,7);
    l1 = dodaj(l1,-2);
    wyswietlListeBezGlowy(l1);
    struct element * l2=malloc(sizeof(struct element));
    l2->i=5;
    l2->next=NULL;
    l2=dodaj(l2,7);
    wyswietlListeBezGlowy(l2);
    return 0;
}
