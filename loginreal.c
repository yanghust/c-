#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <loginrea.h>
#include <bios.h>
#include <main.h>
void input_to_a(int x,int y,char* a)//可见输入内容的输入账号 
{
    int i,n,key;
    i=0;
    n=0;
    while(1)
    {
        if(kbhit())
        {
            key=bioskey(0);
            if(key==ENTER)
            {
                break;
            }
            if(key==BACKSPACE)
            {
                i--;
                n--;
                if(i<0)
                    i=0;
                if(n<0)
                    n=0;
                setfillstyle(1,WHITE);
                bar(x+n*30,y-5,x+30+n*30,y+31);
                a[i]='\0';
            }
            else if(n>8)
            {
            }
            else
            {
                a[i]=key;
                a[i+1]='\0';
                setcolor(BLUE);
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
                outtextxy(x+n*30,y,&a[i]);
                n++;
                i++;
            }
        }
    }
}

void input_to_b(int x,int y,char* a)//不可见输入内容的输入密码及确认密码 
{
    int i,n,key;
    i=0;
    n=0;
    while(1)
    {
        if(kbhit())
        {
            key=bioskey(0);
            if(key==ENTER)
            {
                break;
            }
            if(key==BACKSPACE)
            {
                i--;
                n--;
                if(i<0)
                    i=0;
                if(n<0)
                    n=0;
                setfillstyle(1,WHITE);
                bar(x+n*30,y-5,x+30+n*30,y+31);
                a[i]='\0';
            }
            else if(n>8)
            {
            }
            else
            {
                a[i]=key;
                a[i+1]='\0';
                setcolor(BLUE);
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				outtextxy(x+n*30,y,"*");
                n++;
                i++;
            }
        }
    }
}


