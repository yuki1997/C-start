#include <stdio.h>    /* 标准输入输出库      */
#include <string.h>   /* 字符串操作函数库    */
#include <math.h>   /* 数学函数库          */
#include <stdlib.h>   /* 标准函数库          */
#include <graphics.h> /* 图形函数库          */
#include <bios.h>    /* 基本输入输出系统函数库*/
#include <dos.h>     /* dos函数库           */

#define NUM0       0x5230    /* 小键盘区上数字键0 */
#define NUM1       0x4f31    /* 小键盘区上数字键1 */
#define NUM2       0x5032    /* 小键盘区上数字键2 */
#define NUM3       0x5133    /* 小键盘区上数字键3 */
#define NUM4       0x4b34    /* 小键盘区上数字键4 */
#define NUM5       0x4c35    /* 小键盘区上数字键5 */
#define NUM6       0x4d36    /* 小键盘区上数字键6 */
#define NUM7       0x4737    /* 小键盘区上数字键7 */
#define NUM8       0x4838    /* 小键盘区上数字键8 */
#define NUM9       0x4939    /* 小键盘区上数字键9 */
#define NUMPNT     0x532e    /* 小键盘区上 . 键    */
#define NUMADD     0x4e2b    /* 小键盘区上 + 键    */
#define NUMSUB     0x4a2d    /* 小键盘区上 - 键    */
#define NUMMUL     0x372a    /* 小键盘区上 * 键    */
#define NUMDIV     0x352f    /* 小键盘区上 / 键    */
#define NUMEQU     0x1c0d    /* 小键盘区上 = 键    */

#define KEY0       0xb30     /* 主键盘区上数字键0 */
#define KEY1       0x231     /* 主键盘区上数字键1 */
#define KEY2       0x332     /* 主键盘区上数字键2 */
#define KEY3       0x433     /* 主键盘区上数字键3 */
#define KEY4       0x534     /* 主键盘区上数字键4 */
#define KEY5       0x635     /* 主键盘区上数字键5 */
#define KEY6       0x736     /* 主键盘区上数字键6 */
#define KEY7       0x837     /* 主键盘区上数字键7 */
#define KEY8       0x938     /* 主键盘区上数字键8 */
#define KEY9       0xa39     /* 主键盘区上数字键9 */
#define KEYPNT     0x342e    /* 主键盘区上 . 键    */
#define KEYSUB     0xc2d     /* 主键盘区上 - 键    */
#define KEYMUL     0x92a     /* 主键盘区上 * 键    */
#define KEYEQU     0xd3d     /* 主键盘区上 = 键    */

#define SQR        0x340     /* @ 键,求平方根 */
#define KEYR       0x1372    /* r 键,取倒数 */
#define PERCENT    0x625     /* % 键,求百分数 */
#define DEL        0x5300    /* DEL 键 */
#define ESC        0x11b     /* ESC 键 */
#define BACKSPACE 0xe08     /* 退格 键 */
#define F9         0x4300    /* F9 键，正负数变换 */
#define CTRL_L     0x260c    /* Ctrl 键+L键，清除记忆器中的数值 */
#define CTRL_R     0x1312    /* Ctrl 键+R键，读取记忆器中的数值 */
#define CTRL_M     0x320d    /* Ctrl 键+M键，将当前数值写入记忆器中*/
#define CTRL_P     0x1910    /* Ctrl 键+P键，将当前数值和记忆器中保存的数值相加*/
#define ALT_X      0x2d00    /* Alt 键+X键 */

#define TRUE 1     /* 为十进制1表示为真 true */
#define FALSE 0     /* 为十进制0表示为假 false */

/*计算器界面结构体*/
struct Block
    {    int left,top,width,height;        /* 左上坐标,宽,高          */
         char caption[50];                  /* 标题                    */
         int fontcolor,fontsize,status;    /* 字体颜色,字体大小,状态 */
    };

void Form(struct Block form);      /* 构造和显示主窗口*/
void TextBox(struct Block txtbox); /* 构造和显示文本输入框*/
void Label(struct Block label);    /* 构造和显示标签，若记忆功能开启，标签标记为：M*/

void CommandButton(struct Block cmdbutton); /*显示cmdbutton[i]命令按钮*/
void CommandButton_KeyboardDown(int i); /*定义按下编号为i的键所进行的操作，如按钮的状态的改变*/
void CommandButton_KeyboardUp(int i);   /*定义松开编号为i的按键所进行的操作，如按钮的状态*/


void InitApp(); /*初始化程序*/
void Showme(); /*显示计算器界面*/
void Load();    /*初始化默认值*/

void CommandButton_Click(int key); /*按键盘时所做的操作*/
void DoubleRun(); /*四则运算:加减乘除*/
void SingleRun(int operatoror); /*单运算*/
void Resetbuf(); /*重置缓冲区*/
void StoreSet(int key); /*定义记忆存储操作*/
void Unload(); /*退出系统时的一些恢复操作*/


struct Block frmmain,txtscreen,lblstore,cmdbutton[28]; /*定义主窗口,文本输入框,记忆标签,28[0-27]个按钮*/
int clickflag; /*clickflag:按键标志，*/
int top,pointflag,digitkeyhit; /*top:保存缓冲区中的当前位数，pointflag:小数点标记，digitkeyhit:数字键按键标记*/
int operatoror,runflag,ctnflag; /*operatoror:操作符，runflag:运算标记，ctnflag:运算符标记*/
int errorflag; /*错误标记*/
double num1,num2,store; /*num1:操作数1,num2：操作数2,store：记忆变量*/
char strbuf[33]; /*字符缓冲区,用于保存一个操作数*/


void main()
    {

         int key; /*保存此计算器上定义的按键编号*/
         InitApp();/*初始化程序，进入图形模式*/
         Showme(); /*显示计算器窗口*/
         Load();   /*初始化默认值*/
         while(1)
             {
                    if(bioskey(1)==0) continue; /*直到有键按下时，才返回非0值，否则返回0值*/
                    key=bioskey(0); /*返回上条语句的按键值*/
                    switch(key)    /*捕获相应的键盘按键并匹配到计算器按键上*/
                        {    case NUM0:case KEY0:          key=10;break;
                             case NUM1:case KEY1:          key=1;break;
                             case NUM2:case KEY2:          key=2;break;
                             case NUM3:case KEY3:          key=3;break;
                             case NUM4:case KEY4:          key=4;break;
                             case NUM5:case KEY5:          key=5;break;
                             case NUM6:case KEY6:          key=6;break;
                             case NUM7:case KEY7:          key=7;break;
                             case NUM8:case KEY8:          key=8;break;
                             case NUM9:case KEY9:          key=9;break;
                             case F9:                      key=11;break;
                             case NUMPNT:case KEYPNT:      key=12;break;
                             case NUMADD:                  key=13;break;
                             case NUMSUB:case KEYSUB:      key=14;break;
                             case NUMMUL:case KEYMUL:      key=15;break;
                             case NUMDIV:                  key=16;break;
                             case SQR:                     key=17;break;
                             case PERCENT:                 key=18;break;
                             case KEYR:                    key=19;break;
                             case NUMEQU:case KEYEQU:      key=20;break;
                             case CTRL_L:                  key=21;break;
                             case CTRL_R:                  key=22;break;
                             case CTRL_M:                  key=23;break;
                             case CTRL_P:                  key=24;break;
                             case BACKSPACE:               key=25;break;
                             case DEL:                     key=26;break;
                             case ESC:                     key=27;break;
                             case ALT_X:                   key=0; break;
                             default:                      key=-1;break;
                     }
             if(key<0) continue; /*若对应的按键返回负数，则返回到while(1)处执行*/
             CommandButton_KeyboardDown(key);/*为了在计算器上显示按键效果，在此函数中改变一些按钮的状态值*/
             CommandButton_Click(key); /*根据key的值，进行相关操作*/
             delay(300000);    /*为了突出按键效果，此处延时300000毫秒*/
             CommandButton_KeyboardUp(key); /*在处理完此按键后，要恢复按钮的状态值*/
        }
    }

void InitApp()   /*初始化程序*/
    {
         int driver=DETECT,mode; /* 显示设备驱动为自动检测显示器模式 */
         initgraph(&driver,&mode,"");   /* 初始化图形显示系统 */
         if(driver!=VGA&&driver!=EGA) /* 如果不能初始化 */
             { printf("/n/nERROR!Can't initialize the graphics system!"); /* 显示错误信息"不能初始化图形系统" */
                    closegraph();   /* 关闭图形接口*/
                    exit(0);       /* 直接退出系统 */
             }
         setbkcolor(9);     /* 设置背景颜色为青色 */


         /*主窗口的属性设置*/
         frmmain.left=200; frmmain.top=100; frmmain.width=230; frmmain.height=235; frmmain.fontcolor=BLACK; frmmain.fontsize=1;   strcpy(frmmain.caption,"   << Calculator >>");frmmain.status=1;
         /*文本框的属性设置*/
         txtscreen.left=10;txtscreen.top=25;txtscreen.width=210;txtscreen.height=30;txtscreen.fontcolor=BLACK;txtscreen.fontsize=1;strcpy(txtscreen.caption,"0.");           txtscreen.status=1;
         /*标签的属性设置*/
         lblstore.left=190; lblstore.top=62; lblstore.width=30; lblstore.height=25; lblstore.fontcolor=YELLOW; lblstore.fontsize=1;strcpy(lblstore.caption,"");              lblstore.status=1;
         /*命令按钮的属性设置*/
         cmdbutton[1].left=50-35;cmdbutton[1].top=165;cmdbutton[1].width=30;cmdbutton[1].height=25;cmdbutton[1].fontcolor=BLUE;cmdbutton[1].fontsize=1;strcpy(cmdbutton[1].caption,"1");cmdbutton[1].status=1;
         cmdbutton[2].left=85-35;cmdbutton[2].top=165;cmdbutton[2].width=30;cmdbutton[2].height=25;cmdbutton[2].fontcolor=BLUE;cmdbutton[2].fontsize=1;strcpy(cmdbutton[2].caption,"2");cmdbutton[2].status=1;
         cmdbutton[3].left=120-35;cmdbutton[3].top=165;cmdbutton[3].width=30;cmdbutton[3].height=25;cmdbutton[3].fontcolor=BLUE;cmdbutton[3].fontsize=1;strcpy(cmdbutton[3].caption,"3");cmdbutton[3].status=1;
         cmdbutton[4].left=50-35;cmdbutton[4].top=130;cmdbutton[4].width=30;cmdbutton[4].height=25;cmdbutton[4].fontcolor=BLUE;cmdbutton[4].fontsize=1;strcpy(cmdbutton[4].caption,"4");cmdbutton[4].status=1;
         cmdbutton[5].left=85-35;cmdbutton[5].top=130;cmdbutton[5].width=30;cmdbutton[5].height=25;cmdbutton[5].fontcolor=BLUE;cmdbutton[5].fontsize=1;strcpy(cmdbutton[5].caption,"5");cmdbutton[5].status=1;
         cmdbutton[6].left=120-35;cmdbutton[6].top=130;cmdbutton[6].width=30;cmdbutton[6].height=25;cmdbutton[6].fontcolor=BLUE;cmdbutton[6].fontsize=1;strcpy(cmdbutton[6].caption,"6");cmdbutton[6].status=1;
         cmdbutton[7].left=50-35;cmdbutton[7].top=95;cmdbutton[7].width=30;cmdbutton[7].height=25;cmdbutton[7].fontcolor=BLUE;cmdbutton[7].fontsize=1;strcpy(cmdbutton[7].caption,"7");cmdbutton[7].status=1;
         cmdbutton[8].left=85-35;cmdbutton[8].top=95;cmdbutton[8].width=30;cmdbutton[8].height=25;cmdbutton[8].fontcolor=BLUE;cmdbutton[8].fontsize=1;strcpy(cmdbutton[8].caption,"8");cmdbutton[8].status=1;
         cmdbutton[9].left=120-35;cmdbutton[9].top=95;cmdbutton[9].width=30;cmdbutton[9].height=25;cmdbutton[9].fontcolor=BLUE;cmdbutton[9].fontsize=1;strcpy(cmdbutton[9].caption,"9");cmdbutton[9].status=1;
         cmdbutton[10].left=50-35;cmdbutton[10].top=200;cmdbutton[10].width=30;cmdbutton[10].height=25;cmdbutton[10].fontcolor=BLUE;cmdbutton[10].fontsize=1;strcpy(cmdbutton[10].caption,"0");cmdbutton[10].status=1;
         cmdbutton[11].left=85-35;cmdbutton[11].top=200;cmdbutton[11].width=30;cmdbutton[11].height=25;cmdbutton[11].fontcolor=BLUE;cmdbutton[11].fontsize=1;strcpy(cmdbutton[11].caption,"+/-");cmdbutton[11].status=1;
         cmdbutton[12].left=120-35;cmdbutton[12].top=200;cmdbutton[12].width=30;cmdbutton[12].height=25;cmdbutton[12].fontcolor=BLUE;cmdbutton[12].fontsize=1;strcpy(cmdbutton[12].caption,".");cmdbutton[12].status=1;
         cmdbutton[13].left=155-35;cmdbutton[13].top=95;cmdbutton[13].width=30;cmdbutton[13].height=25;cmdbutton[13].fontcolor=RED;cmdbutton[13].fontsize=1;strcpy(cmdbutton[13].caption,"+");cmdbutton[13].status=1;
         cmdbutton[14].left=155-35;cmdbutton[14].top=130;cmdbutton[14].width=30;cmdbutton[14].height=25;cmdbutton[14].fontcolor=RED;cmdbutton[14].fontsize=1;strcpy(cmdbutton[14].caption,"-");cmdbutton[14].status=1;
         cmdbutton[15].left=155-35;cmdbutton[15].top=165;cmdbutton[15].width=30;cmdbutton[15].height=25;cmdbutton[15].fontcolor=RED;cmdbutton[15].fontsize=1;strcpy(cmdbutton[15].caption,"*");cmdbutton[15].status=1;
         cmdbutton[16].left=155-35;cmdbutton[16].top=200;cmdbutton[16].width=30;cmdbutton[16].height=25;cmdbutton[16].fontcolor=RED;cmdbutton[16].fontsize=1;strcpy(cmdbutton[16].caption,"/");cmdbutton[16].status=1;
         cmdbutton[17].left=190-35;cmdbutton[17].top=95;cmdbutton[17].width=30;cmdbutton[17].height=25;cmdbutton[17].fontcolor=BLUE;cmdbutton[17].fontsize=1;strcpy(cmdbutton[17].caption,"sqr");cmdbutton[17].status=1;
         cmdbutton[18].left=190-35;cmdbutton[18].top=130;cmdbutton[18].width=30;cmdbutton[18].height=25;cmdbutton[18].fontcolor=BLUE;cmdbutton[18].fontsize=1;strcpy(cmdbutton[18].caption,"%");cmdbutton[18].status=1;
         cmdbutton[19].left=190-35;cmdbutton[19].top=165;cmdbutton[19].width=30;cmdbutton[19].height=25;cmdbutton[19].fontcolor=BLUE;cmdbutton[19].fontsize=1;strcpy(cmdbutton[19].caption,"1/x");cmdbutton[19].status=1;
         cmdbutton[20].left=190-35;cmdbutton[20].top=200;cmdbutton[20].width=30;cmdbutton[20].height=25;cmdbutton[20].fontcolor=RED;cmdbutton[20].fontsize=1;strcpy(cmdbutton[20].caption,"=");cmdbutton[20].status=1;
         cmdbutton[21].left=190;cmdbutton[21].top=95;cmdbutton[21].width=30;cmdbutton[21].height=25;cmdbutton[21].fontcolor=RED;cmdbutton[21].fontsize=1;strcpy(cmdbutton[21].caption,"MC");cmdbutton[21].status=1;
         cmdbutton[22].left=190;cmdbutton[22].top=130;cmdbutton[22].width=30;cmdbutton[22].height=25;cmdbutton[22].fontcolor=RED;cmdbutton[22].fontsize=1;strcpy(cmdbutton[22].caption,"MR");cmdbutton[22].status=1;
         cmdbutton[23].left=190;cmdbutton[23].top=165;cmdbutton[23].width=30;cmdbutton[23].height=25;cmdbutton[23].fontcolor=RED;cmdbutton[23].fontsize=1;strcpy(cmdbutton[23].caption,"MS");cmdbutton[23].status=1;
         cmdbutton[24].left=190;cmdbutton[24].top=200;cmdbutton[24].width=30;cmdbutton[24].height=25;cmdbutton[24].fontcolor=RED;cmdbutton[24].fontsize=1;strcpy(cmdbutton[24].caption,"M+");cmdbutton[24].status=1;
         cmdbutton[25].left=50-35;cmdbutton[25].top=60;cmdbutton[25].width=53;cmdbutton[25].height=25;cmdbutton[25].fontcolor=RED;cmdbutton[25].fontsize=1;strcpy(cmdbutton[25].caption,"<-");cmdbutton[25].status=1;
         cmdbutton[26].left=108-35;cmdbutton[26].top=60;cmdbutton[26].width=53;cmdbutton[26].height=25;cmdbutton[26].fontcolor=RED;cmdbutton[26].fontsize=1;strcpy(cmdbutton[26].caption,"Del");cmdbutton[26].status=1;
         cmdbutton[27].left=166-35;cmdbutton[27].top=60;cmdbutton[27].width=53;cmdbutton[27].height=25;cmdbutton[27].fontcolor=RED;cmdbutton[27].fontsize=1;strcpy(cmdbutton[27].caption,"Esc");cmdbutton[27].status=1;
         /* 设置计算器界面 */
    }

void Showme()   /*显示计算器界面*/
    {    int i;
         Form(frmmain); /*显示主窗口，frmmain为主窗口的结构变量名*/
         TextBox(txtscreen); /*显示文本框*/
         Label(lblstore); /*显示记忆器的状态标签*/
         for(i=1;i<28;i++) /*显示27个按钮在计算器主窗口中*/
             CommandButton(cmdbutton[i]);
    }

void Load() /*初始化默认值*/
    {    num1=num2=0;
         Resetbuf();
         ctnflag=FALSE;
         operatoror=0;
         runflag=FALSE;
         errorflag=FALSE;
         store=0;
         clickflag=FALSE;

         strcpy(txtscreen.caption,"0.");
         TextBox(txtscreen);/*文本框中初始显示为0.的字符*/

         strcpy(lblstore.caption,"");
         Label(lblstore);
    }

void Unload() /*退出系统*/
    {
         cleardevice(); /*清除图形屏幕*/
         closegraph(); /*关闭图形系统*/
         exit(0);
    }
