#include <STC15W.h>
#include <intrins.h>  //给_nop_用的
#define uchar unsigned char //后面代码中的unsigned char 用uchar表示
#include <ws2812.h>		//自定函数

///函数声明**********
void Delay(void);
void LedRgb(unsigned char a,unsigned char b, unsigned char c);
void Delay100ms(void);
void msxz(void);
void ysxz(void);
void Delay50ms();
void offRGB();
void onRGB();
///变量声明**********
uchar r=0;
uchar g=0;
uchar b=0;
uchar i=0;///循环计次用
uchar ms=0;
uchar x=0;
uchar y=0;
uchar ld=50;
float ld1=0;
uchar ys=1;


//********************自定义*************************//
uchar code ysR[]=
{
	255,255,0,0,255,0,0,255,255,255,0,0,255,255,255,0,0,255,0,0,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,0,0
};

uchar code ysG[]=
{
	128,128,0,255,255,255,0,128,128,128,255,255,255,0,255,255,0,128,0,255,255,0,0,0,255,255,0,255,255,0,0,0,0,0,255,255,0,255,255,0,255,0,255,255,0
};

uchar code ysB[]=
{
	0,0,255,0,0,0,255,0,0,0,255,0,0,0,0,0,255,0,255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,255
};
//*********************************************//
void color (uchar c)//预设的七个颜色	输入1-7
{
		if(c==0){r=250; 	g=255;	b=250;	}//白
		if(c==1){r=255; 	g=000;	b=000;	}//绿
		if(c==2){r=255; 	g=150;	b=000;	}
		if(c==3){r=240;		g=255;	b=000;	}//黄
		if(c==4){r=150;		g=255;	b=000;	}
		if(c==5){r=000;   g=255;	b=000;	}//红
		if(c==6){r=000;   g=255;	b=150;	}
		if(c==7){r=000;   g=255;	b=250;	}//紫
		if(c==8){r=000;   g=150;	b=250;	}
		if(c==9){r=000;   g=000;	b=255;	}//蓝
		if(c==10){r=150;   g=000;	b=255;	}//蓝
		if(c==11){r=255; 	g=000;	b=255;	}//青
		
}

//*********************************************//

/*
sbit led = P5^4;	//接的led
*/
sbit s2 = P5^5;		// s2 左
sbit s3 = P3^3;		// s3 中
sbit s4 = P3^2;		// s4 右


void main()
{
	while(1)
	{	
		msxz();//按钮s3 模式选择
		
///////////////////////////////////////////////////////////////////////
		
		if (ms==0)//关灯
		{
			offRGB();
		}
		
//////////////////////////////////////////////////////////////////////////
		
		if(ms==1)//预设
		{
			LedRgb(90,0,0);
			LedRgb(0,0,0);
			LedRgb(0,0,0);
			for (i=0;i<50;i++)
			{
				LedRgb(ysR[i],ysB[i],ysG[i]);
			}
			Delay100ms();
		}
		
				
		if(ms==2)			
		{
			ysxz();
			color(ys);
			for (i=0;i<50;i++)
			{
				LedRgb(r,g,b);
			}
			Delay100ms();
		}
//////////////////////////////////////////////////////////////////////////
		
		if(ms==4)
		{
			LedRgb(90,0,0);
			LedRgb(0,90,0);
			LedRgb(0,0,0);
			
			for (i=0;i<50;i++)
			{
				LedRgb(r,g,b);
			}
			Delay100ms();
		}
		
/////////////////////////////////////////////////////////////////////////
		
		if (ms==3&&y!=1)
		{
			LedRgb(0,0,0);
			LedRgb(0,90,0);
			LedRgb(0,0,0);
			r=255;
			g=0;
			b=0;
					
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
			
				g+=1;
				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();
			}
					
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
				r-=1;
						
				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();
				}
					//////////////////////
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
				b+=1;
				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();
			}
					
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
				g-=1;

				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();
			}
		/////////////////////////////
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
						
				r+=1;
				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();
						
			}
					
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
				b-=1;

				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();
			}
		////////////////////////
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
				b+=1;
				g+=1;

				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();

			}
			Delay100ms();
			Delay100ms();
			Delay100ms();
			
			for(i=0;i<255;i++)
			{
				if (s3==0)
				{
					Delay100ms();
					y=1;
					goto a;
				}
				b-=1;
				g-=1;

				for (x=0;x<50;x++)
				{
					LedRgb(r,g,b);
				}
				Delay50ms();

			}
			Delay100ms();
			Delay100ms();
			Delay100ms();
		}
		a:_nop_();

/////////////////////////////////////////////////////////////////////////


		///////////////////////////////
	}
}
///////////////////////
void ysxz (void) //颜色选择 r g b 预设 关 常量
{
	if (s4==0)
	{
		Delay100ms();
		while(s4==0){}
		ys+=1;
	}
	if (ys>11)
	{
		ys=0;
	}
////////////////////
		if (s2==0)
	{
		Delay100ms();
		while(s2==0){}
		ys-=1;
	}
	if (ys<0)
	{
		ys=11;
	}
}
/////////////////
void msxz (void) //模式选择 r g b 预设 关 常量
{
	if (s3==0)
	{
		Delay100ms();
		while(s3==0){}
		ms+=1;
	}
	if (ms>4)
	{
		ms=0;
	}
}

void Delay()		//@35MHz长延时
{
	unsigned char i, j;

	i = 11;
	j = 60;
	do
	{
		while (--j);
	} while (--i);
}

void Delay100ms()		//@35MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 14;
	j = 77;
	k = 153;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay50ms()		//@35MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 4;
	j = 50;
	k = 50;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void LedRgb(unsigned char a,unsigned char b, unsigned char c)
{
	send_sda(c); //绿
	send_sda(a); //红
	send_sda(b); //蓝
}


void offRGB()//关灯
{
	y=0;
	for (i=0;i<50;i++)
	{
		LedRgb(0,0,0);
	}
	Delay100ms();
}

void onRGB()
{
		
}
