#include<stdio.h>
void towerofhanoi(int n,char s,char d,char a)
{
    if(n==1);
    {
        printf("move the disk %d from %c to %c\n",n,s,d);
        return ;
    }
    towerofhanoi(n-1,s,a,d);
    printf("move the disk %d from %c to %c \n",n,s,d);
    towerofhanoi(n-1,a,d,s);
}
int main()
{
    int disk_count;
    printf("enter how many disks are there:\n");
    scanf("%d",&disk_count);
    printf("required move:\n");
    towerofhanoi(disk_count,'s','d','a');
}
