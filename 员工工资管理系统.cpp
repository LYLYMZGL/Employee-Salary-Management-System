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
    printf ("\t\t##          ��ӭ����Ա�����ʹ���ϵͳ��               ##\n");
    printf ("\t\t##              1.¼��Ա����Ϣ                       ##\n");
    printf ("\t\t##              2.��Ա�����ʽ�������                 ##\n");
    printf ("\t\t##              3.�ļ����浽Ӳ����                   ##\n");
    printf ("\t\t##              4.��ѯԱ����Ϣ                       ##\n");
    printf ("\t\t##              5.�޸�Ա����Ϣ                       ##\n");
    printf ("\t\t##              6.�鿴����Ա����Ϣ                   ##\n");
    printf ("\t\t##              7.ɾ��Ա����Ϣ                       ##\n");
    printf ("\t\t##              8.�˳�����                           ##\n");
    printf ("\t\t##                                                   ##\n");
    printf ("\t\t##              ��ѡ���Ӧ�ı�ţ�1��8��             ##\n");
    printf ("\t\t#######################################################\n");
}
void input(WOK *a,int *n)
{
    WOK *p;
    int n1;
    system("cls");
    printf("\n������Ա����������");
    scanf("%d",&n1);
    printf("\n\t\t**********************");
    printf("\n\t\t*   ����  ����  ����   *\n");
    printf("\t\t**********************\n");
    for(p=a+(*n);p<a+(n1)+(*n); p++)
    {
        printf("\t\t   ");
        scanf("%d%s%f",&p->num,p->name,&p->salary);
    }
    *n=*n+n1;
    printf("\n����������أ���");
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
    printf("\n�������ǣ�\n");
    printf("����\t����\t����\t\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t%s\t%.1f\t\n",a[i].num,a[i].name,a[i].salary);
    }
    printf("\n����������أ�");
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
    printf("\n����ɹ���");
    printf("\n����������أ�");
    getch();
}
void find(WOK *a,int n)
{
    int k=0;
    int m;
    WOK *p;
    system("cls");
    printf("\n������Ҫ��ѯ�Ĺ��ţ�");
    scanf("%d",&m);
    for(p=a; p<a+n; p++)
    {
        if(m==p->num)
        {
            k=1;
            printf("���ҵ���Ա����������ϢΪ��\n");
	    printf("\t����\t����\t����\n");
            printf("\t%d\t%s\t%.1f\n",p->num,p->name,p->salary);
            break;
        }
    }
    if(!k)
        printf("�Ҳ�����ѯ��Ա����\n");
    printf("\n����������أ���");
    getch();
}
void modify(WOK *a,int *n)
{
    WOK *p;
    int k=0;
    int m;
    system("cls");
    printf("\n������Ҫ�޸ĵ�Ա����ţ�");
    scanf("%d",&m);
    for(p=a; p<a+*n; p++)
    {
        if(m==p->num)
        {
            k=1;
            scanf("%d%s%f",&p->num,p->name,&p->salary);
            printf("��Ϣ�޸ĳɹ�\n");
            break;
        }
    }
    if(!k)
        printf("�Ҳ���Ҫ�޸ĵ�Ա����\n");
    printf("�����������\n");
    getch();
}
void display(WOK *a,int n)
{
    WOK *p;
    system("cls");
    printf("\t����\t����\t����\n");
    for(p=a; p<a+n; p++)
    {
        printf("\t%d\t%s\t%.1f\n",p->num,p->name,p->salary);
        printf("\n");
    }
    printf("\n����������أ���");
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
    printf("\n������Ҫɾ���Ĺ��ţ�");
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
            printf("ɾ���ɹ���\n");
            break;
        }
    }
    if(!k)
        printf("�Ҳ���Ҫɾ����Ա����\n");
    printf("\n����������أ���");
    getch();
}
int main()
{
    int j,num=0;
    WOK wok[SIZE];
    Sleep(500);//ʱ���ӳ�500����
    printf("\n\n\n\n\n\t\t\t\tϵͳ�����У����Ժ�");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t�������");
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
            printf("����������������룡\n");
        }
    }
    return 0;
}


