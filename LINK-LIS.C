#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct student
{
    int roll;
    char name[20];
    struct student *next;
};

struct student *head=NULL;
int len;

void Append();
void Abegin();
void Apos();

void Dbegin();
void Dend();
void Dpos();

int length();
void display();
void search();

void main()
{
    int ch;
    clrscr();

    while(1)
    {
	printf("\n   ***STUDENT DATA***");
	printf("\n 1. Create list ");
	printf("\n 2. Add roll at begining ");
	printf("\n 3. Add roll at particular position \n");
	printf("\n 4. Delete roll from begining ");
	printf("\n 5. Delete roll from end ");
	printf("\n 6. Delete roll at particular position \n");
	printf("\n 7. Display list");
	printf("\n 8. Length of list ");
	printf("\n 9. Search roll in list \n");
	printf("\n 10. Exit ");

	printf(" \n\n Enter your choice :-");
	scanf("%d",&ch);

	switch(ch)
	{
	    case 1: Append();
		    break;

	    case 2: Abegin();
		    break;

	    case 3: Apos();
		    break;

	    case 4: Dbegin();
		    break;

	    case 5: Dend();
		    break;

	    case 6: Dpos();
		    break;

	    case 7: display();
		    break;

	    case 8: len=length();
		    printf("\nLength of the list = %d\n",len);
		    break;

	    case 9: search();
		    break;

	    case 10: exit(0);


	    default: printf("Invalid input \n \n");

	}

    }

}
void Append()
{
    struct student* temp;
    temp = (struct student*)malloc(sizeof(struct student));

    printf("\n Enter Student roll no:-");
    scanf("%d",&temp->roll);
    printf("\n Enter Student name:-");
    scanf("%s",&temp->name);
    temp->next = NULL;

    if(head==NULL)
    {
	head=temp;
    }
    else
    {
	struct student *p;
	p=head;

	while(p->next!=NULL)
	{
	    p=p->next;
	}
	p->next=temp;
    }
}


int length()
{
    int count=0;
    struct student* temp;
    temp=head;

    while(temp!=NULL)
    {
      count++;
      temp=temp->next;
    }
    return count;
}

void display()
{
    struct student* temp;
    temp=head;

    if(temp==NULL)
    {
	printf("\n List is empty \n");
    }
    else
    {
	while(temp!=NULL)
	{
	    printf("\nRoll no %d ",temp->roll);
	    printf("is %s \n",temp->name);
	    temp=temp->next;

	}
	printf("\n");

    }
}

void Abegin()
{
    struct student *temp;
    temp = (struct student*)malloc(sizeof(struct student));

    printf("\n Enter Student roll no:-");
    scanf("%d",&temp->roll);
    printf("\n Enter Student name:-");
    scanf("%s",&temp->name);
    temp->next = NULL;

    if(head==NULL)
    {
	head=temp;
    }
    else
    {
    temp->next=head;
    head=temp;
    }
}

void Apos()
{
    struct student *temp,*ptr;
    int i,pos;
    temp = (struct student*)malloc(sizeof(struct student));

    printf("\n Enter position :-");
    scanf("%d",&pos);

    printf("\n Enter Student roll no:-");
    scanf("%d",&temp->roll);
    printf("\n Enter Student name:-");
    scanf("%s",&temp->name);
    temp->next = NULL;

    if(pos==1)
    {
	temp->next=head;
	head=temp;
    }

    else
    {
	ptr=head;
	for(i=1;i<pos-1;i++)
	{
	    ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next=temp;

    }

}

void Dbegin()
{
    struct student *temp;

    if(head==NULL)
    {
	printf("\n No elements for deletion");
    }

    else
    {
    temp=head;
    head=head->next;
    free(temp);
    }
}

void Dend()
{
    struct student *temp,*ptr;

    if(head==NULL)
    {
	printf("\n No elements for deletion");
    }

    else if(head->next==NULL)
    {
	ptr=head;
	head=NULL;
	free (ptr);
    }

    else
    {
	ptr=head;

	while(ptr->next!=NULL)
	{
	    temp=ptr;
	    ptr=ptr->next;
	}
	temp->next=NULL;
	free(ptr);

    }

}



void Dpos()
{
    struct student *temp,*ptr;
    int i,pos;

    if(head==NULL)
    {
	printf("\n No elements for deletion \n");
    }

    else
    {
	printf("\n Enter position :-");
	scanf("%d",&pos);

	if(pos==1)
	{
	    Dbegin();
	}

	else if(pos>len)
	{
	    printf("\n Position given does not exist\n");
	}

	else
	{
	    ptr=head;
	    for(i=1;i<pos;i++)
	    {
		temp=ptr;
		ptr=ptr->next;
	    }
	    temp->next=ptr->next;
	    free(ptr);
	}
    }
}

void search()
{
    struct student *temp;
    int rol,count=0;

    printf("\nEnter roll number u want to search :-");
    scanf("%d",&rol);

    temp=head;
    while(temp!=NULL)
    {
	count++;
	if(temp->roll==rol)
	{
	    printf("\n Roll no. found at position = %d ",count);
	    return;
	}
	temp=temp->next;
    }
       else
	{
	    printf("\n Roll no. not found in the list");
	}


}
