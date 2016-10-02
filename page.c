#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <page.h>

void draw_zhuce()
{
	//画叉叉键
	setcolor(WHITE);
	rectangle(600,0,640,40);
	line(600,40,640,0);
	line(600,0,640,40); 
	
	
	setfillstyle(SOLID_FILL,WHITE);
    setcolor(BLUE);
	//画注册新账号窗口 
	arc(88,61,90,270,19);
	arc(552,61,-90,90,19);
	line(88,42,552,42);
	line(88,80,552,80);
	floodfill(88,51,BLUE);
	puthz(237,47,"注册新账号",24,30,BLUE);
	//画账号窗口 
	arc(68,165,90,270,19);
	arc(188,165,-90,90,19);
	line(68,146,188,146);
	line(68,184,188,184);
	floodfill(68,165,BLUE);
	puthz(88,151,"账号",24,30,BLUE);
	//画密码窗口 
	arc(68,223,90,270,19);
	arc(188,223,-90,90,19);
	line(68,204,188,204);
	line(68,242,188,242);
	floodfill(68,223,BLUE);
	puthz(88,209,"密码",24,30,BLUE);
	//画确认密码窗口 
	arc(68,281,90,270,19);
	arc(188,281,-90,90,19);
	line(68,262,188,262);
	line(68,300,188,300);
	floodfill(68,281,BLUE);
	puthz(80,267,"确认密码",24,30,BLUE);
	//画账号输入窗口 
	arc(238,165,90,270,19);
	arc(508,165,-90,90,19);
	line(238,146,508,146);
	line(238,184,508,184);
    floodfill(238,165,BLUE);
	//画密码输入窗口
	arc(238,223,90,270,19);
	arc(508,223,-90,90,19);
	line(238,204,508,204);
	line(238,242,508,242);
	floodfill(238,223,BLUE);
	//画确认密码输入窗口
	arc(238,281,90,270,19);
	arc(508,281,-90,90,19);
	line(238,262,508,262);
	line(238,300,508,300);
	floodfill(238,281,BLUE);
	//画注册窗口
	arc(460,379,90,270,19);
	arc(520,379,-90,90,19);
	line(460,360,520,360);
	line(460,398,520,398); 
	floodfill(460,379,BLUE);
	puthz(462,365,"注册",24,30,BLUE);
	//画返回窗口 
	arc(160,379,90,270,19);
	arc(220,379,-90,90,19);
	line(160,360,220,360);
	line(160,398,220,398); 
	floodfill(160,379,BLUE);
	puthz(162,365,"返回",24,30,BLUE);
	
	
}

void draw_sure_beforetest()
{
	//画叉叉键
	setcolor(WHITE);
	rectangle(600,0,640,40);
	line(600,40,640,0);
	line(600,0,640,40); 
	
	setfillstyle(SOLID_FILL,WHITE);
    setcolor(BLUE);
	//画主题窗口
	arc(124,38,90,270,19);
	arc(472,38,-90,90,19);
	line(124,19,472,19);
	line(124,57,472,57);
	floodfill(124,38,BLUE);
	puthz(220,24,"考前信息确认",24,30,BLUE);
	//画账号窗口
	arc(90,133,90,270,19);
	arc(174,133,-90,90,19);
	line(90,114,174,114);
	line(90,152,174,152);
	floodfill(90,133,BLUE);
	puthz(100,119,"账号",24,30,BLUE);
	//画科目窗口
	arc(90,217,90,270,19);
	arc(174,217,-90,90,19);
	line(90,198,174,198);
	line(90,236,174,236);
	floodfill(90,217,BLUE);
	puthz(100,203,"科目",24,30,BLUE);
	//画账号显示窗口
	arc(276,133,90,270,19);
	arc(564,133,-90,90,19);
	line(276,114,564,114);
	line(276,152,564,152);
	floodfill(276,133,BLUE);
	//画科目显示窗口
	arc(276,217,90,270,19);
	arc(564,217,-90,90,19);
	line(276,198,564,198);
	line(276,236,564,236);
	floodfill(276,217,BLUE); 
	//画确认键
	arc(460,401,90,270,19);
	arc(520,401,-90,90,19);
	line(460,382,520,382);
	line(460,420,520,420);
	floodfill(460,401,BLUE);
	puthz(462,387,"确认",24,30,BLUE);
	//画返回窗口 
	arc(160,401,90,270,19);
	arc(220,401,-90,90,19);
	line(160,382,220,382);
	line(160,420,220,420);
	floodfill(160,401,BLUE);
	puthz(162,387,"返回",24,30,BLUE); 
}


void draw_choice()
{        
    //画叉叉键
	setcolor(WHITE);
	rectangle(600,0,640,40);
	line(600,40,640,0);
	line(600,0,640,40); 
	
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,WHITE);
    //画科目选择主题框 
    line(58,44,246,44);
    line(58,82,246,82);
    arc(58,63,90,270,19);
    arc(246,63,270,90,19);
    floodfill(58,63,BLUE);
    puthz(60,49,"考试科目选择",24,33,BLUE);
    //画考试车辆选择框 
    line(394,44,590,44);
    line(394,82,590,82);
    arc(394,63,90,270,19);
    arc(590,63,270,90,19);
    floodfill(394,63,BLUE);
    puthz(396,49,"考试车辆选择",24,33,BLUE);
    //画显示窗口 
    rectangle(58,202,226,370);
    floodfill(59,203,BLUE);
    rectangle(394,202,570,370);
    floodfill(395,203,BLUE);

    //画按键窗口 
    rectangle(8,270,48,306);
    floodfill(9,271,BLUE);
    line(36,274,36,300);
    line(36,300,16,287);
    line(16,287,36,274);


    rectangle(240,270,278,306);
    floodfill(241,271,BLUE);
    line(250,274,250,300);
    line(250,300,270,287);
    line(270,287,250,274);

    rectangle(345,270,383,306);
    floodfill(346,271,BLUE);
    line (373,274,373,300);
    line(373,300,353,287);
    line(353,287,373,274);


    rectangle(578,270,618,306);
    floodfill(579,271,BLUE);
    line(588,274,588,300);
    line(588,300,608,287);
    line(608,287,588,274);
    //画确认窗口 
    arc(480,419,90,270,19);
    arc(540,419,-90,90,19);
    line(480,400,540,400);
    line(480,438,540,438);
    floodfill(480,419,BLUE);
    puthz(482,405,"确认",24,30,BLUE);
}


void draw_login()
{   
    //画叉叉键
	setcolor(WHITE);
	rectangle(600,0,640,40);
	line(600,40,640,0);
	line(600,0,640,40); 
	      
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,WHITE);
    //画科目二科目三驾考模拟系统主题框 
    line(85,46,540,46);
    line(85,84,540,84);
    arc(85,65,90,270,19);
    arc(540,65,270,90,19);
    floodfill(85,65,BLUE);
    puthz(87,51,"科目二科目三驾考模拟系统",24,40,BLUE);
    //画账号框 
    line(64,184,140,184);
    line(64,146,140,146);
    arc(64,165,90,270,19);
    arc(140,165,270,90,19);
    floodfill(64,165,BLUE);
    puthz(66,151,"账号",24,40,BLUE);
    //画账号输入框 
    line(220,146,522,146);
    line(220,184,522,184);
    arc(220,165,90,270,19);
    arc(522,165,270,90,19);
    floodfill(220,165,BLUE);
    //画密码框 
    line(64,260,140,260);
    line(64,298,140,298);
    arc(64,279,90,270,19);
    arc(140,279,270,90,19);
    floodfill(64,279,BLUE);
    puthz(66,265,"密码",24,40,BLUE);
    //画密码输入显示框 
    line(220,260,522,260);
    line(220,298,522,298);
    arc(220,279,90,270,19);
    arc(522,279,270,90,19);
    floodfill(220,279,BLUE);
    //画确认键框 
    line(290,360,370,360);
    line(290,398,370,398);
    arc(290,379,90,270,19);
    arc(370,379,270,90,19);
    floodfill(290,379,BLUE);
    puthz(292,365,"确认",24,40,BLUE);
    //画修改密码键 
    line(68,412,180,412);
    line(68,450,180,450);
    arc(68,431,90,270,19);
    arc(180,431,270,90,19);
    floodfill(68,431,BLUE);
    puthz(70,417,"修改密码",24,30,BLUE);

    //画注册键 
    line(490,412,554,412);
    line(490,450,554,450);
    arc(490,431,90,270,19);
    arc(554,431,270,90,19);
    floodfill(490,431,BLUE);
    puthz(492,417,"注册",24,40,BLUE);


}


void draw_changekey()
{   
    //画叉叉键
	setcolor(WHITE);
	rectangle(600,0,640,40);
	line(600,40,640,0);
	line(600,0,640,40); 
	      
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,WHITE);
    //画账号输入窗口 
    line(52,18,186,18);
    line(52,56,186,56);
    arc(52,37,90,270,19);
    arc(186,37,270,90,19);
    floodfill(52,37,BLUE);
    puthz(54,23,"账号",24,33,BLUE);

    line(266,18,490,18);
    line(266,56,490,56);
    arc(266,37,90,270,19);
    arc(490,37,270,90,19);
    floodfill(266,37,BLUE);
    
    //画旧密码框.下同 
    line(52,66,186,66);
    line(52,104,186,104);
    arc(52,85,90,270,19);
    arc(186,85,270,90,19);
    floodfill(52,85,BLUE);
    puthz(54,71,"旧密码",24,33,BLUE);

    line(266,66,490,66);
    line(266,104,490,104);
    arc(266,85,90,270,19);
    arc(490,85,270,90,19);
    floodfill(266,85,BLUE);


    line(52,156,186,156);
    line(52,194,186,194);
    arc(52,175,90,270,19);
    arc(186,175,270,90,19);
    floodfill(52,175,BLUE);
    puthz(54,161,"新密码",24,33,BLUE);

    line(266,156,490,156);
    line(266,194,490,194);
    arc(266,175,90,270,19);
    arc(490,175,270,90,19);
    floodfill(266,175,BLUE);

    line(52,246,186,246);
    line(52,284,186,284);
    arc(52,265,90,270,19);
    arc(186,265,270,90,19);
    floodfill(52,265,BLUE);
    puthz(54,251,"确认密码",24,22,BLUE);

    line(266,246,490,246);
    line(266,284,490,284);
    arc(266,265,90,270,19);
    arc(490,265,270,90,19);
    floodfill(266,265,BLUE);

    line(260,404,446,404);
    line(260,442,446,442);
    arc(260,423,90,270,19);
    arc(446,423,270,90,19);
    floodfill(260,423,BLUE);
    puthz(262,409,"确认更改密码",24,33,BLUE);

}

