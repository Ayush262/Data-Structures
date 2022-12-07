#include<stdio.h>
#define max 5

void sort(int a[])
{
    for(int i=1;i<=max-1;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    } 
}

void show(int a[])
{
    for(int i=0;i<max;i++)
        printf("%d ",a[i]); 
}
int main(){
    int a[max];
    int i,j,key;
    printf("Enter the elements in the array=");
    for(i=0;i<max;i++){
        scanf("%d",&a[i]);
    }
    show(a);
    sort(a);
    show(a);
    return 0;
}
