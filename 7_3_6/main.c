#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element*znajdz(struct element*Lista, int a)
{
    while((Lista!=NULL)&&(Lista->i!=a))
    {
        Lista=Lista->next;
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
    l1->next->next=malloc(sizeof(struct element));
    l1->next->next->i=9;
    l1->next->next->next=NULL;
    wyswietlListeBezGlowy(l1);
    printf("%p\n", l1->next);
    printf("%p\n",znajdz(l1,-4));
    printf("%p\n",znajdz(l1,11));
    return 0;
}
