#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include <main.h>
void init(PERSON** head)
{
	*head=(PERSON *)malloc(sizeof(PERSON));
	if(*head==NULL)
	{
		printf("init fail in list.c init\n");
		exit(0);
	}
	(*head)->next=NULL;
	return;
}


PERSON* find_by_name(PERSON* head,char* name )
{
    PERSON* l;
    l=head;
    while(l!=NULL)
	{
		if(strcmp(l->name,name)==0)
		return l;
		else
		l=l->next;
	}
	return l;
}


PERSON* find_by_key(PERSON* head,char* key)
{
	PERSON* l;
	l=head;
	while(l!=NULL)
	{
		if(strcmp(l->key,key)==0)
		return l;
		else
		l=l->next;
	}
	return l;
}


void add(PERSON** head,char* name,char* key,int *usernum)
{
	PERSON* l;
	PERSON* p;
	l=*head;
	(*usernum)++;

	while(l->next!=NULL)
	l=l->next;
	p=(PERSON*)malloc(sizeof(PERSON));
	if(p==NULL)
	{
		printf("malloc fail in list.c add\n");
		exit(0);
	}
	l->next=p;
	strcpy(p->name,name);
	strcpy(p->key,key);
	p->next=NULL;
	return;
 }


void read_from_file(PERSON** head,char* filename,int *usernum)
{
    char n;
	PERSON* l;
	PERSON* p;
    int i;
    FILE* fp;
    l=*head;


    if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("can't open file in list.c read_from_file\n");
		exit(0);
	}
    rewind(fp);
    fread(&n,sizeof(char),1,fp);
    p=(PERSON*)malloc(n*sizeof(PERSON));
    if(p==NULL)
    {
    	printf("p malloc fail in list.c read_from_file");
    	exit(0);
	}
    for(i=0;i<n;i++)
	{
		fread(&p[i],sizeof(PERSON),1,fp);
	   // puts(p[i].name);
		add(head,p[i].name,p[i].key,usernum);
	}
    fclose(fp);
}

void write_to_file(PERSON* head,char* filename)
{
    PERSON* l;
    FILE* fp;
    l=head;
    if((fp=fopen(filename,"wb+"))==NULL)
	{
	   printf("can't open file in list.c write_to_file\n");
	   exit(0);
	}
    rewind(fp);
    l=l->next;
    while(l!=NULL)
	{
		fwrite(l,sizeof(PERSON),1,fp);
		l=l->next;
	}
    fclose(fp);
}

