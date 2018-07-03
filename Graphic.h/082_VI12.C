#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void main()
{
	int gd=DETECT,gm,i,j;
	initgraph(&gd,&gm,"..\\bgi");

       for(i=0;i<=1000;i++)
	{
	cleardevice();//We clear the previous screen
	outtextxy((getmaxx()/2)-30,getmaxy()/2,"Loading..");
	arc(getmaxx()/2,getmaxy()/2,0+i,90+i,50);
	delay(10);     //Since motion is fast we specify delay so here specify delay of 10 milliseconds
	//delay is specified in dos.h
	}
	for(i=0;i<=360;i++)
{
cleardevice();
arc(getmaxx()/2-50,(getmaxy()/2),0,i,50);
delay(10);
}
cleardevice();

for(j=0,i=1;i<=360;i++,j++)
{
	cleardevice();

	setcolor(RED);
	line((getmaxx()/2)-50+j,(getmaxy()/2)+50,(getmaxx()/2)+0.872664,(getmaxy()/2)+50);
	setcolor(WHITE);
	arc((getmaxx()/2-50)+j,getmaxy()/2,-90,270-i,50);
	delay(10);
}
outtextxy(getmaxx()/2+75,getmaxy()/2+60,"Cicumfernce=2(pi)r");
delay(3000);

	cleardevice();
       for(i=0;i<=300&&!kbhit();i++)
	{
	//here we dont use clear device because we all curves in spiral
	setcolor(BROWN);
	arc(getmaxx()/2-30,getmaxy()/2,0+i,90+i,i/2);
	delay(10);//So as to percieve the motion
	}
	for(i=0;i<=300&&!kbhit();i++)
	{
	setcolor(WHITE);
	arc(getmaxx()/2,getmaxy()/2,0+i,90+i,i/2);
	delay(10);
	}
	for(i=0;i<=300&&!kbhit();i++)
	{
	setcolor(GREEN);
	arc(getmaxx()/2+30,getmaxy()/2,0+i,90+i,i/2);
	delay(10);
	}
	setcolor(RED);
	outtextxy(getmaxx()/2-60,getmaxy()/2+150,"Lets Spread Peace");


	getch();

	closegraph();

}


