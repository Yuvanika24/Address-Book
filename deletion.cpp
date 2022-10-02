#include "source1.cpp"
#include<stack>
struct data point[25];
int Top=-1;

void push(struct data pt)
{
    if(Top==24)
    {
        //printf("Overflow\n");
    }
    else
    {
        Top++;
        point[Top]=pt;
    }
    return;
}
struct data pop()
{
    return point[Top--];
}
void undo()
{
    if(Top==-1)
	{
		//printf("Underflow\n");
	}
	else
    {
	struct data temp=pop();
	printf("\n\n\n\t\t\t\t\tUndone successfully ...!");
	printf("\n\n\t\t\t\t\tUndone element : %s",temp.name);
	FILE *f1;
	f1=fopen("data.dat","rb");
	if(!f1)
    {
        printf("\n\n\t\t\t\t\t\tFile doesn't exist... Please create it...!\n");
        return;
    }
	read_binary(f1);
	fclose(f1);
	insert_list(temp);
	FILE *f2;
    f2=fopen("data.dat","wb");
    write_binary(f2);
    fclose(f2);
    }
}

void delete1()
{
	
	FILE *f1;
    f1=fopen("data.dat","rb");
    if(!f1)
    {
        printf("\n\n\t\t\t\t\t\tFile doesn't exist... Please create it...!\n");
        return;
    }
    read_binary(f1);
    fclose(f1);
    
    struct node *temp=head;
    int i=0,flag=0;
    
    char str[25];
    char temp_ph[11];
    fflush(stdin);
    
    printf("\n\t\t\t\t\t\tEnter the name : ");
    gets(str);
    fflush(stdin);
    while (temp!=NULL)
    {

       if(strcmp(temp->d1.name,str)==0)
        {
        	flag=1;
            printf("\n\t\t\t\t\t\tDetails of the employee to be deleted : \n\n");
            printf("\t\t\t\t\t\t  Name         : %s\n",temp->d1.name);
            printf("\t\t\t\t\t\t  Blood group  : %s\n",temp->d1.blood);
            printf("\t\t\t\t\t\t  Profession   : %s\n",temp->d1.profession);
            printf("\t\t\t\t\t\t  Address      : %s\n",temp->d1.address);
            printf("\t\t\t\t\t\t  Phone number : %s\n",temp->d1.phone);
            
            printf("\n\n\t\t\t\tPress 1 to delete \t\t");
            printf("Press 0 to continue\n");
            int opt;
            printf("\n\t\t\t\t\t\t Enter your choice : ");
            scanf("%d",&opt);
            
            if(opt==1)
            {
            	strcpy(temp_ph,temp->d1.phone);
            	//printf("\n %s",temp_ph);
            	
			 if(strcmp(head->d1.phone,temp->d1.phone)==0) // head node
             {
		
                if(head->next != NULL) //head is not the only node...that is it has more than one node
                {
                    head->next->prev = NULL;
                    push(head->d1);
                    head = head->next;
                }
                else //head is the only node
                {
                	push(head->d1);
                    head = NULL;
                    printf("\n\t\t\t\t\t\tList is empty now...!");
                    
                    FILE *f2;
                    f2=fopen("data1.dat","wb");
                    write_binary(f2);
                    fclose(f2);
                    
                    remove("data.dat");
                    rename("data1.dat","data.dat");
                    free(temp);
                    return;
                }
            }
            if(strcmp(head->d1.phone,temp_ph)!=0) // not a head node
            {
            	struct node *temp;//,*pre_node;
	            temp = head;
	            while(temp->next != NULL && strcmp(temp->d1.phone,temp_ph)!=0)
	            {
	              temp = temp->next;
	            }
	            
	           // printf("\n %s \n",temp->d1.phone);
	            
	            if(strcmp(temp->d1.phone,temp_ph)==0)
	            {
	            	temp->prev->next = temp->next;
	            	
	              	if(temp->next != NULL)
	                {
	                    temp->next->prev = temp->prev;
	                }
	                else
	                {
	                	last =temp->prev;
	                	last->next=NULL;
	                }
	                push(temp->d1);
	            }
	 		}
           
			} 
 		} 
		temp=temp->next;
    }
	FILE *f2;
	f2=fopen("data1.dat","wb");
	write_binary(f2);
	fclose(f2);
	
	remove("data.dat");
	rename("data1.dat","data.dat");
	
	if(flag==0)
	{
		printf("\n\t\t\t\t\t\t Element not found...!");
	}
	free(temp);

}




























































/*void push(struct data pt)
{
    if(Top==24)
    {
        printf("Overflow\n");
    }
    else
    {
        Top++;
        point[Top]=pt;
    }
    return;
}
struct data pop()
{
	if(Top==-1)
	{
		printf("Underflow\n");
	}
    return point[Top--];
}
void undo()
{
	struct data temp=pop();
	printf("%s",temp.name);
	FILE *f1;
	f1=fopen("data.dat","rb");
	if(!f1)
	    {
	        printf("\n\n\t\t\t\t\t\tFile doesn't exist... Please create it\n");
	        return;
	    }
	read_binary(f1);
	fclose(f1);
	insert_list(temp);
	FILE *f2;
    f2=fopen("data.dat","wb");
    write_binary(f2);
    fclose(f2);
}*/


/*
void delete1()
{
	
	FILE *f1;
    f1=fopen("data.dat","rb");
    read_binary(f1);
    fclose(f1);
    
    struct node *temp=head;
    int i=0,flag=0;
    
    char str[25];
    fflush(stdin);
    
    printf("\n\t\t\t\t\t\tEnter the name : ");
    gets(str);
    fflush(stdin);
    while (temp!=NULL)
    {
       if(strcmp(temp->d1.name,str)==0)
        {
        	flag=1;
            printf("\n\t\t\t\t\t\tDetails of the customer which you want to delete is...\n\n");
            printf("\t\t\t\t\t\t  Person Name  :%s\n",temp->d1.name);
            printf("\t\t\t\t\t\t  Blood group  :%s\n",temp->d1.blood);
            printf("\t\t\t\t\t\t  Profession   :%s\n",temp->d1.profession);
            printf("\t\t\t\t\t\t  Address      :%s\n",temp->d1.address);
            printf("\t\t\t\t\t\t  Phone number :%s\n",temp->d1.phone);
            
            printf("\n\n\t\t\t\tPress 1 to delete \t\t");
            printf("Press 0 to continue\n");
            int opt;
            printf("\n\t\t\t\t\t\t Enter your choice : ");
            scanf("%d",&opt);
            if(opt==1)
            {
            	printf("aaa");
				if(strcmp(head->d1.name,temp->d1.name)==0) // head node
	            {
	                printf("\n\t\t\t\t\t\tIt is at head...! \n");
	                if(head->next != NULL) //head is not the only node...that is it has more than one node
	                {
	                    head->next->prev = NULL;
	                    push(head->d1);
	                    head = head->next;
	                }
	                else //head is the only node
	                {
	                	push(head->d1);
	                    head = NULL;
	                    head->next=NULL;
	                    head->prev=NULL;
	                    printf("\n\t\t\t\t\t\tList is empty now...!");
	                    
	                    FILE *f2;
	                    f2=fopen("data1.dat","wb");
	                    write_binary(f2);
	                    fclose(f2);
	                    
	                    remove("data.dat");
	                    rename("data1.dat","data.dat");
	                    free(temp);
	                    return;
	                }
	            }
	            else // not a head node
	            {
	            	printf("not a head node");
	            	struct node *prev_node;
	            	while( (temp->next != NULL) && (strcmp(temp->d1.name,str)!=0))
	            	{
	            		printf("abc");
		              prev_node = temp;
		              temp = temp->next;
	            	}
	            	if((strcmp(temp->d1.name,str)==0))
	            	{
	            			printf("abcd");
		            	prev_node->next = prev_node->next->next;
		            	
		              	if(prev_node->next != NULL)
		                {
		                	printf("xxx");
		                    prev_node->next->prev = prev_node;
		                }
		                else
		                {
		                	printf("123");
		                	last = prev_node;
		                }
		                push(temp->d1);
	            	}
	            	
				}
				
			} 
 		} 
		temp=temp->next;
    }
	FILE *f2;
	f2=fopen("data1.dat","wb");
	write_binary(f2);
	fclose(f2);
	
	remove("data.dat");
	rename("data1.dat","data.dat");
	
	if(flag==0)
	{
		printf("\n\t\t\t\t\t\t Element not found...!");
	}
	free(temp);

}*/
/*
void delete1()
{
    int i=0,flag=0;
	FILE *f1;
    f1=fopen("data.dat","rb");
    if(!f1)
    {
        printf("\n\n\t\t\t\t\t\tFile doesn't exist... Please create it\n");
        return;
    }
    read_binary(f1);
    fclose(f1);
    struct node *temp=head;
    char str[11];
    fflush(stdin);
    
    printf("\n\t\t\t\t\t\tEnter the phone number : ");
    gets(str);
    fflush(stdin);
    while(temp!=NULL)
    {
	    if(temp==NULL)
	    {
	    	printf("\n\n\t\t\t\t\t\tThe list is empty...Create it first...!");
		}
	    while (temp!=NULL)
	    {
	        if(strcmp(temp->d1.phone,str)==0)
	        {
	        	flag=1;
	            printf("\n\t\t\t\t\t\tDetails of the customer which you want to delete is...\n\n");
	            printf("\t\t\t\t\t\t  Person Name  :%s\n",temp->d1.name);
	            printf("\t\t\t\t\t\t  Blood group  :%s\n",temp->d1.blood);
	            printf("\t\t\t\t\t\t  Profession   :%s\n",temp->d1.profession);
	            printf("\t\t\t\t\t\t  Address      :%s\n",temp->d1.address);
	            printf("\t\t\t\t\t\t  Phone number :%s\n",temp->d1.phone);
	            
				if(strcmp(head->d1.phone,str)==0)
	            {
	            	
	                //printf("\n\t\t\t\t\t\tIt is at head...! \n");
	                if(head->next != NULL)
	                {
	                    head->next->prev = NULL;
	                    push(head->d1);
	                    head = head->next;
	                }
	                else
	                {
	                	push(head->d1);
	                    head = NULL;
	                    //printf("\n\t\t\t\t\t\tList is empty now...!");
	                    
	                    FILE *f2;
	                    f2=fopen("data1.dat","wb");
	                    write_binary(f2);
	                    fclose(f2);
	                    
	                    remove("data.dat");
	                    rename("data1.dat","data.dat");
	                    free(temp);
	                    return;
	                }
	            }
	            else if(strcmp(head->d1.phone,str)!=0 && head->next == NULL)
	            {
	          		//printf("\n\t\t\t\t\t\t %s not found in the list...!\n",temp->d1.name);
	            }
	            struct node *current,*pre_node;
	            current = head;
	            while(current->next != NULL && strcmp(current->d1.phone,str)!=0)
	            {
	              pre_node = current;
	              current = current->next;
	            }
	            if(strcmp(current->d1.phone,str)==0)
	            {
	            	pre_node->next = pre_node->next->next;
	            	
	              	if(pre_node->next != NULL)
	                {
	                    pre_node->next->prev = pre_node;
	                }
	                else
	                {
	                	last = pre_node;
	                }
	                push(current->d1);
	            }
	            else
	            {
	            	
				}
	                //printf("\n\t\t\t\t\t\t %s not found in the list...!",temp->d1.name);
	 		}
			temp=temp->next;
	    }
		FILE *f2;
		f2=fopen("data1.dat","wb");
		write_binary(f2);
		fclose(f2);
		
		remove("data.dat");
		rename("data1.dat","data.dat");
		if(flag==0)
		{
			printf("\n\t\t\t\t\t\t Element not found...!");
		}
		free(temp);
	}
}*/
