#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define SIZE 100
typedef struct
{
    int num;
    char name[20];
    float salary;
} WOK;
void menu()
{
    printf ("\n\n\n\t\t#######################################################\n");
    printf ("\t\t##          欢迎进入员工工资管理系统：               ##\n");
    printf ("\t\t##              1.录入员工信息                       ##\n");
    printf ("\t\t##              2.对员工工资进行排序                 ##\n");
    printf ("\t\t##              3.文件保存到硬盘上                   ##\n");
    printf ("\t\t##              4.查询员工信息                       ##\n");
    printf ("\t\t##              5.修改员工信息                       ##\n");
    printf ("\t\t##              6.查看所有员工信息                   ##\n");
    printf ("\t\t##              7.删除员工信息                       ##\n");
    printf ("\t\t##              8.退出程序                           ##\n");
    printf ("\t\t##                                                   ##\n");
    printf ("\t\t##              请选择对应的编号（1—8）             ##\n");
    printf ("\t\t#######################################################\n");
}
void input(WOK *a,int *n)
{
    WOK *p;
    int n1;
    system("cls");
    printf("\n请输入员工的人数：");
    scanf("%d",&n1);
    printf("\n\t\t**********************");
    printf("\n\t\t*   工号  姓名  工资   *\n");
    printf("\t\t**********************\n");
    for(p=a+(*n);p<a+(n1)+(*n); p++)
    {
        printf("\t\t   ");
        scanf("%d%s%f",&p->num,p->name,&p->salary);
    }
    *n=*n+n1;
    printf("\n按任意键返回！！");
    getch();

}
void sort(WOK *a,int n)
{
    int i,j;
    WOK t;
    system("cls");
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if((a[j].salary)<(a[j+1].salary))
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("\n排序结果是：\n");
    printf("工号\t姓名\t工资\t\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t%s\t%.1f\t\n",a[i].num,a[i].name,a[i].salary);
    }
    printf("\n按任意键返回！");
    getch();
}
void save(WOK *a,int n)
{
    FILE *fp;
    WOK *p;
    int i;
    fp=fopen("c:\\woker.txt","w");
    for(p=a; p<a+n; p++)
    {
        fprintf(fp,"%10d%10s%10.1f\n",p->num,p->name,p->salary);
        printf("\n");
    }
    fclose(fp);
    printf("\n保存成功！");
    printf("\n按任意键返回！");
    getch();
}
void find(WOK *a,int n)
{
    int k=0;
    int m;
    WOK *p;
    system("cls");
    printf("\n请输入要查询的工号：");
    scanf("%d",&m);
    for(p=a; p<a+n; p++)
    {
        if(m==p->num)
        {
            k=1;
            printf("已找到该员工，具体信息为：\n");
	    printf("\t工号\t姓名\t工资\n");
            printf("\t%d\t%s\t%.1f\n",p->num,p->name,p->salary);
            break;
        }
    }
    if(!k)
        printf("找不到查询的员工！\n");
    printf("\n按任意键返回！！");
    getch();
}
void modify(WOK *a,int *n)
{
    WOK *p;
    int k=0;
    int m;
    system("cls");
    printf("\n请输入要修改的员工编号：");
    scanf("%d",&m);
    for(p=a; p<a+*n; p++)
    {
        if(m==p->num)
        {
            k=1;
            scanf("%d%s%f",&p->num,p->name,&p->salary);
            printf("信息修改成功\n");
            break;
        }
    }
    if(!k)
        printf("找不到要修改的员工！\n");
    printf("按任意键继续\n");
    getch();
}
void display(WOK *a,int n)
{
    WOK *p;
    system("cls");
    printf("\t工号\t姓名\t工资\n");
    for(p=a; p<a+n; p++)
    {
        printf("\t%d\t%s\t%.1f\n",p->num,p->name,p->salary);
        printf("\n");
    }
    printf("\n按任意键返回！！");
    getch();
}
void read(WOK *a,int *n)
{
    FILE *fp;
    WOK *p;
    int i;
    fp=fopen("c:\\woker.txt","r");
    for(p=a; fscanf(fp,"%d%s%f",&p->num,p->name,&p->salary)!=EOF; p++)
    {
        *n=*n+1;
        printf("\n");
    }
    fclose(fp);
}
void del(WOK *a,int *n)
{
    int i,j,k=0;
    WOK *p;
    float num;
    system("cls");
    printf("\n请输入要删除的工号：");
    scanf("%f",&num);
    for(i=0,p=a; p<a+*n; i++)
    {
        if(num==(p+i)->num)
        {
            k=1;
            for(j=i; j<*n-1; j++)
            {
                *(a+j)=*(a+j+1);
            }
            (*n)--;
            printf("删除成功！\n");
            break;
        }
    }
    if(!k)
        printf("找不到要删除的员工！\n");
    printf("\n按任意键返回！！");
    getch();
}
int main()
{
    int j,num=0;
    WOK wok[SIZE];
    Sleep(500);//时间延迟500毫秒
    printf("\n\n\n\n\n\t\t\t\t系统加载中，请稍侯");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t加载完成");
    Sleep(500);
    read(wok,&num);
    while(1)
    {
        system("cls");
        menu();
        scanf("%d",&j);
        switch(j)
        {
        case 1:
            input(wok,&num);
            break;
        case 2:
            sort(wok,num);
            break;
        case 3:
            save(wok,num);
            break;
        case 4:
            find(wok,num);
            break;
        case 5:
            modify(wok,&num);
            break;
        case 6:
            display(wok,num);
            break;
        case 7:
            del(wok,&num);
            break;
        case 8:exit(0);
        default:
            printf("输入错误，请重新输入！\n");
        }
    }
    return 0;
}


