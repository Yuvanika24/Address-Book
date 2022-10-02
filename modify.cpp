#include "source1.cpp"
void admin_options();
void modify()
{
	struct node *temp=head;
    int i=0;
    if(temp==NULL)
    {
    	printf("\n\n\t\t\t\t\t\tThe list is empty...Create it first...!");
	}
    while(temp!=NULL)
    {
	    FILE *f1;
	    f1=fopen("data.dat","rb");
	    if(!f1)
	    {
	        printf("\n\n\t\t\t\t\t\tFile doesn't exist... Please create it\n");
	        return;
	    }
	    read_binary(f1);
	    fclose(f1);
	    prog:
	    	system("cls");
	    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	    printf("\n\n\n\n\t\t\t\t\t\t\t To search and modify the details : \n\n");
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	    
	    printf("\t\t\t\t\t\t 1. To search by NAME\n");
	    printf("\t\t\t\t\t\t 2. To search by PHONE NUMBER\n");
	    printf("\t\t\t\t\t\t 3. Back to admin options\n\n");
	    int choice;
    	int final1;
	    int rtn = 0;
	    for (;;) 
		{

	    printf("\n\t\t\t\t\t\t Enter your choice : ");
        rtn = scanf (" %d", &final1);
	    if (rtn == 0) 
		{
            fputs ("\n\t\t\t\t\t\t\t  Error: Character input-Invalid...!\n", stderr);
            empty_stdin();
        }
        else if (final1<1 || 3<final1) 
		{
            fputs ("\n\n\t\t\t\t\t\t\t  Error: Choice out of range [1-3] - Invalid...!", stderr);
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
	    choice=final1;
	    switch(choice)
	    {
	        case 1:
            {
                char name1[25];
                int flag=0;
                fflush(stdin);
                printf("\n\t\t\t\t\t\t Enter the name you want to search : ");
                gets(name1);
                struct node *temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(name1,temp->d1.name)==0)
                    {
                    	flag++;
                    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                        printf("\n\t\t\t\t\t\t\tSearched Details\n\n");
                        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                        printf("\t\t\t\t\t\t Name         : %s\n",temp->d1.name);
                        printf("\t\t\t\t\t\t Blood Group  : %s\n",temp->d1.blood);
                        printf("\t\t\t\t\t\t Profession   : %s\n",temp->d1.profession);
                        printf("\t\t\t\t\t\t Address      : %s\n",temp->d1.address);
                        printf("\t\t\t\t\t\t Phone Number : %s\n",temp->d1.phone);

                        printf("\n\n\t\t\t\tPress 1 to make changes \t\t");
                        printf("Press 0 to continue\n");
                        int opt;
                        printf("\n\t\t\t\t\t\t Enter your choice : ");
                        scanf("%d",&opt);
                        if(opt==1)
                        {
                       	 	label:
                       	 		system("cls");
                       	 		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                        	printf("\n\t\t\t\t\t\t\t To modify by");
                        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                            printf("\n\t\t\t\t\t\t   1.Name\n");
                            printf("\t\t\t\t\t\t   2.Blood group\n");
                            printf("\t\t\t\t\t\t   3.Profession\n");
                            printf("\t\t\t\t\t\t   4.Address\n");
                            printf("\t\t\t\t\t\t   5.Phone number\n");
                            printf("\t\t\t\t\t\t   6.To modify the whole record\n");
                            int prf;
                            printf("\n\t\t\t\t\t\t Enter your choice : ");
                            scanf("%d",&prf);
                            switch(prf)
                            {
                            	case 1:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the name : ");
                                    gets(temp->d1.name);
                                    flag++;
	                                if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 2:
                                {
                                    fflush(stdin);
                                    printf("\\t\t\t\t\t\t Enter the blood group : ");
                                    gets(temp->d1.blood);
                                    flag++;
                                if(flag!=0)
                                {
                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
                                    getch();
                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                                }
                                    break;
                                }
                            	case 3:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t The profession : ");
                                    gets(temp->d1.profession);
                                    flag++;
	                                if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tThe element is found and it has been modified\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                           	 	case 4:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the address : ");
                                    gets(temp->d1.address);
                                    flag++;
	                                if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tThe element is found and it has been modified\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 5:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the phone number : ");
                                    gets(temp->d1.phone);
                                    flag++;
	                                if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 6:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the name        : ");
                                    gets(temp->d1.name);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the blood group : ");
                                    gets(temp->d1.blood);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the profession  : ");
                                    gets(temp->d1.profession);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the address     : ");
                                    gets(temp->d1.address);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the phone number : ");
                                    gets(temp->d1.phone);
                                    flag++;
                                    if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	default:
                            		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                printf("\n\t\t\t\t\t\t Invalid choice...! Re-enter again\n");
	                                getch();
	                                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                goto label;
                            }
                        }
                        else
                        {
                        	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                            printf("\n\t\t\t\t\t\t No changes required\n");
                            getch();
                            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                        }
                	}
                	/*else
                    {
                    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                        printf("\n\t\t\t\t\t\t hello The element is not found in the linked list\n");
                        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                        printf("\n\t\t\t\t\t\t\t  ");
        				system("pause");
                    }*/
                    temp=temp->next;
                }
                
                if(flag==0)
                {
                	printf("\n\t\t\t\t\t\t Element not found...!");
                	getch();
				}
                free(temp);
                break;
            }
        	case 2:
            {
                int flag1=0,flag=0;
                struct data k;
                fflush(stdin);
                printf("\n\t\t\t\t\t\t Enter the phone number you want to search : ");
                gets(k.phone);
                struct node *temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(k.phone,temp->d1.phone)==0)
                    {
                    	flag1++;
                    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                        printf("\n\t\t\t\t\t\t\tSearched Details\n\n");
                        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                        printf("\t\t\t\t\t\t Name         : %s\n",temp->d1.name);
                        printf("\t\t\t\t\t\t Blood Group  : %s\n",temp->d1.blood);
                        printf("\t\t\t\t\t\t Profession   : %s\n",temp->d1.profession);
                        printf("\t\t\t\t\t\t Address      : %s\n",temp->d1.address);
                        printf("\t\t\t\t\t\t Phone Number : %s\n",temp->d1.phone);

                        printf("\n\n\t\t\t\t\t\t\tPress 1 to make changes \n");
                        printf("\n\t\t\t\t\t\t\tPress 0 to continue\n");
                        int opt;
                        printf("\t\t\t\t\t\t Enter your choice : ");
                        scanf("%d",&opt);
                        if(opt==1)
                        {
                        	label1:
                        		system("cls");
                        		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                            printf("\n\t\t\t\t\t\t\t\t To modify by");
                            SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                            printf("\n\t\t\t\t\t\t   1.Name\n");
                            printf("\t\t\t\t\t\t   2.Blood group\n");
                            printf("\t\t\t\t\t\t   3.Profession\n");
                            printf("\t\t\t\t\t\t   4.Address\n");
                            printf("\t\t\t\t\t\t   5.Phone number\n");
                            printf("\t\t\t\t\t\t   6.To modify the whole record\n");
                            int prf;
                            printf("\n\t\t\t\t\t\t Enter your choice : ");
                            scanf("%d",&prf);
                            switch(prf)
                            {
                            	case 1:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the name : ");
                                    gets(temp->d1.name);
                                    flag++;
	                                if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 2:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the blood group : ");
                                    gets(temp->d1.blood);
                                    flag++;
                                    if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 3:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the profession : ");
                                    gets(temp->d1.profession);
                                    flag++;
                                   if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 4:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the address : ");
                                    gets(temp->d1.address);
                                    flag++;
                                    if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 5:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the phone number : ");
                                    gets(temp->d1.phone);
                                    flag++;
                                    if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                                    break;
                                }
                            	case 6:
                                {
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the name        : ");
                                    gets(temp->d1.name);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the blood group : ");
                                    gets(temp->d1.blood);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the profession  : ");
                                    gets(temp->d1.profession);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the address     : ");
                                    gets(temp->d1.address);
                                    fflush(stdin);
                                    printf("\n\t\t\t\t\t\t Enter the phone number : ");
                                    gets(temp->d1.phone);
                                    break;
                                    flag++;
                                    if(flag!=0)
	                                {
	                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                    printf("\n\t\t\t\t\t\tElement is found and modified...!\n");
	                                    getch();
	                                    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                }
                            	}
                                default:
                                	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                                printf("\n\t\t\t\t\t\t Invalid choice...! Re-enter again\n");
	                                getch();
	                                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                                goto label1;
                        	}
						}
	                    else
	                    {
	                    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	                        printf("\n\t\t\t\t\t\tNo changes required...!\n");
	                        getch();
	                        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	                    }
                	}
                    temp=temp->next;
                }
                      if(flag1==0)
                {
                	
                	printf("\n\t\t\t\t\t\t Element not found...!");
                	getch();
				}
                        free(temp);
                        break;
            }
            case 3:
            	admin_options();//	output();
            	getch();
            	break;
            default:
            	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
                printf("\n\t\t\t\t\t\t Invalid choice...! Re-enter again\n");
                getch();
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                goto prog;
        }
        FILE *f2;
        f2=fopen("data.dat","wb");
        write_binary(f2);
        fclose(f2);
	}
}

