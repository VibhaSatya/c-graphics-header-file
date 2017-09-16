#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;
char dnaArr[20]="";
char rnaArr[20]="pic.bmp";
int x,y;
void cover();
void menu();
void dna();
void transcriptionText();
void transcription();
void rna();
void translationText();
void translation();






void cover()
{
      
    float x1,x2;
    float j=0;
    int count=0;
     float i=0;

    while (i<1360)
    {
          //sin function
           setcolor(14); 
           x1=(100)*sin(j);        
          circle(i,275+x1, 2);
          delay(1);
          
          //cos function
         setcolor(14); 
           x2=(100)*cos(j);        
          circle(i-70,275+x2, 2);
          
          //lines
           if(count%10==0)
           {setcolor(10); 
           line(i,275+x1,i-70,275+x2);
           delay(1);}
          
         count++; 
         i+=0.7;
         j+=0.01;
        
       }
       
       
    
setcolor(15);
settextstyle(10, 0, 6);
outtextxy(200,50,"TRANSCRIPTION AND TRANSLATION");
rectangle(500,500,650,570);
settextstyle(9,100,4);
outtextxy(510,520,"MENU");


while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}



getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>500&&x<650)&&(y>500&&y<570))
{
cleardevice();

}


}//end of cover




void dna()
{
readimagefile(dnaArr,-50,100,900,700);//dna structure
settextstyle(10,0,6);
outtextxy(450,30,"DNA STRUCTURE");
delay(1500);
settextstyle(10,0,3);
outtextxy(850,100,"* DNA is made up of nucleotides.");
delay(1500);
outtextxy(850,200,"*A nucleotide is made up of ");
outtextxy(850,230,"a sugar, a phosphate and a base.");
delay(1500);
outtextxy(850,300,"* There are four kinds of ");
outtextxy(850,330,"nucleotides or base pairs:");
delay(1500);
outtextxy(850,370,"1) ADENINE(A) -pairs with T");
delay(1500);
outtextxy(850,420,"2) THYAMINE(T) -pairs with A");
delay(1500);
outtextxy(850,470,"3) GUANINE(G) -pairs with C");
delay(1500);
outtextxy(850,520,"4) CYTOSINE(C) -pairs with G");
delay(1500);
outtextxy(100,575,"* The pairs are linked by weak hydrogen bonds.");   
rectangle(850,600,950,650);
outtextxy(870,610,"MENU");
rectangle(970,600,1070,650);
outtextxy(990,610,"NEXT");
while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}

getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>850&&x<950)&&(y>600&&y<650))
{
cleardevice();
menu();
}
if((x>970&&x<1070)&&(y>600&&y<650))
{
cleardevice();
transcriptionText();
}
   
}//end of dna













void transcriptionText()
{
  setcolor(15);  
settextstyle(10,0,6);
outtextxy(450,50,"TRANSCRPTION");
settextstyle(10,0,3);
outtextxy(10,150," * Transcription is the first step of gene expression.");
delay(1000);

outtextxy(10,225," * Here,a particular segment of DNA is copied into RNA by the enzyme polymerase.");
delay(1000);

outtextxy(10,300," * DNA segment is read by RNA polymerase which produces complementary anti parallel RNA strand.");
delay(1000);

outtextxy(10,375," * RNA complement includes nucleotide uracil(U) instead of thymine(T).");
rectangle(850,600,950,650);
outtextxy(870,610,"MENU");
rectangle(970,600,1070,650);
outtextxy(990,610,"NEXT");
while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}

getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>850&&x<950)&&(y>600&&y<650))
{
cleardevice();
menu();
}
if((x>970&&x<1070)&&(y>600&&y<650))
{
cleardevice();
transcription();
}
}












void transcription()
{
setcolor(15);
settextstyle(10,0,6);
outtextxy(450,50,"TRANSCRPTION");
//random function
int nucNum[40];
int n=1;

int randnum;
unsigned int seedval;
time_t t;
seedval=(unsigned)time(&t);
srand(seedval);

setcolor(YELLOW);                           //DNA unwound lines
line(0,200,1360,200);
line(0,300,1360,300);

setcolor(15);
line(100,190,70,130);
settextstyle(10,0,2);
outtextxy(50,120,"Unwound DNA");

line(1300,250,1250,170);
settextstyle(10,0,2);
outtextxy(1200,150,"Hydrogen bond");


for(int i=0;i<1360;i+=30)             
{
 
 setcolor(GREEN); 
 if(i%20==0)
continue;
                                          // green bases
rectangle(i,201,i+20,250);
rectangle(i,250,i+20,299);
settextstyle(10, 0, 2);

//to generate random nucleotides

nucNum[n]=(rand()%4)+1;
switch(nucNum[n])
{
 case 1:                   
outtextxy(i+5,270,"A");
outtextxy(i+5,211,"T");
break;

case 2:                   
outtextxy(i+5,270,"T");
outtextxy(i+5,211,"A");
break;

case 3:                   
outtextxy(i+5,270,"G");
outtextxy(i+5,211,"C");
break;

case 4:
outtextxy(i+5,270,"C");
outtextxy(i+5,211,"G");
break;

}//end of switch
n++;
if(i==330)
{
setcolor(15);
line(i+10,300,i+20,370);
line(i+130,300,i+70,370);
settextstyle(10,0,2);
outtextxy(i-20,370,"Nucleotides");
}
}//end of loop2



//for(int b=0;b<20;b++)
//cout<<nucNum[b];


//polymerase
int circ=0;
n=0;
for(int k=20;k<1300;k++)
{
 setcolor(RED);       
ellipse(k,250,0,360,60,20);
setfillstyle(1,BLUE);
fillellipse(k,250,60,20);
outtextxy(k-35,240,"enzyme");

delay(10);
setcolor(BLACK);
ellipse(k,250,0,360,60,20);
fillellipse(k,250,60,20);
outtextxy(k-35,240,"enzyme");

//RNA (red line)
if(k>35)
{
setcolor(RED);
circle(circ,235,2);
circ++;

}


//new bases


if (k%60==0)
{
rectangle(k-90,234,k-69,270);
switch(nucNum[n])
{
 case 1:                   
outtextxy(k-85,240,"T");
break;

case 2:                   
outtextxy(k-85,240,"A");
break;

case 3:                   
outtextxy(k-85,240,"C");
break;

case 4:
outtextxy(k-85,240,"G");
break;

}//end of switch
n++;


}//end of if
if(k==400)
{
setcolor(15);
line(350,170,400,250);
settextstyle(10,0,2);
outtextxy(250,150,"Copy of genetic information");
}





}//end of loop3


setfillstyle(1,RED);
bar(0,230,1360,270);
delay(50);
setcolor(0);

{
//RNA seperates
float x;
    float j=0;
    int count=0;
     float i=1360,m;
     int k=0;
    while (!kbhit( ))
    {
          setcolor(0);
          rectangle(k,230,k+20,270);
                 
           setcolor(RED); 
           x=20*sin(j); 
           m=0.35*i;
          for(int l=250;l<290;l+=4)       
          circle(i,l+(1360*0.35-m)+x,2);      //1360*0.35
         
          delay(10);
         
         i-=0.7;
         j+=0.01;
         k++;
             
     if(k==1000)    
    {setcolor(15);
    line(i+50,400,i+20,500);
    settextstyle(10,0,2);
    outtextxy(i+50,400,"M-RNA");} 
         
         
    }
    }//sine function block

//DNA join

setfillstyle(1,0);
bar(0,200,1360,250);
n=1;


//re-draw top half
setcolor(YELLOW);                           //DNA unwound lines
line(0,230,1360,230);


for(int i=0;i<1360;i+=30)             
{
 setcolor(GREEN);      
if(i%20==0)

continue;
                                           //green bases
rectangle(i,231,i+20,270);
settextstyle(10, 0, 2);
switch(nucNum[n])
{
 case 1:                   
outtextxy(i+5,240,"T");
break;

case 2:                   
outtextxy(i+5,240,"A");
break;

case 3:                   
outtextxy(i+5,240,"C");
break;

case 4:
outtextxy(i+5,240,"G");
break;

}//end of switch
n++;

}//end of loop4

rectangle(850,600,950,650);
outtextxy(870,610,"MENU");
rectangle(970,600,1070,650);
outtextxy(990,610,"NEXT");
while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}

getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>850&&x<950)&&(y>600&&y<650))
{
cleardevice();
menu();
}
if((x>970&&x<1070)&&(y>600&&y<650))
{
cleardevice();
rna();
}

     
 }//end of transcription












//protein data base
char* protein[]={"Serine","Serine","Serine","Serine","Phenylalanine","Phenylalanine","Leucine","Leucine","Tyrosine","Tyrosine","Stop","Stop","Cysteine","Cysteine","Stop","Tryptophan","Leucine","Leucine","Leucine","Leucine","Proline","Histidine","Glutamine","Glutamine","Arginine","Arginine","Arginine","Arginine","Isoleucine","Isoleucine","Isoleucine","Methionine","Threonine","Threonine","Threonine","Threonine","Asparagine","Asparagine","Lysine","Lysine","Serine","Serine","Arginine","Arginine","Proline","Proline","Proline","Histidine","Valine","Valine","Valine","Valine","Alanine","Alanine","Alanine","Alanine","Aspartic Acid","Aspartic Acid","Glutamic Acid","Glutamic Acid","Glycine","Glycine","Glycine","Glycine"};
char seq[][4]= {"UCA","UCC","UCG","UCU","UUC","UUU","UUA","UUG","UAC","UAU","UAA","UAG","UGC","UGU","UGA","UGG","CUA","CUC","CUG","CUU","CCA","CAU","CAA","CAG","CGA","CGC","CGG","CGU","AUA","AUC","AUU","AUG","ACA","ACC","ACG","ACU","AAC","AAU","AAA","AAG","AGC","AGU","AGA","AGG","CCC","CCG","CCU","CAC","GUA","GUC","GUG","GUU","GCA","GCC","GCG","GCU","GAC","GAU","GAA","GAG","GGA","GGC","GGG","GGU" };
      
int nucSeq(char a,char b,char c)
{
  
  for(int i=0;i<64;i++)
  {
  
     if(seq[i][0]==a)
      if(seq[i][1]==b)
       if(seq[i][2]==c)
       {//cout<<i<<endl;
       return(i);}
       }
     }
     
  void rna()
  {
  //readimagefile(rnaArr,-100,100,1000,900);//rna structure
settextstyle(10,0,6);
outtextxy(350,50,"RNA STRUCTURE");

delay(1500);
settextstyle(10,0,3);
outtextxy(700,150,"* RNA is a polymer of ribonucleotides.");
delay(1500);
outtextxy(700,200,"* It is mainly synthesized from DNA.");
delay(1500);
outtextxy(700,300,"* RNA has uracil present in it ");
outtextxy(700,325,"instead of Thymine.");
delay(1500);
outtextxy(700,400,"* There are 3 types of RNA:");
delay(1500);
outtextxy(700,450," 1) Messenger RNA M-RNA");
delay(1500);
outtextxy(700,500," 2) Transfer RNA T-RNA");
delay(1500);
outtextxy(700,550," 3) Ribosomal RNA");  
  
  rectangle(850,600,950,650);
outtextxy(870,610,"MENU");
rectangle(970,600,1070,650);
outtextxy(990,610,"NEXT");
while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}

getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>850&&x<950)&&(y>600&&y<650))
{
cleardevice();
menu();
}
if((x>970&&x<1070)&&(y>600&&y<650))
{
cleardevice();
translationText();
}     
       
       
}   
     
     
     
     
     
     
     
     
     
void translationText()
{
settextstyle(10,0,6);
outtextxy(450,50,"TRANSLATION");

settextstyle(10,0,3);
outtextxy(200,200,"* Translation occurs in the cytoplasm. ");
delay(500);
//settextstyle(0,100,3);
outtextxy(200,250," * It is divided into four phases:");
delay(1500);
outtextxy(200,325,"1) ACTIVATION: The amino acid is bonded to tRNA.");
delay(1500);
outtextxy(200,400,"2) INITIATION: The subunit of ribosome binds to the end of mRNA.");
delay(1500);
outtextxy(200,475,"3) ELONGATION: The next aminoacyl tRNA binds to ribosome .");
delay(1500);
outtextxy(200,550,"4) TERMINATION: The A site of ribosome faces a stop codon(UAA or UAG).");
rectangle(850,600,950,650);
outtextxy(870,610,"MENU");
rectangle(970,600,1070,650);
outtextxy(990,610,"NEXT");
while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}

getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>850&&x<950)&&(y>600&&y<650))
{
cleardevice();
menu();
}
if((x>970&&x<1070)&&(y>600&&y<650))
{
cleardevice();
translation();
}

}

void translation()
{
int flag=0;
int count;
//nucleotide input
char nucArr[50][1];
char* tmp = new char[2];
settextstyle(10,0,6);
outtextxy(450,50,"TRANSLATION");

settextstyle(9,100,4);
outtextxy(170,150,"Enter nitogenous base sequence in the text box ");
outtextxy(200,200,"for translation to happen...");

cout<<"Enter base sequence (in multiples of three only)\n\n";


while(flag==0||flag==2)
{
    for(count=0;count<50;count++)
    {
        cin.get(nucArr[count][0]);
                                                                                                                                                                                                         
        if(nucArr[count][0]=='\n')
         {          
         flag=1;
         break; }
          }
        if((count)%3!=0)
        {
        cout<<"Number of bases entered MUST be in multiples of three\n(because 3 nitrogenous bases make one codon).\n\nEnter again."<<endl<<endl;
         flag=2;}
    
     //to check input
       for(int i=0;i<count;i++)
     {
       
        if(nucArr[i][0]!='A')
         if(nucArr[i][0]!='a')
           if(nucArr[i][0]!='U')
             if(nucArr[i][0]!='u')
                if(nucArr[i][0]!='G')
                   if(nucArr[i][0]!='g')
                      if(nucArr[i][0]!='C') 
                        if(nucArr[i][0]!='c')
         flag=0;
               
     } 
     
      if(flag==0)cout<<"Invalid base symbol. "<<endl<<"Enter once more. "<<endl<<endl; 
      
     
}//end of while
//
int proteinArr[50];
//
int proNo;

//to store corresponding protein
//cout<<count<<endl;
for(int j=0,i=0;j<count/3;j++,i+=3)
{
proteinArr[j]=(nucSeq(toupper(nucArr[i][0]),toupper(nucArr[i+1][0]),toupper(nucArr[i+2][0])));
//cout<<protein[proteinArr[j]]<<endl;
}





//compliment of nucArr
char comArr[50][1];
for(int i=0;i<count;i++)
{
  if((toupper(nucArr[i][0]))=='A')   
  comArr[i][0]='U';  
  if((toupper(nucArr[i][0]))=='G')   
  comArr[i][0]='C'; 
    
  if((toupper(nucArr[i][0]))=='U')   
  comArr[i][0]='A'; 
  if((toupper(nucArr[i][0]))=='C')   
  comArr[i][0]='G';  
 
} 
//for(int i=0;i<count;i++)
//cout<<comArr[i][0];

int co=1;
int count2=1;
int row=0;
int row2=0;
int c=0;
int control=1;
setcolor(0);
settextstyle(9,100,4);
outtextxy(170,150,"Enter nitogenous base sequence in the text box ");
outtextxy(200,200,"for translation to happen...");

//visual
setcolor(15);
settextstyle(10,0,1); 
outtextxy(1000,600,"*SUGAR AND T-RNA NOT DEPICTED");

for(int k=50;k<1500;k++)
{  
   settextstyle(10,0,1);                                          //top
setfillstyle(1, YELLOW);
setcolor(YELLOW);
ellipse(k,370,0, 360, 70,25);
fillellipse(k,370,70,25);
                                        //bottom
ellipse(k,420,0, 360, 50,25);
fillellipse(k,420, 50,25);
setcolor(RED);
 outtextxy(k-43,412,"Ribosome");
 row=0;
  
                                       //phosphate
for(int l=0;l<1360;l+=20)
{
setcolor(BLUE);                   
rectangle(l-7,370,l+7,400);
setcolor(YELLOW);

  if(row==count)
  row=0;
 
  

   tmp[0]=toupper(nucArr[row][0]);
   tmp[1]='\0';
   outtextxy(l-5,370,tmp);
  
   row++;
       
setcolor(RED); 
circle(l,400,10); 

for(int j=0;j<10;j++)                   //fill circle color
{
setcolor(RED);
circle(l,400,j);
}


}




delay(2);
setcolor(0);


                                       //black
ellipse(k,370,0, 360, 70,25);          //top
setfillstyle(1, BLACK);
fillellipse(k,370,70,25);

ellipse(k,420,0, 360, 50,25);       //bottom
setfillstyle(1, BLACK);
fillellipse(k,420, 50,25);


if(k%20==0)
{
if(count2%3==0)
{
 co++;              
setcolor(co);
circle(k-70,300,30);
settextstyle(10,0,2);
if(c==count/3)
c=0;
//cout<<endl<<c;
//cout<<endl<<endl<<proteinArr[c];
outtextxy(k-90,290,protein[(proteinArr[c])]);

c++;

}
if(co==15)
co=1;

setcolor(co);                   
rectangle(k-106,340,k-93,368);
if(row2==count)
  row2=0;
  if(control>2)
   {
   tmp[0]=toupper(comArr[row2][0]);
   tmp[1]='\0';
   outtextxy(k-104,340,tmp);
   row2++;}
   control++; 

   
   
}
count2++;
setcolor(15);
if(k==100)
{
line(50,300,100,150);
outtextxy(40,140,"Amino acid");
line(200,400,250,500); 
outtextxy(251,501,"Phosphate");
line(700,300,600,370);
outtextxy(701,290,"Nitrogenous base");

}
if(k==200)
{
settextstyle(10,0,4);
outtextxy(300,200,"PROTEIN FORMATION");

}

}//end of big loop
rectangle(850,600,950,650);
outtextxy(870,610,"MENU");
rectangle(970,600,1070,650);
outtextxy(990,610,"NEXT");
while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}

getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>850&&x<950)&&(y>600&&y<650))
{
cleardevice();
menu();
}
if((x>970&&x<1070)&&(y>600&&y<650))
{
cleardevice();
exit(0);
}
}  //end of transcription function





void menu()
{
settextstyle(9,100,5);
outtextxy(300,100,"1) DNA");
rectangle(900,100,940,140);
delay(1500);
outtextxy(300,200,"2) TRANSCRIPTION");
rectangle(900,200,940,240);
delay(1500);
outtextxy(300,300,"3) RNA");
rectangle(900,300,940,340);
delay(1500);
outtextxy(300,400,"4) TRANSLATION");
rectangle(900,400,940,440);
delay(1500);
outtextxy(300,500,"5) EXIT");
rectangle(900,500,940,540);



while(ismouseclick(WM_LBUTTONDBLCLK)==0)
{
}

getmouseclick(WM_LBUTTONDBLCLK,x,y);
if((x>=900&&x<=940)&&(y>=100&&y<=140))
{
cleardevice();
dna();
}
if((x>=900&&x<=940)&&(y>=200&&y<=240))
{
cleardevice();
transcriptionText();

}
if((x>=900&&x<=940)&&(y>=300&&y<=340))
{
cleardevice();
rna();
}
if((x>=900&&x<=940)&&(y>=400&&y<=440))
{
cleardevice();
translationText();

}
if((x>=900&&x<=940)&&(y>=500&&y<=540))
{
cleardevice();
exit(0);
}
     
  }//end of menu










int main( )
{
initwindow(1360, 700, "Comp project");

cover();
menu();






  

system("pause");
}
 

