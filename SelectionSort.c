#include<stdio.h>
#define max 5

void sort(int a[])
{
        int j,i;
        for(i=0; i<max; i++)
        {
                int t=i;
                for(j=i+1; j<max; j++)
                {
                        if(a[j]<a[t])
                                t=j;
                }
                int temp= a[i];
                a[i]=a[t];
                a[t]=temp;
        }
}

void show(int a[])
{
        for(int i=0; i<max; i++)
                printf("%d\n",a[i]);
}

int main(){
    int a[max];
    int i,j,temp;
    printf("Enter the elements in the array:");
    for(i=0;i<max;i++){
        scanf("%d",&a[i]);
    }
    show(a);
    sort(a);
    show(a);
    return 0;
}
