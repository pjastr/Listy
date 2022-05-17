#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element* dodajk(struct element*Lista, int a)
{
    struct element * wsk ;
    if(Lista==NULL)
    {
        wsk=malloc(sizeof(struct element));
        Lista=wsk;
    }
    else
    {
        wsk=Lista;
        while(wsk->next!=NULL)
        {
            wsk=wsk->next;
        }
        wsk->next=malloc(sizeof(struct element));
        wsk=wsk->next;
    }
    wsk->i=a;
    wsk->next=NULL;
    return Lista;
}

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
    struct element * l1=NULL;
    l1=dodajk(l1,7);
    wyswietlListeBezGlowy(l1);
    struct element * l2=malloc(sizeof(struct element));
    l2->i=5;
    l2->next=NULL;
    l2=dodajk(l2,7);
    wyswietlListeBezGlowy(l2);
    return 0;
}
