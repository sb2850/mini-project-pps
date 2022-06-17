#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

void insert();
void search();
void update();
void delete ();

struct bs
{
    int bookCode;
    int issueDate;
    int returnDate;
    char authName[20];
    char bookName[20];
    int price;
};
struct bs b;

int main()
{
    int a;
    while (a != 4)
    {
        printf("\t**********************************\n");
        printf("\t'WELCOME TO LIBRARY DATABASE'\n");
        printf("\t**********************************\n\n\n");

        printf("\t****What would you like to do?****\n\n");
        printf("\t~1: Insert BOOK RECORD~\n");
        printf("\t~2: Search BOOK RECORD~\n");
        printf("\t~3: Update BOOK RECORD~\n");
        printf("\t~4: Exit~\n\n");
        printf("\tEnter Your CHOICE : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            system("cls");
            insert(); // calling the function
            break;
        case 2:
            system("cls");
            search();
            break;
        case 3:
            system("cls");
            update();
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("\n\t\t!!! You Entered The Wrong choice !!!\n\n");
            // it is a menu driven program
        }
        getchar(); // again go to the loop
    }

    return 0;
}

void insert()
{
    FILE *fp;
    fp = fopen("book.txt", "a+");
    printf("\n\n\t~~~ENTER NEW BOOK~~~");
    printf("\n\n\tEnter BOOK Code : ");
    scanf("%d", &b.bookCode);

    printf("\n\tEnter issue date : ");
    scanf("%d", &b.issueDate);

    printf("\n\tEnter return date : ");
    scanf("%d", &b.returnDate);
    fflush(stdin);

    printf("\n\tEnter Author name : ");
    gets(b.authName);

    printf("\n\tEnter Book Name : ");
    gets(b.bookName);

    printf("\n\tEnter Price : ");
    scanf("%d", &b.price);

    fwrite(&b, sizeof(b), 1, fp);
}
void search()
{
    int code, flag = 0;

    FILE *fp;
    fp = fopen("book.txt", "r");

    if (fp == NULL)
    {
        printf("\n\t\tError : File Does Not Exist !!! ");
        return;
    }

    printf("\n\n\tEnter Book Code To Search : ");
    scanf("%d", &code);
    while (fread(&b, sizeof(b), 1, fp) > 0 && flag == 0)
    {
        if (b.bookCode == code)
        {
            flag = 1;
            printf("\n\tSearch Sucessfull And book Details Is as follows");
            printf("\n\n\tBook code\tIssue Date\treturn Date\tauthor Name\tbook Name\t\tPrice\n");
            printf("\t%d\t\t%d\t\t%d\t\t%s\t\t%s\t\t\t%d\n\n\n", b.bookCode, b.issueDate, b.returnDate, b.authName, b.bookName, b.price);
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\t!!! No Record Found !!!\n\n");
    }
    fclose(fp);
}
void update()
{
    int code, flag = 0;

    FILE *fp;
    fp = fopen("book.txt", "r+");
    if (fp == NULL)
    {
        printf("\n\t\tError : File Does Not Exist");
        return;
    }

    printf("\n\n\tEnter book Code of the book  To Update : ");
    scanf("%d", &code);

    printf("\n\n\t\t *** Previously log Details for the book Code ***\n");
    while (fread(&b, sizeof(b), 1, fp) > 0 && flag == 0)
    {
        if (b.bookCode == code)
        {
            flag = 1;
            printf("\n\n\tBook code\tIssue Date\treturn Date\tauthor Name\tbook Name\t\tPrice\n");
            printf("\t%d\t\t%d\t\t%d\t\t%s\t\t%s\t\t\t%d\n\n", b.bookCode, b.issueDate, b.returnDate, b.authName, b.bookName, b.price);

            printf("\n\t\t*** Update the book Details ***\n\n");
            printf("\n\tEnter Book Code : ");
            scanf("%d", &b.bookCode);

            printf("\n\tEnter Issue Date : ");
            scanf("%d", &b.issueDate);

            printf("\n\tEnter return Date : ");
            scanf("%d", &b.returnDate);
            fflush(stdin);

            printf("\n\tEnter Author Name : ");
            gets(b.authName);

            printf("\n\tEnter Book Name : ");
            gets(b.bookName);

            printf("\n\tEnter Price : ");
            scanf("%d", &b.price);

            fseek(fp, -(long)sizeof(b), 1);

            fwrite(&b, sizeof(b), 1, fp);
            printf("\n\n\t\tDetails Updated\n\n\n");
        }
    }
    if (flag == 0)
    {
        printf("\n\t\tError : Something Went Wrong !!!\n\n");
    }
    fclose(fp);
}