#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};


struct element* dodajw(struct element*Lista, struct element*elem, int a)
{
    struct element*wsk=malloc(sizeof(struct element));
    wsk->i=a;
    if (elem == NULL)
    {
        wsk->next=Lista;
        Lista=wsk;
    }
    else
    {
        wsk->next=elem->next;
        elem->next=wsk;
    }
    return Lista;
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
    struct element * l1=malloc(sizeof(struct element));
    l1->i=5;
    l1->next=malloc(sizeof(struct element));
    l1->next->i =-4;
    l1->next->next=NULL;
    wyswietlListeBezGlowy(l1);
    l1=dodajw(l1, NULL, 8);
    wyswietlListeBezGlowy(l1);
    l1=dodajw(l1, l1->next, -3);
    wyswietlListeBezGlowy(l1);
    return 0;
}
