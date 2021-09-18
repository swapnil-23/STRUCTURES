//q3 structure with pointers

#include <stdio.h>
#include <conio.h>
#include <string.h>
struct student
{
    char name[30];
    int prn;
    float perc;

};

int count=0;

void create(struct student *a);
void insert(struct student *a);
void modify(struct student *a);
void Delete(struct student *a);
void display(struct student *a);

int main()
{
    struct student stu[10];
    int n , ch;
    do
    {

	printf("\nMAIN DATABASE");
	printf("\n 1.Create");
    printf("\n 2.Insert");
    printf("\n 3.Modify");
    printf("\n 4.Delete");
    printf("\n 5.Display");

    printf("\nenter the choice number==> ");
    scanf("%d" , &n);

    switch(n)
    {
        case 1:
        create(stu);
        break;

        case 2:
        insert(stu);
        break;

        case 3:
        modify(stu);
        break;

        case 4:
        Delete(stu);
        break;

        case 5:
        display(stu);
        break;

        default:
        printf("wrong choice");
    }

    printf("\n Do you want to continue(0/1)==>");
    scanf("%d", &ch);
    }
    while(ch!=0);
}
void create(struct student *a)
{
    int x ,i;
    printf("Enter the number of the records you want to enter:\n==>");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        printf("Enter the name prn and percentage:\n");
        scanf("%s",(a+i)->name);
        scanf("%d",&(a+i)->prn);
        scanf("%f",&(a+i)->perc);
        count++;
    }

}
void insert(struct student *a)
{
    int x,i;
    printf("Enter the number of the records you want to insert:\n==>");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        printf("Enter the name prn and percentage:\n");
        scanf("%s",a[count].name);
        scanf("%d",&a[count].prn);
        scanf("%f",&a[count].perc);
        count++;
    }

}
void Delete(struct student *a)
{
    char name[30],i;
    printf("Enter the name of which you want to delete the entry:\n==>");
    scanf("%s",name);
    for (i=0;i<count;i++)
    {
        if (!strcmp(name,(a+i)->name))
        {
            while(i<count)
            {
                a[i]=a[i+1];
                i++;
            }
        }
    }
    printf("Deleted!!\n");
    count--;
}
void modify(struct student *a)
{
    char stname[30];
    int stprn;
    float stperc;
    int i;
    printf("Enter the student's name you want to modify\n==>");
    scanf("%s",stname);
    printf("\nNew prn\n==>");
    scanf("%d", &stprn);
    printf("\nNew percentage\n==>");
    scanf("%f", &stperc);
    for (i=0;i<count;i++)
    {
        if (!strcmp(stname,(a+i)->name)) //string comparison
        {
            (a+i)->prn = stprn;
            (a+i)->perc = stperc;
        }

    }

}
void display(struct student *a)
{
	int i;
    for (i =0;i<count;i++)
    {
        printf("\nName: %s\t",(a+i)->name);
        printf("PRN: %d \t",(a+i)->prn);
        printf("Percentage: %f\t",(a+i)->perc);
        printf("\n");

    }
}