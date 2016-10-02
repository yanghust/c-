#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <mouse.h>
#include <hz.h>
#include <list.h>
#include <loginrea.h>
#include <page.h>
#include <ctrlpage.h>
#include <main.h>

void main()
{
	
    int kemu=0; 
	PERSON *head,*l,*cur;
	int usernum=0;
	char name[20];
	char key[20]; 
	int page=1;
	int gd=VGA;
	int gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	

	init(&head);
	mouse_use_init();
	//read_from_file(&head,"c:\\borlandc\\userinfo.txt",&usernum);
	cleardevice();
	setcolor(BLUE);
	while(1)
	{
		if(page==0)
		page0(&page,head);
		else if(page==1)
		page1(&page,head);
		else if(page==2)
		page2(&page,&head,&usernum);
		else if(page==3)
		page3(&page,&kemu);
		else if(page==4)
		page4(&page,&kemu);
		else
		break;

	}
}
