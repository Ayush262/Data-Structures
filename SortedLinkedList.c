#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int s, d, w;
    struct node *next;
}test;

void insert(test **R){
	test *p = (test*)malloc(sizeof(test));
	printf("Enter Source: ");
	scanf("%d", &p->s);
	printf("Enter Destination: ");
	scanf("%d", &p->d);
	printf("Enter Weight: ");
	scanf("%d", &p->w);
	p->next = NULL;
	*R = p;
}

void sort(test **h)
{
    int a, b, c;
    test *p = (test*)malloc(sizeof(test));
	printf("Enter Source: ");
	scanf("%d", &a);
	printf("Enter Destination: ");
	scanf("%d", &b);
	printf("Enter Weight: ");
	scanf("%d", &c);
	test *t;
	t=*h;
	if(((*h)->w)>c)
	{
	    p->s=a;
        p->d=b;
        p->w=c;
        p->next = *h;
        *h=p;
	}
	else
	{
	    while(t->w < c && t->next != NULL)
        t = t->next;
        p->s=a;
        p->d=b;
        p->w=c;
	    p->next = t->next;
        t->next=p;
	    t = p;
	}
}

void show(test *h)
{
    test *t = h;
    printf("Source to Destination - Weight\n");
    while(t != NULL)
    {
        printf("%d to %d - %d\n", t->s, t->d, t->w);
        t=t->next;
    }
}
int main()
{
    int n=0, flag=0;
    test *head;
    // printf("Creating First Node\n");
    // insert(&head);
    do{
        printf("1 Input\n2 Display\n3 exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                if(flag==0)
                {
                    insert(&head);
                    flag=1;
                }
                else
                    sort(&head);
                    break;
            case 2:
                show(head);
                break;
            case 3:
                n=-1;
                break;
        }
    }while(n!=-1);
    return 0;
}
