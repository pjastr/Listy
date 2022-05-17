#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

void usun(struct element* Lista, int a)
{
    struct element*wsk=Lista;
    struct element*wsk2;
    while((wsk->next!=NULL)&&(wsk->next->i!=a))
    {
        wsk=wsk->next;
    }
    if(wsk->next!=NULL)
    {
        wsk2=wsk->next;
        wsk->next=wsk2->next;
        free(wsk2);
    }
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
    usun(l1,-2);
    wyswietlListeZGlowa(l1);
    usun(l1,5);
    wyswietlListeZGlowa(l1);
    usun(l1,7);
    wyswietlListeZGlowa(l1);
    return 0;
}
