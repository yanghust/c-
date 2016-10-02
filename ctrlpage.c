#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list.h>
#include <page.h>
#include <ctrlpage.h>
#include <hz.h>
#include <mouse.h>
#include <loginrea.h>
#include <main.h>


//更改密码界面 
void page0(int *page,PERSON *head)
{
	int flag=0;
	char name[20];
	PERSON *cur;
	char key0[20];
	char key1[20];
	char key2[20];
	MOUSE mouse;
	cleardevice();
	draw_changekey();
	while(1)
	{
		which_pressed(&mouse);
		//选中账号输入窗口
		if(mouse.x>266&&mouse.x<490&&mouse.y>18&&mouse.y<56&&mouse.but==1)
		{
		    floodfill(53,19,BLUE);
		    setcolor(RED);
			line(266,18,490,18);
            line(266,56,490,56);	
            input_to_a(54,24,name);
            setcolor(BLUE);
            line(266,18,490,18);
            line(266,56,490,56);
            
		} 
		//选中旧密码输入框
		else if(mouse.x>266&&mouse.x<490&&mouse.y<104&&mouse.y>66&&mouse.but==1)
		{
			floodfill(267,67,BLUE);
			setcolor(RED);
			line(266,66,490,66);
			line(266,104,490,104);
			input_to_b(268,72,key0);
			setcolor(BLUE);
			line(266,66,490,66);
			line(266,104,490,104);
			cur=find_by_name(head,name);
			
			if(cur==NULL)
			{
				puthz(268,106,"没有该账户",16,25,BLUE);
				delay(2000);
				*page=0;
				break;
			}
			if(strcmp(cur->key,key0)!=0)
			{
				puthz(268,106,"旧密码输入错误",16,25,BLUE);
				delay(2000);
				*page=0;
				break;
			}
			else
			{
				flag=1;
				*page=1;
				break;
			}
		}//选中新密码输入窗口
		else if(flag==1&&mouse.x>266&&mouse.x<490&&mouse.y<194&&mouse.y>156&&mouse.but==1)
		{
			floodfill(267,157,BLUE);
			setcolor(RED);
			line(266,156,490,156);
			line(266,194,490,194);
			floodfill(267,157,BLUE);
			input_to_b(268,162,key1);
			setcolor(BLUE);
			line(266,156,490,156);
			line(266,194,490,194);
		}
		//选中确认密码输入窗口
		else if(flag==1&&mouse.x>266&&mouse.x<490&&mouse.y<284&&mouse.y>246&&mouse.but==1)
		{
			floodfill(267,247,BLUE);
			setcolor(RED);
			line(266,246,490,246);
			line(266,284,490,284);
			input_to_b(268,252,key2);
			setcolor(BLUE);
			line(266,246,490,246);
			line(266,284,490,284);
		}
		//按下确认密码键
		else if(mouse.x>220&&mouse.x<522&&mouse.y<184&&mouse.y>146&&mouse.but==1)
		{
			while(mouse.but)                            //模拟按键按下 直到松开按键
			{
				which_pressed(&mouse);
				setcolor(RED);
				line(220,146,522,146);
				line(220,184,522,184);
			}
			setcolor(BLUE);
			line(220,146,522,146);
			line(220,184,522,184);
			if(strcmp(key1,key2)!=0)
			{
				puthz(268,496,"输入的密码不一样",16,25,WHITE);
				delay(2000);
				*page=0;
				break;
			}
			else
			{
			strcpy(cur->key,key1);
			*page=3;
			break;
			}
		}
		else if(mouse.x>600&&mouse.x<640&&mouse.y<40&&mouse.y>0&&mouse.but==1)
		{
			*page=20;
			break;
		}
	}
	cleardevice();


}

//登录界面
void page1(int *page,PERSON *head)
{
    MOUSE mouse;
    PERSON *cur;
    char name[20];
    char key[20];
    cleardevice();
	draw_login();
	while(1)
	{
		which_pressed(&mouse);
		//选中账号输入框
		if(mouse.x>220&&mouse.x<522&&mouse.y<184&&mouse.y>146&&mouse.but==1)
		{
			floodfill(221,147,BLUE);
			setcolor(RED);
			line(220,146,522,146);
			line(220,184,522,184);
			input_to_a(222,152,name);
			setcolor(BLUE);
			line(220,146,522,146);
			line(220,184,522,184);

		}
		//选中密码输入窗口
		else if(mouse.x>220&&mouse.x<522&&mouse.y<298&&mouse.y>260&&mouse.but==1)
		{
			floodfill(221,261,BLUE);
			setcolor(RED);
			line(220,260,522,260);
			line(220,298,522,298);
			input_to_b(222,266,key);
			setcolor(BLUE);
			line(220,260,522,260);
			line(220,298,522,298);
		}
		//选中确认键
		else if(mouse.x>290&&mouse.x<370&&mouse.y<398&&mouse.y>360&&mouse.but==1)
		{
			while(mouse.but)                            //模拟按键按下直到松开按键
			{
				which_pressed(&mouse);
				setcolor(RED);
				line(220,260,522,260);
				line(220,298,522,298);
			}
			setcolor(BLUE);
			line(220,260,522,260);
			line(220,298,522,298);
			cur=find_by_name(head,name);
			if(strlen(name)==0)
			{
				puthz(222,186,"请输入账号",16,25,WHITE);
				delay(2000);
				*page=1;
				break;
			}
			if(cur==NULL)
			{
				puthz(220,303,"没有该账号，请注册",16,25,BLUE);
				delay(2000);
				*page=1;
				break;
			}
			if(strcmp(cur->key,key)==0)
			{
				*page=3;
				break;
			}
			else
			{
				puthz(220,303,"密码错误",16,25,BLUE);
				delay(2000);
				*page=1;
				break;
			}
		}
		//选中修改密码键
		else if(mouse.x>68&&mouse.x<180&&mouse.y<450&&mouse.y>412&&mouse.but==1)
		{
			while(mouse.but)                            //模拟按键按下直到松开按键
			{
				which_pressed(&mouse);
				setcolor(RED);
				line(68,412,180,412);
				line(68,450,180,450);
			}
			setcolor(BLUE);
			line(68,412,180,412);
			line(68,450,180,450);
			*page=0;
			break;
		}
		//选中注册键
		else if(mouse.x>490&&mouse.x<554&&mouse.y<450&&mouse.y>412&&mouse.but==1)
		{
			while(mouse.but)                            //模拟按键按下直到松开按键
			{
				which_pressed(&mouse);
				setcolor(RED);
				line(490,412,554,412);
				line(490,450,554,450);
			}
			setcolor(BLUE);
			line(490,412,554,412);
			line(490,450,554,450);
			*page=2;
			break;
		}
		else if(mouse.x>600&&mouse.x<640&&mouse.y<40&&mouse.y>0&&mouse.but==1)
		{
			*page=20;
			break;
		}
	}

	cleardevice();
}

//注册界面
void  page2(int *page,PERSON **head,int *usernum)
{
	char name0[30];
	char key0[30];
	char key1[30];
	MOUSE mouse;
	cleardevice();
	draw_zhuce();
	while(1)
	{
		which_pressed(&mouse);//循环读取鼠标位置及按键状态
		if(mouse.x>238&&mouse.x<508&&mouse.y<184&&mouse.y>146&&mouse.but==1)//选中账号输入窗口，输入账号
		{
			floodfill(239,147,BLUE);
			setcolor(RED);
			line(238,146,508,146);
			line(238,184,508,184);
			input_to_a(240,152,name0);
			setcolor(BLUE);
			line(238,146,508,146);
			line(238,184,508,184);
		}
		else if(mouse.x>238&&mouse.x<508&&mouse.y<242&&mouse.y>204&&mouse.but==1)//选中密码输入窗口,输入密码
		{
			floodfill(239,205,BLUE);
			setcolor(RED);
			line(238,204,508,204);
			line(238,242,508,242);
			input_to_b(240,210,key0);
			setcolor(BLUE);
			line(238,204,508,204);
			line(238,242,508,242);
		}
		else if(mouse.x>238&&mouse.x<508&&mouse.y<262&&mouse.y>300&&mouse.but==1)//选中确认密码窗口，输入确认密码
		{
			floodfill(239,301,BLUE);
			setcolor(RED);
			line(238,262,508,262);
			line(238,300,508,300);
			input_to_b(240,268,key1);
			setcolor(BLUE);
			line(238,262,508,262);
			line(238,300,508,300);
		}
		else if(mouse.x>160&&mouse.x<220&&mouse.y<398&&mouse.y>360&&mouse.but==1)//选中返回窗口
		{
			*page=1;//返回到第一个界面
			break;
		}
		else if(mouse.x>460&&mouse.x<520&&mouse.y<398&&mouse.y>360&&mouse.but==1)//选中注册窗口
		{
			while(mouse.but)                            //模拟按键按下直到松开按键
			{
				which_pressed(&mouse);
				setcolor(RED);
				line(460,360,520,360);
				line(460,398,520,398);
			}
			setcolor(BLUE);
			line(460,360,520,360);
			line(460,398,520,398);
			if(strlen(name0)==0)
			{
				puthz(240,186,"请输入账号",16,25,WHITE);
				delay(2000);
				*page=2;
				break;
			}
			if(strcmp(key0,key1)!=0)
			{
				puthz(245,310,"两次输入的密码不同，请重新输入",16,20,WHITE);
			}
			else
			{
				add(head,name0,key0,usernum);
				*page=1;                                                     //跳转到程序的第一个界面
				break;
			}
		}
		else if(mouse.x>600&&mouse.x<640&&mouse.y<40&&mouse.y>0&&mouse.but==1)
		{
			*page=20;
			break;
		}
	}
	cleardevice();

}


void page3(int *page,int* kemu)
{
    MOUSE mouse;
    char KE[2][20]={"科目一","科目二"};
    cleardevice();
	draw_choice();
	//显示开始时的科目与车辆
	while(1)
	{
		which_pressed(&mouse);
	   //选中科目选择左键
		if(mouse.x>8&&mouse.x<48&&mouse.y<306&&mouse.y>48&&mouse.but==1)
		{
			(*kemu)--;
			if(*kemu<0)
			*kemu=1;
			floodfill(60,280,BLUE);
			puthz(60,280,KE[*kemu],24,30,BLUE);
		}
		//选中科目选择右键
		else if(mouse.x>240&&mouse.x<278&&mouse.y<306&&mouse.y>270&&mouse.but==1)
		{
			*kemu=((*kemu)++)%2;
			floodfill(60,280,BLUE);
			puthz(60,280,KE[*kemu],24,30,WHITE);
		}
		//选中车辆选择左键
		else if(mouse.x>345&&mouse.x<383&&mouse.y<306&&mouse.y>270&&mouse.but==1)
		{
			//换图片
		}
		//选中车辆选择右键
		else if(mouse.x>578&&mouse.x<618&&mouse.y<306&&mouse.y>270&&mouse.but==1)
		{
			//换图片
		}
		//选中确认键
		else if(mouse.x>480&&mouse.x<540&&mouse.y<400&&mouse.y>438&&mouse.but==1)
		{
			*page=4;
			break;
		}
		else if(mouse.x>600&&mouse.x<640&&mouse.y<40&&mouse.y>0&&mouse.but==1)
		{
			*page=20;
			break;
		}
	}
	cleardevice();
	
}

void  page4(int *page,int* kemu)
{
	char name[20];
	char KE[2][20]={"科目一","科目二"};
	MOUSE mouse;
	cleardevice();
	draw_sure_beforetest();
	
	puthz(278,119,name,24,30,BLUE);                                                       //显示账号
	puthz(278,203,KE[*kemu],24,30,BLUE);                                                                                  //显示选择的考试科目
	while(1)
	{
		which_pressed(&mouse);
		if(mouse.x>460&&mouse.x<520&&mouse.y<420&&mouse.y>382&&mouse.but==1)//选中确认键
		{
			while(mouse.but)                            //模拟按键按下直到松开按键
			{
				which_pressed(&mouse);
				setcolor(RED);
				line(460,382,520,382);
				line(460,420,520,420);
			}
			setcolor(BLUE);
			line(460,382,520,382);
			line(460,420,520,420);
			*page=5;//跳转到相应考试界面
			break;
		}
		else if(mouse.x>160&&mouse.x<220&&mouse.y<420&&mouse.y>382&&mouse.but==1)//选中返回键
		{
			while(mouse.but)                            //模拟按键按下直到松开按键
			{
				which_pressed(&mouse);
				setcolor(RED);
				line(160,382,220,382);
				line(160,420,220,420);
			}
			setcolor(BLUE);
			line(160,382,220,382);
			line(160,420,220,420);
			*page=3;//跳回科目选择界面
			break;
		}
		else if(mouse.x>600&&mouse.x<640&&mouse.y<40&&mouse.y>0&&mouse.but==1)
		{
			*page=20;
			break;
		}
	}
	cleardevice();

}

