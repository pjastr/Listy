#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element* usun(struct element* Lista, int a)
{
    if (Lista==NULL)
        return Lista;
    struct element*wsk,*wsk2;
    wsk=Lista;
    if (Lista->i==a)
    {
        Lista=Lista->next;
        free(wsk);
    }
    else
    {
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
    usun(l1,-4);
    wyswietlListeBezGlowy(l1);
    usun(l1,33);
    wyswietlListeBezGlowy(l1);
    return 0;
}
