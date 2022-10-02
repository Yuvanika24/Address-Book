#include "source1.cpp"
#include "deletion1.cpp"
#include "modify1.cpp"

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <windows.h>
#include  <limits>
#include  <ctype.h>


void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

int front_page();

void admin_options();

bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'));
}
bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}
struct login
{
	char name[50];
	char passwor[20];
};
void loadingBar()
{
    char a = 177, b = 219;
    printf("\n\n\t\t\t\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");
        
    printf("\r");
    printf("\t\t\t\t\t\t\t\t");
    for (int i = 0; i < 15; i++) 
	{
        printf("%c", b);
        Sleep(100);
    }
}
//----------------------------------------------------------------------------------------------------------//
// register
//----------------------------------------------------------------------------------------------------------//
void sign_up()
{
	char u_pass[20];
	int i;
	int flag=0;
	struct login l;
	struct login c;
	FILE *ln;
	FILE *lo;
	lo = fopen("login.bin","ab+");
	
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	printf("\n\n\t\t\t\t\t\tSIGN UP");
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tCreate Username  :");
	gets(l.name);
	
	fflush(stdin);

	printf("\n\t\t\t\t\t\tCreate Password  :");
	for( i=0 ; ; )
	{
		u_pass[i] = getch();
		if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
		{
			l.passwor[i] = u_pass[i];
			++i;
			u_pass[i]='*';			// password masking
			printf("%c",u_pass[i]);
		}
		if(u_pass[i] == '\b' && i>=1)
		{
		    printf("\b \b");
		    --i;
		}
		if(u_pass[i] == '\r')
		{
			l.passwor[i] = '\0';
			break;
		}
	}
    fwrite(&l, sizeof(login),1,lo);
	fclose(lo);
	front_page();
   }
//----------------------------------------------------------------------------------------------------------//
// LOGIN
//----------------------------------------------------------------------------------------------------------//
void sign_in()
{
	int l_times = 0;
	while(l_times<3)
	{
		int i,flag=0;
		char u_pass[20],pass[20], username[50];
	
		struct login l;
		FILE *lo;
		
		fflush(stdin);
		printf("\n\n\t\t\t\t\t\tUsername  :");
		gets(username);
		
		fflush(stdin);
		printf("\n\t\t\t\t\t\tPassword  :");
		
		for( i=0 ; ; )
		{
			u_pass[i] = getch();
			if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
			{
				pass[i] = u_pass[i];
				++i;
				u_pass[i]='*';
				printf("%c",u_pass[i]);
			}
			if(u_pass[i] == '\b' && i>=1)
			{
			    printf("\b \b");
			    --i;
			}
			if(u_pass[i] == '\r')
			{
				pass[i] = '\0';
				break;
			}
		}
		lo = fopen("login.bin","rb");
	
		while(fread(&l,sizeof(login),1,lo))
		{
			if(strcmpi(username,l.name)==0 && strcmpi(pass,l.passwor)==0)
			{
				flag = 1;
				
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
				printf("\n\n\n\t\t\t\t\t\tLog in Successful...!");
				ResetConsoleColour(240);
				
				admin_options();
			}
		}
		if(flag == 0)
		{
			l_times++;
			SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
			printf("\n\n\t\t\t\t\t\tInvalid Username/Password...");
				ResetConsoleColour(240);
		}
   }
   SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
   printf("\n\n\t\t\t\t\t\tToo many login attempts...!\n\n\t\t\t\t\t\tTry again later...\n\n\t\t\t\t\t\tThank you...!\n\n\n");
   ResetConsoleColour(240);
}
//----------------------------------------------------------------------------------------------------------//
// admin login
//----------------------------------------------------------------------------------------------------------//
int userlogin(void)
{
    int n,rtn;
    
    for (;;) 
	{
		system("cls");
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t WELCOME TO ADDRESS BOOK\n");
       
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
        printf("\n\n\t\t\t\t\t\t============= ADMIN LOGIN =============\n");
       
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
        printf("\n\n\t\t\t\t\t\t\t\t1. LOGIN\n\n\t\t\t\t\t\t\t\t2. REGISTER\n\n\t\t\t\t\t\t\t\t3. BACK");
        
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
        printf("\n\n\t\t\t\t\t\t======================================= \n\n");
        
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
        
    	printf("\n\t\t\t\t\t\tENTER YOUR CHOICE : ");
        rtn = scanf("%d",&n);
        
        if (rtn == EOF) 
		{
            fputs ("\n\t\t\t\t\t\t\t  user canceled input\n", stderr);
            return 1;
        }
        else if (rtn == 0) 
		{
            fputs ("\n\t\t\t\t\t\t\t  Error: Character input-Invalid...!\n", stderr);
            empty_stdin();
        }
        else if (n<1 || 3<n) 
		{
            fputs ("\n\t\t\t\t\t\t\t  Error: Choice out of range [1-3] - Invalid...!", stderr);
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
    switch(n)
	{
        case 1:
		{
            sign_in();		//login
            break;
        }
        case 2:
        {
            sign_up();		//register
            break;
        }
        case 3:
        {
            front_page();	//back
            break;
        }
    }
}
//----------------------------------------------------------------------------------------------------------//
// admin menu
//----------------------------------------------------------------------------------------------------------//
void admin_options()
{
	while(true)
	{
    int rtn,choice;
    for(;;)
    {
        label:
        output();
        rtn = scanf("%d",&choice);
        
		if (rtn == 0) 
		{
            fputs ("\n\t\t\t\t\t\t\t  Error: Character input-Invalid...!\n", stderr);
            empty_stdin();
        }
        else if (choice<1 || 9<choice) 
		{
            fputs ("\n\t\t\t\t\t\t\t  Error: Choice out of range [1-9] - Invalid...!", stderr);
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
        switch(choice)
        {
    	case 1:
        {
            char ch;
            printf("\n\t\t\t\t\t\t\tIf we create a file ,The existing file will be deleted\n");
            printf("\n\t\t\t\t\t\t\tPress y Or Y ---> To create new file\n");
            printf("\n\t\t\t\t\t\t\tPress n Or N ---> To skip\n");
            fflush(stdin);
            printf("\n\t\t\t\t\t\t\t  ");
            scanf("%c",&ch);
            if(ch=='y'||ch=='Y')
            {
                create();
            }
            break;
        }
        case 2:
            insert();
            break;
        case 3:
            display();
            break;
        case 4:
            search1();
            break;
        case 5:
            modify();
            break;
        case 6:
            delete1();
            break;
        case 7:
            userlogin();
            break;
        case 8:
            undo();
            break;
        case 9:
        	exit(0);
            break;
        }
    }
}
//----------------------------------------------------------------------------------------------------------//
// 1st page
//----------------------------------------------------------------------------------------------------------//
int front_page()
{
    dsa:
    	
    int final1;
    int rtn = 0;
    for (;;) 
	{
        ads:
	    system("cls");
	    
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	    printf("\n\n\n\n\t\t\t\t\t\t\t  THE #1 FREE ONLINE ADDRESS BOOK ");
	    printf("\n\n\t\t\t\t\t\tThe easiest way to get all of your friends\' addresses...!");
	    ResetConsoleColour(240);
	    
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
		
	    printf("\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO ADDRESS BOOK\n\n");
	    ResetConsoleColour(240);
	    
	    printf("\t\t\t\t\t\t\t====================================== \n\n");
	    
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	    printf("\t\t\t\t\t\t\t\t  1. ADMIN \n\n");
	    
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	    printf("\t\t\t\t\t\t\t\t  2. USER \n\n");
	    
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	    printf("\t\t\t\t\t\t\t\t  3. EXIT \n");
	    
	    ResetConsoleColour(240);
	    printf("\n\t\t\t\t\t\t\t====================================== \n\n");
	    
	    printf("\n\n\t\t\t\t\t\t\t  Enter your choice : ");
	    
	    rtn = scanf (" %d", &final1);
	    
        if (rtn == EOF) 
		{
            fputs ("\n\t\t\t\t\t\t\t user canceled input \n", stderr);
            return 1;
        }
        else if (rtn == 0) 
		{
            fputs ("\n\t\t\t\t\t\t\t  Error: Character input-Invalid...!\n", stderr);
            empty_stdin();
        }
        else if (final1<1 || 3<final1) 
		{
            fputs ("\n\t\t\t\t\t\t\t  Error: Choice out of range [1-3] - Invalid...!\n", stderr);
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
    if(final1==3)
    {
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
        printf("\n\n\n\t\t\t\t\t\t\tThank you for your response...!");
        ResetConsoleColour(240);
        
        printf("\n\n\n\n\n");
        exit(0);
    }
    if(final1==1)
    {
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
        loadingBar();
        ResetConsoleColour(240);
        userlogin();
    }
    else if(final1==2)
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
        loadingBar();
        ResetConsoleColour(240);
        
        int choice;
    	while(true)
        {
        	int final1;
			int rtn = 0;
			for (;;) 
			{  	
	            label:
	            system("cls");
		    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
		    	
		        printf("\n\n\n\n\n\t\t\t\t\t\t\tWELCOME TO ADDRESS BOOK\n");
		        
				ResetConsoleColour(240);
				
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
		        printf("\n\n\t\t\t\t\t\t============= USER LOGIN =============\n\n\n");
		        ResetConsoleColour(240);
		        
	            printf("\t\t\t\t\t\t\t  1. View address\n\n");
	            printf("\t\t\t\t\t\t\t  2. Back\n\n");
	            
	            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	            
	            printf("\t\t\t\t\t\t====================================== \n\n");
	            ResetConsoleColour(240);
			    printf("\t\t\t\t\t\tEnter your choice : ");
			    
		        rtn = scanf (" %d", &final1);
		        if (rtn == EOF) 
				{
		            fputs ("\n\t\t\t\t\t\t\t user canceled input \n", stderr);
		            return 1;
		        }
		        else if (rtn == 0) 
				{
		            fputs ("\n\t\t\t\t\t\t\t  Error: Character input-Invalid...!\n", stderr);
		            empty_stdin();
		        }
		        else if (final1<1 || 2<final1) 
				{
		            fputs ("\n\t\t\t\t\t\t\t  Error: Choice out of range [1-3] - Invalid...!\n", stderr);
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
		        
	        if(final1==1)
	        {	
	        	FILE *f1;
			    f1=fopen("data.dat","rb");
			    read_binary(f1);
			    fclose(f1);
			    
			    search2();	// search is called for searching and displaying
	        	
				printf("\n\n\n\t\t\t\t\t\t");
        		system("pause");
			}
	        if(final1==2)
	        	goto ads;
    	}
    }
    }
//----------------------------------------------------------------------------------------------------------//
// main function
//----------------------------------------------------------------------------------------------------------//
int main()
{
    front_page();
    return 0;
}
