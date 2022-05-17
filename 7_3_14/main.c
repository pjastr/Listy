#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

void dodajw(struct element*Lista, struct element*elem, int a)
{
    struct element*wsk=malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=elem->next;
    elem->next=wsk;
}

void wyswietlListeZGlowa(struct element*Lista)
{
    struct element*temp=Lista->next;
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
    struct element* l1=malloc(sizeof(struct element));
    l1->next=malloc(sizeof(struct element));
    l1->next->i=5;
    l1->next->next=malloc(sizeof(struct element));
    l1->next->next->i=7;
    l1->next->next->next=malloc(sizeof(struct element));
    l1->next->next->next->i=-2;
    l1->next->next->next->next=NULL;
    wyswietlListeZGlowa(l1);
    dodajw(l1,l1->next->next,14);
    wyswietlListeZGlowa(l1);
    return 0;
}
