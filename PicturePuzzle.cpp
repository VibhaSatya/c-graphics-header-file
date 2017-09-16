//PICTURE PUZZLE
#include "C:\Program Files (x86)\CodeBlocks\MinGW\include\graphics.h"
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

void *image[9];
char id[9]={'a','b','c','d','e','f','g','h','z'};
int x=1360;
int y=700;
int diffLevel=0;

struct node
{

    int old;
    int cur;
    struct node *next;
};
typedef struct node N;
N* top=NULL;
/*--------------------------------------------------------------------------------------------------------------------------*/
//function prototypes

//stack functions
N* push(int,int);
N* pop();
int stackEmpty();

//to generate random puzzle pattern
int patternGenerate(int,int);

//to solve the final puzzle
void solveIt();

//user interface functions
void imgFunc();
void homePage();
void drawBoxes();
void select();
void redraw();
void endButtons();

//to start the game
void start();

//to finish
void submit();



/*--------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------*/
//stack to keep track of exchanges
N* push(int old, int cur)
 {
	N* add;
	add=(struct node*)malloc(sizeof(N));
	add->old=old;
	add->cur=cur;
	add->next=NULL;
	if(top==NULL){

		top=add;
	}
	else
	{

		add->next=top;
		top=add;
	}

}

N* pop()
{
	N* temp;
	if(top==NULL)
	{
		return NULL;
	}
	else
	{
		temp=top;
		top=top->next;
	}
	return temp;
}

int stackEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
/*--------------------------------------------------------------------------------------------------------------------------*/

int patternGenerate(int prev,int ch)
{
	int temp,rindex;
	time_t t;
	srand((unsigned) time(&t));
		switch(ch)
			{
			case 0:
			{
			int choice[]={1,3};
			rindex=choice[rand()%2];
			break;
			}
			case 1:
			{
			int choice[]={0,4,2};
			rindex=choice[rand()%3];
			break;
			}
			case 2:
			{
			int choice[]={1,5};
			rindex=choice[rand()%2];
			break;
			}
			case 3:
			{
			int choice[]={0,4,6};
			rindex=choice[rand()%3];
			break;
			}
			case 4:
			{
			int choice[]={1,3,5,7};
			rindex=choice[rand()%4];
			break;
			}
			case 5:
			{
			int choice[]={2,4,8};
			rindex=choice[rand()%3];
			break;
			}
			case 6:
			{
			int choice[]={3,7};
			rindex=choice[rand()%2];
			break;
			}
			case 7:
			{
			int choice[]={4,6,8};
			rindex=choice[rand()%3];
			break;
			}
			case 8:
			{
			int choice[]={5,7};
			rindex=choice[rand()%2];
			break;
			}

			}

    if(rindex==prev)
			return -1;
    else
    {
        push(ch,rindex);

        temp=id[ch];
        id[ch]=id[rindex];
        id[rindex]=temp;

        void* temp2=image[ch];
        image[ch]=image[rindex];
        image[rindex]=temp2;


        //cout<<rindex;
        diffLevel++;
        return rindex;
    }
 }

void imgFunc()
{
    int color;
    int i, midx, midy, radius = 200;
    unsigned long size;

    initwindow(x,y);
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    //concentric rings
       for (i = 1; i <= 15; i++) {
                if (i % 2 == 0) {
                        color = 15;
                } else {
                        color = i;
                        if(i>15)
                          color=color-15;
                }

                setcolor(color);
                setfillstyle(SOLID_FILL, color);
                circle(midx, midy, radius);
                floodfill(midx, midy, color);
                radius = radius - 10;
        }
       radius+=10;
       for (i=1;radius!=0;i++)
       {
                if(i%2==0)
                color=i;
                else
                    color=15;
                setcolor(color);
                setfillstyle(SOLID_FILL, color);
                circle(midx, midy, radius);
                floodfill(midx, midy, color);
                radius = radius - 10;
       }


    int left = x/2-y/3;
	int top = y/2-y/3;
	int right = x/2+y/3;
	int bottom = y/2+y/3;
    int xdiff=(right-left)/3;
    int ydiff=(bottom-top)/3;


    //to capture 9 parts of the image
    size = imagesize(left, top, left+xdiff, top+ydiff );

    image[0] = malloc(size);
    image[1] = malloc(size);
    image[2] = malloc(size);
    image[3] = malloc(size);
    image[4] = malloc(size);
    image[5] = malloc(size);
    image[6] = malloc(size);
    image[7] = malloc(size);
    image[8] = malloc(size);
    image[9] = malloc(size);

    getimage(left, top, left+xdiff, top+ydiff, image[0]);
    getimage(left+xdiff, top, left+2*xdiff, top+ydiff, image[1]);
    getimage(left+2*xdiff, top, right, top+ydiff, image[2]);

    getimage(left, top+ydiff, left+xdiff, top+2*ydiff, image[3]);
    getimage(left+xdiff, top+ydiff, left+2*xdiff, top+2*ydiff, image[4]);
    getimage(left+2*xdiff, top+ydiff, right, top+2*ydiff, image[5]);

    getimage(left, top+2*ydiff, left+xdiff, bottom, image[6]);
    getimage(left+xdiff, top+2*ydiff, left+2*xdiff, bottom, image[7]);
    getimage(0, 0, xdiff, ydiff, image[8]);


}

void homePage()
{
  imgFunc();
  setcolor(15);
  rectangle(x-340,y-170,x-190,y-100);
  settextstyle(3,0,5);
  outtextxy(x-330,y-160,"START");
  settextstyle(3,0,8);
  outtextxy(x/2-360,40,"PICTURE PUZZLE");
  int a=-1,b=-1;
  do
    {
    getmouseclick(WM_LBUTTONDOWN,a,b);
    delay(10);
    }while(a==-1||b==-1||((a<x-340||a>x-190)||(b<y-170||b>y-100)));
    //cout<<"out";
    closegraph();



}


void drawBoxes()
{

    int left = x/2-y/3;
	int top = y/2-y/3;
	int right = x/2+y/3;
	int bottom = y/2+y/3;

	//char picture[20]="pic.bmp";
	//readimagefile(picture,left,top,right,bottom);

   //main rectangle
    int xdiff=(right-left)/3;
    int ydiff=(bottom-top)/3;


    putimage(left,top,image[0],0);
    putimage(left+xdiff,top,image[1],0);
    putimage(left+2*xdiff,top,image[2],0);
    putimage(left,top+ydiff,image[3],0);
    putimage(left+xdiff,top+ydiff,image[4],0);
    putimage(left+2*xdiff,top+ydiff,image[5],0);
    putimage(left,top+2*xdiff,image[6],0);
    putimage(left+xdiff,top+2*ydiff,image[7],0);
    putimage(left+2*xdiff,top+2*ydiff,image[8],0);


    setcolor(1);
    //first row
    rectangle(left,top,left+xdiff,top+ydiff);


    rectangle(left+xdiff,top,left+2*xdiff,top+ydiff);


    rectangle(left+2*xdiff,top,right,top+ydiff);


    //second row

    rectangle(left,top+ydiff,left+xdiff,top+2*ydiff);


    rectangle(left+xdiff,top+ydiff,left+2*xdiff,top+2*ydiff);


    rectangle(left+2*xdiff,top+ydiff,right,top+2*ydiff);


    //third row

    rectangle(left,top+2*ydiff,left+xdiff,bottom);


    rectangle(left+xdiff,top+2*ydiff,left+2*xdiff,bottom);


    rectangle(left+2*xdiff,top+2*ydiff,right,bottom);

}

void select()
{
    int left = x/2-y/3;
	int top = y/2-y/3;
	int right = x/2+y/3;
	int bottom = y/2+y/3;
    int xdiff=(right-left)/3;
    int ydiff=(bottom-top)/3;
    int templ,tempr,tempt,tempb,prev;
    int a=-1,b=-1;
    void *current;
    char curid;


    do
    {
    getmouseclick(WM_LBUTTONDOWN,a,b);
    if(a>x-340&&a<x-170&&b>y-170&&b<y-100)
        submit();
    else if(a>x-340&&a<x-140&&b>y-270&&b<y-200)
        solveIt();
    delay(10);
    }while(a==-1||b==-1||((a<left||a>right)||(b<top||b>bottom)));
   // cout<<"out1";

    //row 1
    if(a>=left&&a<=left+xdiff&&b>=top&&b<=top+ydiff)
    {
        if(id[1]=='z'||id[3]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=0;
            current=image[0];
            curid=id[0];
            setcolor(15);
            rectangle(left,top,left+xdiff,top+ydiff);
            templ=left;
            tempt=top;
        }
        else
            {
                setcolor(15);
                settextstyle(3,0,4);
                outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
                return;
            }


    }
     else if(a>=left+xdiff&&a<=left+2*xdiff&&b>=top&&b<=top+ydiff)
    {

        if(id[0]=='z'||id[4]=='z'||id[2]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=1;
            current=image[1];
            curid=id[1];
            setcolor(15);
            rectangle(left+xdiff,top,left+2*xdiff,top+ydiff);
            templ=left+xdiff;
            tempt=top;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;
        }

    }

     else if(a>=left+2*xdiff&&a<=right&&b>=top&&b<=top+ydiff)
    {
        if(id[1]=='z'||id[5]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=2;
            current=image[2];
            curid=id[2];
            setcolor(15);
            rectangle(left+2*xdiff,top,right,top+ydiff);
            templ=left+2*xdiff;
            tempt=top;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;

        }

    }

    //row 2
    else if(a>=left&&a<=left+xdiff&&b>=top+ydiff&&b<=top+2*ydiff)
    {
        if(id[0]=='z'||id[4]=='z'||id[6]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=3;
            current=image[3];
            curid=id[3];
            setcolor(15);
            rectangle(left,top+ydiff,left+xdiff,top+2*ydiff);
            templ=left;
            tempt=top+ydiff;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;
        }


    }
     else if(a>=left+xdiff&&a<=left+2*xdiff&&b>=top+ydiff&&b<=top+2*ydiff)
    {
        if(id[1]=='z'||id[3]=='z'||id[5]=='z'||id[7]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=4;
            current=image[4];
            curid=id[4];
            setcolor(15);
            rectangle(left+xdiff,top+ydiff,left+2*xdiff,top+2*ydiff);
            templ=left+xdiff;
            tempt=top+ydiff;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;

        }
    }
     else if(a>=left+2*xdiff&&a<=right&&b>=top+ydiff&&b<=top+2*ydiff)
    {
        if(id[2]=='z'||id[4]=='z'||id[8]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=5;
            current=image[5];
            curid=id[5];
            setcolor(15);
            rectangle(left+2*xdiff,top+ydiff,right,top+2*ydiff);
            templ=left+2*xdiff;
            tempt=top+ydiff;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;
        }
    }

    //row 3
      else if(a>=left&&a<=left+xdiff&&b>=top+2*ydiff&&b<=bottom)
    {
        if(id[3]=='z'||id[7]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=6;
            current=image[6];
            curid=id[6];
            setcolor(15);
            rectangle(left,top+2*ydiff,left+xdiff,bottom);
            templ=left;
            tempt=top+2*ydiff;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;
        }
    }
     else if(a>=left+xdiff&&a<=left+2*xdiff&&b>=top+2*ydiff&&b<=bottom)
    {
        if(id[6]=='z'||id[4]=='z'||id[8]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=7;
            current=image[7];
            curid=id[7];
            setcolor(15);
            rectangle(left+xdiff,top+2*ydiff,left+2*xdiff,bottom);
            templ=left+xdiff;
            tempt=top+2*ydiff;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;
        }
    }
     else if(a>=left+2*xdiff&&a<=right&&b>=top+2*ydiff&&b<=bottom)
    {
        if(id[5]=='z'||id[7]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            prev=8;
            current=image[8];
            curid=id[8];
            setcolor(15);
            rectangle(left+2*xdiff,top+2*ydiff,right,bottom);
            templ=left+2*xdiff;
            tempt=top+2*ydiff;
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
            return;
        }
    }

   //picture exchange

   do
    {
    getmouseclick(WM_LBUTTONDOWN,a,b);
    delay(10);
    }while(a==-1&&b==-1||((a<left||a>right)||(b<top||b>bottom)));
    //cout<<"out2";


    //row 1
    if(a>=left&&a<=left+xdiff&&b>=top&&b<=top+ydiff)
    {
        if(id[0]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left,top,current,0);
            void *temp;
            temp=image[0];
            image[0]=current;
            current=temp;

            char t;
            t=id[0];
            id[0]=curid;
            curid=t;

            push(prev,0);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }
     else if(a>=left+xdiff&&a<=left+2*xdiff&&b>=top&&b<=top+ydiff)
    {
        if(id[1]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left+xdiff,top,current,0);
            void *temp;
            temp=image[1];
            image[1]=current;
            current=temp;

            char t;
            t=id[1];
            id[1]=curid;
            curid=t;

            push(prev,1);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }


    }

     else if(a>=left+2*xdiff&&a<=right&&b>=top&&b<=top+ydiff)
    {
        if(id[2]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left+2*xdiff,top,current,0);
            void *temp;
            temp=image[2];
            image[2]=current;
            current=temp;


            char t;
            t=id[2];
            id[2]=curid;
            curid=t;

            push(prev,2);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }

    //row 2
    else if(a>=left&&a<=left+xdiff&&b>=top+ydiff&&b<=top+2*ydiff)
    {
        if(id[3]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left,top+ydiff,current,0);
            void *temp;
            temp=image[3];
            image[3]=current;
            current=temp;


            char t;
            t=id[3];
            id[3]=curid;
            curid=t;

            push(prev,3);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }
     else if(a>=left+xdiff&&a<=left+2*xdiff&&b>=top+ydiff&&b<=top+2*ydiff)
    {
        if(id[4]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left+xdiff,top+ydiff,current,0);
            void *temp;
            temp=image[4];
            image[4]=current;
            current=temp;

            char t;
            t=id[4];
            id[4]=curid;
            curid=t;

            push(prev,4);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }
     else if(a>=left+2*xdiff&&a<=right&&b>=top+ydiff&&b<=top+2*ydiff)
    {
        if(id[5]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left+2*xdiff,top+ydiff,current,0);
            void *temp;
            temp=image[5];
            image[5]=current;
            current=temp;

            char t;
            t=id[5];
            id[5]=curid;
            curid=t;

            push(prev,5);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }

    //row 3

    else if(a>=left&&a<=left+xdiff&&b>=top+2*ydiff&&b<=bottom)
    {
        if(id[6]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left,top+2*ydiff,current,0);
            void *temp;
            temp=image[6];
            image[6]=current;
            current=temp;

            char t;
            t=id[6];
            id[6]=curid;
            curid=t;

            push(prev,6);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }
     else if(a>=left+xdiff&&a<=left+2*xdiff&&b>=top+2*ydiff&&b<=bottom)
    {
        if(id[7]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left+xdiff,top+2*ydiff,current,0);
            void *temp;
            temp=image[7];
            image[7]=current;
            current=temp;

            char t;
            t=id[7];
            id[7]=curid;
            curid=t;

            push(prev,7);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }
     else if(a>=left+2*xdiff&&a<=right&&b>=top+2*ydiff&&b<=bottom)
    {
        if(id[8]=='z')
        {
            setcolor(0);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            putimage(left+2*xdiff,top+2*ydiff,current,0);
            void *temp;
            temp=image[8];
            image[8]=current;
            current=temp;

            char t;
            t=id[8];
            id[8]=curid;
            curid=t;

            push(prev,8);
        }
        else
        {
            setcolor(15);
            settextstyle(3,0,4);
            outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
            return;
        }
    }

    putimage(templ,tempt,current,0);
    image[prev]=current;
    id[prev]=curid;

}
void redraw()
{
    int left = x/2-y/3;
	int top = y/2-y/3;
	int right = x/2+y/3;
	int bottom = y/2+y/3;
    int xdiff=(right-left)/3;
    int ydiff=(bottom-top)/3;
    //redraw grid
    setcolor(1);
    //first row
    rectangle(left,top,left+xdiff,top+ydiff);
    rectangle(left+xdiff,top,left+2*xdiff,top+ydiff);
    rectangle(left+2*xdiff,top,right,top+ydiff);
    //second row
    rectangle(left,top+ydiff,left+xdiff,top+2*ydiff);
    rectangle(left+xdiff,top+ydiff,left+2*xdiff,top+2*ydiff);
    rectangle(left+2*xdiff,top+ydiff,right,top+2*ydiff);
    //third row
    rectangle(left,top+2*ydiff,left+xdiff,bottom);
    rectangle(left+xdiff,top+2*ydiff,left+2*xdiff,bottom);
    rectangle(left+2*xdiff,top+2*ydiff,right,bottom);
}

void solveIt()
{
    setcolor(0);
    settextstyle(3,0,4);
    outtextxy(x/2,y/2+300,"You can only move to the adjacent blank cell");
    setcolor(0);
    settextstyle(3,0,4);
    outtextxy(x/2,y/2+300,"Selected block is not blank. Select again");
    setcolor(0);
    rectangle(x-340,y-170,x-170,y-100);
    rectangle(x-340,y-270,x-140,y-200);

    settextstyle(3,0,5);
    outtextxy(x-330,y-160,"SUBMIT");
    setcolor(0);
    settextstyle(3,0,5);
    outtextxy(x-330,y-260,"SOLVE IT");
    int left = x/2-y/3;
	int top = y/2-y/3;
	int right = x/2+y/3;
	int bottom = y/2+y/3;
    int xdiff=(right-left)/3;
    int ydiff=(bottom-top)/3;
    int templ,tempt;
    void* current;
    //if user gives up
    while(!stackEmpty())
    {
       N* popped= pop();
       switch(popped->cur)
        {
        case 0:
            setcolor(15);
            rectangle(left,top,left+xdiff,top+ydiff);
            current=image[0];
            templ=left;
            tempt=top;
            break;
         case 1:
            setcolor(15);
            rectangle(left+xdiff,top,left+2*xdiff,top+ydiff);
            current=image[1];
            templ=left+xdiff;
            tempt=top;
            break;
         case 2:
            setcolor(15);
            rectangle(left+2*xdiff,top,right,top+ydiff);
            current=image[2];
            templ=left+2*xdiff;
            tempt=top;
            break;
         case 3:
            setcolor(15);
            rectangle(left,top+ydiff,left+xdiff,top+2*ydiff);
            current=image[3];
            templ=left;
            tempt=top+ydiff;
            break;
         case 4:
            setcolor(15);
            rectangle(left+xdiff,top+ydiff,left+2*xdiff,top+2*ydiff);
            current=image[4];
            templ=left+xdiff;
            tempt=top+ydiff;
            break;
         case 5:
            setcolor(15);
            rectangle(left+2*xdiff,top+ydiff,right,top+2*ydiff);
            current=image[5];
            templ=left+2*xdiff;
            tempt=top+ydiff;
            break;
         case 6:
            setcolor(15);
            rectangle(left,top+2*ydiff,left+xdiff,bottom);
            current=image[6];
            templ=left;
            tempt=top+2*ydiff;
            break;
         case 7:
            setcolor(15);
            rectangle(left+xdiff,top+2*ydiff,left+2*xdiff,bottom);
            current=image[7];
            templ=left+xdiff;
            tempt=top+2*ydiff;
            break;
         case 8:
            setcolor(15);
            rectangle(left+2*xdiff,top+2*ydiff,right,bottom);
            current=image[8];
            templ=left+2*xdiff;
            tempt=top+2*ydiff;
            break;

        }
    delay(1000);
    //exchange
    switch(popped->old)
      {
         case 0:
            putimage(left,top,current,0);
            break;
         case 1:
            putimage(left+xdiff,top,current,0);
            break;
         case 2:
            putimage(left+2*xdiff,top,current,0);
            break;
         case 3:
            putimage(left,top+ydiff,current,0);
            break;
         case 4:
            putimage(left+xdiff,top+ydiff,current,0);
            break;
         case 5:
            putimage(left+2*xdiff,top+ydiff,current,0);
            break;
         case 6:
            putimage(left,top+2*ydiff,current,0);
            break;
         case 7:
            putimage(left+xdiff,top+2*ydiff,current,0);
            break;
         case 8:
            putimage(left+2*xdiff,top+2*ydiff,current,0);
            break;

      }
    putimage(templ,tempt,image[popped->old],0);
    void *temp2=image[popped->old];
    image[popped->old]=image[popped->cur];
    image[popped->cur]=temp2;
    redraw();
    }
delay(2000);
system("cls");
closegraph();
cout<<"\n\n\n";
cout<<"*****************************************************************************";
    cout<<"\n\n\n                    GAME OVER\n\n\n";
cout<<"*****************************************************************************";
cout<<"\n\n\n";

}
void submit()
{
int answer=strcmp(id,"abcdefghz");
closegraph();
system("cls");
cout<<"\n\n\n";
cout<<"*****************************************************************************";
if(answer==0)
    cout<<"\n\n\n                    CONGRATULATIONS!!!!! YOU WON!!!!!\n\n\n";
else
    cout<<"\n\n\n                    SORRY. YOU LOST\n\n\n";
cout<<"*****************************************************************************";
cout<<"\n\n\n";
exit(0);

}

void start()
{

    //to generate the puzzle
    int prev=8,rno=8;

    while(diffLevel<10)
    {
        int temp=rno;
        rno=patternGenerate(prev,rno);

        if(rno==-1)
        {
            rno=temp;
            continue;
        }
        else
            prev=temp;


    }
    //cout<<id;

	initwindow(x,y);
	drawBoxes();

	/*node* temp=top;
	cout<<"\n";
	while(temp!=NULL)
    {
       cout<<temp->old<<" -> "<<temp->cur<<"\n";
       temp=temp->next;

    }*/

    setcolor(15);
    rectangle(x-340,y-170,x-170,y-100);
    rectangle(x-340,y-270,x-140,y-200);

    settextstyle(3,0,5);
    outtextxy(x-330,y-160,"SUBMIT");
    setcolor(15);
    settextstyle(3,0,5);
    outtextxy(x-330,y-260,"SOLVE IT");
    while(1)
    {
    select();
    //cout<<top->old<<" -> "<<top->cur<<"\n";
    redraw();
    }
    setcolor(15);
    outtextxy(0,0,"Starting");
    solveIt();

}

int main( )
{

    homePage();
    cout<<"Loading...Please wait...";
    start();
    while(1);
    return 0;
}
