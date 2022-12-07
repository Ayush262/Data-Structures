#include<stdio.h>
#define max 5

void sort(int a[], int lb, int ub)
{
        int i=lb, j=ub, key=a[ub], t=0;
        if(lb>=ub)
                return;
        while(i<j)
        {
                while(key>=a[i])
                        i++;
                while(key<=a[j])
                        j--;
                if(i<j)
                {
                        t=a[i];
                        a[i]=a[j];
                        a[j]=t;
                }
        }
        a[lb]=a[j];
        a[j]=key;
        sort(a, lb, j-1);
        sort(a, j+1, ub);
}

void show(int a[])
{
        for(int i=0; i<max; i++)
                printf("%d\n",a[i]);
}

int main(){
    int a[max];
    int i;
    printf("Enter the elements in the array:");
    for(i=0;i<max;i++){
        scanf("%d",&a[i]);
    }
    show(a);
    sort(a, 0, max);
    show(a);
    return 0;
}
