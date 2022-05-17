#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element * znajdz(struct element* Lista, int a)
{
    Lista=Lista->next;
    while((Lista!=NULL)&&(Lista->i!=a))
    {
        Lista=Lista->next;
    }
    return Lista;
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
    printf("%p\n",l1->next->next->next);
    printf("%p\n",znajdz(l1,-2));
    return 0;
}
