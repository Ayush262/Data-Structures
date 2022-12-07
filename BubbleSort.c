#include<stdio.h>
#define max 5

void sort(int a[])
{
    for(int i=0;i<max-1;i++)
    {
        for(int j=0;j<max-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void show()
{
    for(int i=0;i<max;i++)
        printf("%d",a[i]);
}
int main(){
    int a[max];
    int i,j,temp;
    printf("Enter the elements in the array:");
    for(i=0;i<max;i++){
        scanf("%d",&a[i]);
    }
    sort(a);
    
    return 0;
}
