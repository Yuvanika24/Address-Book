#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

void admin_options();
int front_page();

void empty_stdin (void)
{
    int c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
}

struct data
{
    char name[25];
    char address[50];
    char phone[11];
    char profession[25];
    char blood[6];
};
struct node
{
    struct data d1;
    struct node *next,*prev,*last;
};

struct node *head=NULL,*head1=NULL,*tail=NULL;

struct node *first =NULL,*last = NULL;

struct node *merge(struct node *p1, struct node *p2)
{
    struct node **pp;
    pp = &head;
    for (;;)
	{
        if (strcmp(p1->d1.name, p2->d1.name) <= 0)
		{
            *pp = p1;
            pp = &p1->next;
            p1 = p1->next;
            if (p1 == NULL)
			{
                *pp = p2;
                break;
            }
        }
		else
		{
            *pp = p2;
            pp = &p2->next;
            p2 = p2->next;
            if (p2 == NULL)
			{
                *pp = p1;
                break;
            }
        }
    }
    return head;
}
struct node *msort(struct node *np)
{
    struct node *p1, *p2;

    if (np == NULL || np->next == NULL)
        return np;

    for (p1 = np, p2 = np->next; p2 && p2->next; p2 = p2->next->next)
        p1 = p1->next;

    p2 = p1->next;
    p1->next = NULL;
    p1 = np;
    p1 = msort(p1);
    p2 = msort(p2);

    return merge(p1, p2);
}
void sort()
{
    struct node *p1, *p2;
    struct node *temp;
    temp=head;
    first = msort(temp);
    p1 = NULL;
    for (p2 = first; p2; p2 = p2->next)
	{
        p2->last = p1;
        p1 = p2;
    }
    last = p1;
}
void output()
{
	label1:

	getch();
	system("cls");
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	printf("\n\n\t\t\t\t\t\t======================================= \n\n");

	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("\t\t\t\t\t\t\t\tOPTIONS\n\n");

	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	printf("\t\t\t\t\t\t======================================= \n");

	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
    printf("\n\t\t\t\t\t\t\t  1. Create\n");
    printf("\t\t\t\t\t\t\t  2. Insert\n");
    printf("\t\t\t\t\t\t\t  3. Display\n");
    printf("\t\t\t\t\t\t\t  4. Search\n");
    printf("\t\t\t\t\t\t\t  5. Modify\n");
    printf("\t\t\t\t\t\t\t  6. Delete\n");
    printf("\t\t\t\t\t\t\t  7. Back to login page\n");
    printf("\t\t\t\t\t\t\t  8. Undo\n");
    printf("\t\t\t\t\t\t\t  9. Exit\n");

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	printf("\t\t\t\t\t\t======================================= \n");

	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("\n\t\t\t\t\t\tEnter your choice : ");
}
void write_binary(FILE *f1)
{
    struct data s;
    head1=head;
    struct node*dumpy=head;
	while(dumpy!=NULL)
	{
        s=dumpy->d1;
        fwrite(&s, sizeof(s), 1, f1);
        dumpy=dumpy->next;
	}
}
void insert_list(struct data d)
{
   struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->next = NULL;
    ptr->prev = NULL;
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");

   }
   else
   {
        ptr->d1=d;
       if(head == NULL)
       {
           head = tail=ptr;
       }
       else
       {
          tail->next = ptr;
          ptr ->prev=tail;
          tail=ptr;
       }

   }
}
void read_binary(FILE *f1)
{
    struct data s;
    head=NULL;
	while(fread(&s,sizeof(s),1,f1))
    {
    	insert_list(s);
    }
}

int check_ph(char *ph)
{
	struct node*temp=head;
    while(temp!=NULL)
    {
        if(strcmp(ph,temp->d1.phone)==0)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int checkString(char str1[])
{
    int i, x=0, p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == ' '))
        {
            continue;
        }
        else
		{
			return 0;
		}
    }
    return 1;
}
int checkString_num(char str1[])
{
    int i, x=0, p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9' &&  p == 10 )
        {
            continue;
        }
        else
		{
		    return 0;
		}
    }
    if(check_ph(str1)!=0)
       return -1;
    return 1;
}
void create()
{
    int n,i=0;
    printf("\n\t\t\t\t\t\tEnter the number of records : ");
    scanf("%d",&n);
    system("cls");
    head=NULL;

    for(i=0;i<n;i++)
    {
        struct data d;
        fflush(stdin);
        printf("\n\n\n\t\t\t\t\t\t\tPerson %d\n\n",i+1);
        printf("\n\t\t\t\t\t\t Enter the name : ");
        gets(d.name);

        while(checkString(d.name)==0)
        {
        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
        	printf("\n\t\t\t\t\t\t\tInvalid name...! Re-enter...\n\n");
        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
        	printf("\n\t\t\t\t\t\t Enter the name : ");
        	gets(d.name);
		}
        fflush(stdin);
        printf("\n\t\t\t\t\t\t Enter the blood group : ");
        gets(d.blood);

        fflush(stdin);
        printf("\n\t\t\t\t\t\t Enter the profession : ");
        gets(d.profession);

        while(checkString(d.profession)==0)
        {
        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
        	printf("\n\t\t\t\t\t\t\t Invalid profession...! Re-enter...\n\n");
        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
        	printf("\n\t\t\t\t\t\t Enter the profession : ");
        	gets(d.profession);
		}
        fflush(stdin);
        printf("\n\t\t\t\t\t\t Enter the address : ");
        gets(d.address);
        fflush(stdin);

        printf("\n\t\t\t\t\t\t Enter the phone number : ");
        gets(d.phone);

        while(true)
        {
        	if(checkString_num(d.phone)==1)
        		break;
        	else if(checkString_num(d.phone)==-1)
        	{
        		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
        		printf("\n\t\t\t\t\t\t Number already exists...! Enter unique number...");
			}
        	else
			{
        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
        	printf("\n\t\t\t\t\t\t\t Invalid number...! Re-enter...\n\n");
            }
        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
        	printf("\n\n\t\t\t\t\t\t Enter the phone number : ");
        	gets(d.phone);
		}
        insert_list(d);
    }
    FILE *f1;
    f1=fopen("data.dat","wb");
    write_binary(f1);
    fclose(f1);
}
void insert()
{
	struct node *temp=head;

    /*if(temp==NULL)
    {
    	printf("\n\n\t\t\t\t\t\tThe list is empty...Create it first...!");
	}*/

    FILE *f1;
    f1=fopen("data.dat","rb");
    if(!f1)
    {
        printf("\n\n\t\t\t\t\t\tFile doesn't exist please create it...!\n");
        return;
    }
    read_binary(f1);
    fclose(f1);
    struct data d;
    fflush(stdin);
    printf("\n\t\t\t\t\t\t Enter the name : ");
    gets(d.name);

    while(checkString(d.name)==0)
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
    	printf("\n\t\t\t\t\t\t\tInvalid name...! Re-enter...\n\n");
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
    	printf("\n\t\t\t\t\t\t Enter the name : ");
    	gets(d.name);
	}
    fflush(stdin);
    printf("\n\t\t\t\t\t\t Enter the blood group : ");
    gets(d.blood);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t Enter the profession : ");
    gets(d.profession);
    checkString(d.profession);
    while(checkString(d.profession)==0)
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
    	printf("\n\t\t\t\t\t\t\t Invalid profession...! Re-enter...\n\n");
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
    	printf("\n\t\t\t\t\t\t Enter the profession : ");
    	gets(d.profession);
	}
    fflush(stdin);
    printf("\n\t\t\t\t\t\t Enter the address : ");
    gets(d.address);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t Enter the phone number : ");
    gets(d.phone);
    
    while(true)
    {
    	if(checkString_num(d.phone)==1)
    		break;
    	else if(checkString_num(d.phone)==-1)
    	{
    		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
    		printf("\n\t\t\t\t\t\t Number already exists...! Enter unique number...");
		}
    	else
		{
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
    	printf("\n\t\t\t\t\t\t\t Invalid number...! Re-enter...\n\n");
        }
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
    	printf("\n\n\t\t\t\t\t\t Enter the phone number : ");
    	gets(d.phone);
	}
    insert_list(d);
    FILE *f2;
    f2=fopen("data.dat","wb");
    write_binary(f2);
    fclose(f2);

}
void disp()
{
    struct node *temp=head;
    int i=0;
    if(temp==NULL)
    {
    	printf("\n\n\t\t\t\t\t\tNo records available...!");
	}
    while(temp!=NULL)
    {
    	printf("\n\n\t\t\t\t\t\t======================================\n");
        printf("\n\t\t\t\t\t\t\t    Person %d\n",i+1);
        printf("\n\t\t\t\t\t\t======================================\n\n");
        printf("\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n",temp->d1.phone);
        i++;
        temp=temp->next;
    }
}
void display()
{
    FILE *f1;
    f1=fopen("data.dat","rb");
    if(!f1)
	{
	    printf("\n\n\t\t\t\t\t\tFile doesn't exist please create it...!\n");
	    return;
	}
    read_binary(f1);
    fclose(f1);
    sort();
    disp();
}
void search1()
{
	struct node *temp=head;
    if(temp==NULL)
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
    	printf("\n\n\t\t\t\t\t\tNo records available...!");
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
    while(temp!=NULL)
    {
	    FILE *f1;
	    f1=fopen("data.dat","rb");
	    if(!f1)
	    {
	        printf("\n\n\t\t\t\t\t\tFile doesn't exist please create it...!\n");
	        return;
	    }
	    read_binary(f1);
	    fclose(f1);

	    label:
	    system("cls");
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	    printf("\n\n\n\t\t\t\t\t\t To search details : \n\n");

	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	    printf("\t\t\t\t\t\t\t 1.  by Name\n");
	    printf("\t\t\t\t\t\t\t 2.  by Profession\n");
	    printf("\t\t\t\t\t\t\t 3.  by Blood group\n");
	    printf("\t\t\t\t\t\t\t 4.  by Phone\n");
	    printf("\t\t\t\t\t\t\t 5.  Back\n");

	    //label:

	    int choice;
        int final1;
        int rtn = 0;
        for (;;)
		{
	    //system("cls");
	    printf("\n\t\t\t\t\t\t Enter your choice : ");
	    rtn = scanf (" %d", &final1);
		    if (rtn == 0)
			{
	            fputs ("\n\t\t\t\t\t\t\t  Error: Character input-Invalid...!\n", stderr);
	            empty_stdin();
	        }
	        else if (final1<1 || 5<final1)
			{
	            fputs ("\n\t\t\t\t\t\t\t  Error: Choice out of range [1-5] - Invalid...!\n", stderr);
	            empty_stdin();
	        }
	        else
			{
	            empty_stdin();
	            break;
	        }
	        printf("\n\t\t\t\t\t\t\t  ");
	        system("pause");
	      }
	    fflush(stdin);
	    choice=final1;
	    switch(choice)
	    {
	        case 1:
	        {
	            int i=0;
	            int flag=0;
	            struct data k;
	            fflush(stdin);
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\t Enter the name you want to search : ");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            gets(k.name);

	            struct node *temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(k.name,temp->d1.name)==0)
	                {
	                	printf("\n\n\t\t\t\t\t\tPerson %d\n\n",i+1);
				        printf("\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n",temp->d1.phone);
	                    i++;
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
	            if(flag==0)
	            {
	            	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                printf("\n\t\t\t\t\t\t The element is not found\n");
	                getch();
	                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            }
	            flag=0;
	            break;
	        }
	        case 2:
	        {
	        	int i=0;
	            int flag=0;
	            char profession1[25];
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\t Enter the profession you want to search : ");
	            gets(profession1);
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	            struct node *temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(profession1,temp->d1.profession)==0)
	                {
	                    printf("\n\n\t\t\t\t\t\tPerson %d\n\n",i+1);
				        printf("\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n\n\n",temp->d1.phone);
				        i++;
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
	            if(flag==0)
	            {
	            	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                printf("\n\t\t\t\t\t\t The element is not found\n");
	                getch();
	                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            }
	            flag=0;
	            break;
	        }
	        case 3:
	        {
	        	int i=0;
	            int flag=0;
	            char blood1[6];
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\tEnter the blood group you want to search : ");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	            gets(blood1);
	            struct node*temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(blood1,temp->d1.blood)==0)
	                {
	                	printf("\n\n\t\t\t\t\t\tPerson %d\n\n",i+1);
				        printf("\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n",temp->d1.phone);
				        i++;
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
                if(flag==0)
                {
                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                    printf("\n\t\t\t\t\t\t The element is not found\n");
                    getch();
                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

                }
                flag=0;
	            break;
	        }
	        case 4:
	        {
	            int flag=0;
	            char phone1[6];
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\t Enter the phone number you want to search : ");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	            gets(phone1);
	            struct node*temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(phone1,temp->d1.phone)==0)
	                {
	                    printf("\n\n\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n",temp->d1.phone);
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
	                if(flag==0)
	                {
	                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                    printf("\n\t\t\t\t\t\t The element is not found\n");
	                    getch();
	                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	                }
	                flag=0;
	            break;
	        }
	        case 5:
	        	admin_options();
	        	getch();
	        	break;
	        default:
	        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	            printf("\n\n\t\t\t\t\t\t Invalid choice...! Re-enter please...\n");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            printf("\n\t\t\t\t\t\t\t  ");
        		system("pause");
	            goto label;
	    }
	    FILE *f2;
	    f2=fopen("data.dat","wb");
	    write_binary(f2);
	    fclose(f2);
	}
}

void search2()
{
	struct node *temp=head;
    if(temp==NULL)
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
    	printf("\n\n\t\t\t\t\t\tNo records available...!");
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
    while(temp!=NULL)
    {
	    FILE *f1;
	    f1=fopen("data.dat","rb");
	    if(!f1)
	    {
	        printf("\n\n\t\t\t\t\t\tFile doesn't exist please create it...!\n");
	        return;
	    }
	    read_binary(f1);
	    fclose(f1);

	    label:
	    system("cls");
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	    printf("\n\n\n\t\t\t\t\t\t To search details : \n\n");

	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	    printf("\t\t\t\t\t\t\t 1.  by Name\n");
	    printf("\t\t\t\t\t\t\t 2.  by Profession\n");
	    printf("\t\t\t\t\t\t\t 3.  by Blood group\n");
	    printf("\t\t\t\t\t\t\t 4.  by Phone\n");
	    printf("\t\t\t\t\t\t\t 5.  Back\n");

	    //label:

	    int choice;
        int final1;
        int rtn = 0;
        for (;;)
		{
	    //system("cls");
	    printf("\n\t\t\t\t\t\t Enter your choice : ");
	    rtn = scanf (" %d", &final1);
		    if (rtn == 0)
			{
	            fputs ("\n\t\t\t\t\t\t\t  Error: Character input-Invalid...!\n", stderr);
	            empty_stdin();
	        }
	        else if (final1<1 || 5<final1)
			{
	            fputs ("\n\t\t\t\t\t\t\t  Error: Choice out of range [1-5] - Invalid...!\n", stderr);
	            empty_stdin();
	        }
	        else
			{
	            empty_stdin();
	            break;
	        }
	        printf("\n\t\t\t\t\t\t\t  ");
	        system("pause");
	      }
	    fflush(stdin);
	    choice=final1;
	    switch(choice)
	    {
	        case 1:
	        {
	            int i=0;
	            int flag=0;
	            struct data k;
	            fflush(stdin);
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\t Enter the name you want to search : ");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            gets(k.name);

	            struct node *temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(k.name,temp->d1.name)==0)
	                {
	                	printf("\n\n\t\t\t\t\t\tPerson %d\n\n",i+1);
				        printf("\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n",temp->d1.phone);
	                    i++;
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
	            if(flag==0)
	            {
	            	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                printf("\n\t\t\t\t\t\t The element is not found\n");
	                getch();
	                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            }
	            flag=0;
	            break;
	        }
	        case 2:
	        {
	        	int i=0;
	            int flag=0;
	            char profession1[25];
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\t Enter the profession you want to search : ");
	            gets(profession1);
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	            struct node *temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(profession1,temp->d1.profession)==0)
	                {
	                    printf("\n\n\t\t\t\t\t\tPerson %d\n\n",i+1);
				        printf("\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n\n\n",temp->d1.phone);
				        i++;
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
	            if(flag==0)
	            {
	            	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                printf("\n\t\t\t\t\t\t The element is not found\n");
	                getch();
	                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            }
	            flag=0;
	            break;
	        }
	        case 3:
	        {
	        	int i=0;
	            int flag=0;
	            char blood1[6];
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\tEnter the blood group you want to search : ");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	            gets(blood1);
	            struct node*temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(blood1,temp->d1.blood)==0)
	                {
	                	printf("\n\n\t\t\t\t\t\tPerson %d\n\n",i+1);
				        printf("\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n",temp->d1.phone);
				        i++;
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
                if(flag==0)
                {
                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                    printf("\n\t\t\t\t\t\t The element is not found\n");
                    getch();
                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

                }
                flag=0;
	            break;
	        }
	        case 4:
	        {
	            int flag=0;
	            char phone1[6];
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	            printf("\n\t\t\t\t\t\t Enter the phone number you want to search : ");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	            gets(phone1);
	            struct node*temp=head;
	            while(temp!=NULL)
	            {
	                if(strcmp(phone1,temp->d1.phone)==0)
	                {
	                    printf("\n\n\t\t\t\t\t\tNAME         : %s\n",temp->d1.name);
				        printf("\t\t\t\t\t\tBLOOD GROUP  : %s\n",temp->d1.blood);
				        printf("\t\t\t\t\t\tPROFESSION   : %s\n",temp->d1.profession);
				        printf("\t\t\t\t\t\tADDRESS      : %s\n",temp->d1.address);
				        printf("\t\t\t\t\t\tPHONE NUMBER : %s\n",temp->d1.phone);
	                    flag++;
	                    printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
	                }
	                temp=temp->next;
	            }
	                if(flag==0)
	                {
	                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                    printf("\n\t\t\t\t\t\t The element is not found\n");
	                    getch();
	                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);

	                }
	                flag=0;
	            break;
	        }
	        case 5:
	        	front_page();
	        	//admin_options();
	        	getch();
	        	break;
	        default:
	        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	            printf("\n\n\t\t\t\t\t\t Invalid choice...! Re-enter please...\n");
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	            printf("\n\t\t\t\t\t\t\t  ");
        		system("pause");
	            goto label;
	    }
	    FILE *f2;
	    f2=fopen("data.dat","wb");
	    write_binary(f2);
	    fclose(f2);
	}
}
#endif // SOURCE_H_INCLUDED
