#include <graphics.h>
#include <dos.h>
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <mouse.h>
#include <main.h>


int reset_mouse(void)                            //安装鼠标驱动     ireg.s.ax=0
{
    union REGS ireg,oreg;

    ireg.x.ax=0;
    int86(0x33,&ireg,&oreg);
    return ((oreg.x.ax==0)?0:1);
}
void show_mouse(void)                    //设置鼠标可见  ireg.x.ax=1 
{
    union REGS ireg;
    ireg.x.ax=1;
    int86(0x33,&ireg,&ireg);
}

void init_mouse(void)                         //鼠标初始化，安装驱动，并使鼠标可见 
{
    if(reset_mouse())
    {
        show_mouse();
    }
    else
        printf("init mouse fail\n");
}

void hide_mouse(void)                              //隐藏鼠标,ireg.x.ax=2 
{
    union REGS ireg;
    ireg.x.ax=2;
    int86(0x33,&ireg,&ireg);
}

int which_pressed(MOUSE *mouse)                                 //读取按键状态，那个键被按下，并读取鼠标位置  ireg.x.ax=3 
{
    union REGS ireg,oreg;
    ireg.x.ax=3;
    int86(0x33,&ireg,&oreg);
    mouse->x=oreg.x.cx;
    mouse->y=oreg.x.dx;
    mouse->but=oreg.x.bx;
    return (oreg.x.bx);
}
void get_xy(MOUSE* mouse)                       //读取鼠标位置   ireg.x.ax=3 
{
    union REGS ireg,oreg;
    ireg.x.ax=3;
    int86(0x33,&ireg,&oreg);

    mouse->x=oreg.x.cx;
    mouse->y=oreg.x.dx;
}

void set_xy(int x,int y)                          //设置鼠标位置  ireg.x.ax=4 
{
    union REGS ireg;
    ireg.x.ax=4;
    ireg.x.cx=x;
    ireg.x.dx=y;
    int86(0x33,&ireg,&ireg);
}


int pressed_status(MOUSE* mouse,int button)      //返回button键自上次调用以来按钮按下的次数，存储按钮按下的坐标 
{
    union REGS ireg,oreg;
    ireg.x.ax=5;
    ireg.x.bx=button;
    int86(0x33,&ireg,&oreg);
    mouse->x=oreg.x.cx;
    mouse->y=oreg.x.dx;
    mouse->but=oreg.x.ax;
    return (oreg.x.bx);
}
void set_xy_range(int xmin,int xmax,int ymin,int ymax)    //设置鼠标有效范围   入口参数ireg.x.ax=7,ireg.x.cx=xmin ireg.x.dx=xmax
{                                                         //ireg.x.ax=8  ireg.x.cx=ymin  ireg.x.dx=ymax
    union REGS ireg;
    ireg.x.ax=7;
    ireg.x.cx=xmin;
    ireg.x.dx=xmax;
    int86(0x33,&ireg,&ireg);

    ireg.x.ax=8;
    ireg.x.cx=ymin;
    ireg.x.dx=ymax;
    int86(0x33,&ireg,&ireg);
}

void set_graphic_cursor(int x,int y,unsigned int far* pattern)   //设置鼠标形状  入口参数   ireg.x.ax=9 ireg.x.bx=x  ireg.x.cx=y  ireg.x.dx=FP_OFF(pattern)  
{                                                                          //isreg.x.es=FP_SEG(pattern)
    union REGS ireg;
    struct SREGS isreg;
    ireg.x.ax=9;
    ireg.x.bx=x;
    ireg.x.cx=y;
    ireg.x.dx=FP_OFF(pattern);
    isreg.es=FP_SEG(pattern);
    int86x(0x33,&ireg,&ireg,&isreg);
}
void mouse_use_init()                 //鼠标使用初始化  
{
	unsigned int cursor[32]={                               //鼠标形状模型
0x3fff,0x1fff,0x0fff,0x07ff,0x03ff,0x01ff,0x00ff,0x007f,
0x003f,0x001f,0x01ff,0x10ff,0x30ff,0xf87f,0xf87f,0xfc3f,
0x0000,0x4000,0x6000,0x7000,0x7800,0x7c00,0x7e00,0x7f00,
0x7f80,0x7fc0,0x6c00,0x4600,0x0600,0x0300,0x0300,0x0180};
    delay(1);     //初始化鼠标，装驱动，使之可见 
    init_mouse();
    set_xy_range(1,639,1,479);//设置有效范围 
    set_graphic_cursor(5,1,cursor);//设置鼠标形状   5,1,pattern
    set_xy(320,240);//设置鼠标初始位置 
    show_mouse();
}
