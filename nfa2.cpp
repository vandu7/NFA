#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
int main()
{
    char str[100];
    int gd = DETECT, gm,x1=100,y1=300,r=50,xc=1,xch=12,x2,y2,flag=0,count;
    int len,i=0,j=1;
    char *ch,*state;
    ch=(char*)calloc(10,sizeof(char));
    state=(char*)calloc(20,sizeof(char));
    *state='0';
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("enter\n");
    gets(str);
    len=strlen(str);
    settextstyle(0, HORIZ_DIR, 1);

    while(str[i]!='\0')
    {


        if(str[i]>='a' && str[i]<='z')
        {
            //*ch=str[i];
            line(x1,y1,x1+100,y1);
            x1=x1+100;
            circle(x1+50,y1,r);
            x1=x1+50;
            x2=x1;
            y2=y1+50;
            //line(x1+50,y1,x1+100,y1);
            //x1=x1+100;

            //outtextxy(x1-15,y1-30,ch);
            i++;
            //free(ch);
            //ch=(char*)calloc(10,sizeof(char));
        }
        else if(str[i]=='+')
        {
            if(flag==0)
            {
            if(str[i-1]>='a' && str[i-1]<='z')
            {
                *ch=str[i-1];
            line(x1+50,y1,x1+100,y1);
            x1=x1+100;
            outtextxy(x1-15,y1-30,ch);
            free(ch);
            ch=(char*)calloc(10,sizeof(char));
            flag++;
            }
            }

            i++;
            if(str[i]=='(')
            {
                i++;
                line(x1,y1,x1+50,y1);
                x1=x1+50;
                circle(x1+50,y1,r);
                circle(x1+50,y1,r-20);
                x1=x1-50;
                y1=y1+150;
                line(x2,y2,x1,y1);
                *ch=str[i];
                if(str[i+1]!='.' && str[i+1]!='+')
                {
                line(x1,y1,x1+50,y1);
                x1=x1+50;
                outtextxy(x1-15,y1-30,ch);
                circle(x1+50,y1,50);
                x1=x1+100;
                }
                //if(str[i+1]!='.')
                outtextxy(x1,y1-30,ch);

                if(str[i+1]!='.' && str[i+1]!='+')

                {
                    line(x1,y1,x1+50,y1);
                    x1=x1+50;
                }
                free(ch);
                ch=(char*)calloc(10,sizeof(char));
                //i--;
                //if(str[i+1]=='.')
                    i++;
                xc=1;xch=12;
            }
            if(str[i]>='a' && str[i]<='z')
            *ch=str[i];
            if(str[i-1]!='(' && str[i+1]!='*' && str[i]!='+' && str[i]!='.')
            outtextxy(x1+xc,y1-30,",");
            //if(str[i+1]!='*')
            if(str[i]!='+')
            outtextxy(x1+xch,y1-30,ch);
            xc=xc+20;
            xch=xch+20;
            if(str[i]!='*' && str[i]!='+' && str[i]!='.')
            i++;
            if(str[i]==')' && i==len-1)
            {
                line(x1,y1,x1+50,y1);
                x1=x1+50;
                circle(x1+50,y1,r);
                circle(x1+50,y1,r-20);
                i++;

            }
            if(str[i]==')' && str[i+1]=='*')
            {
                line(x1,y1,x1+50,y1);
                x1=x1+50;
                circle(x1+50,y1,r);
                x1=x1+50;
            }
            if(str[i]!='*' && str[i]!='+' && str[i]!='.')
            i++;

            //if(str[i+1]=='.')
                //i++;

            free(ch);
            ch=(char*)calloc(10,sizeof(char));
        }
        else if(str[i]=='.')
        {
            if(flag==0)
            {
            if(str[i-1]>='a' && str[i-1]<='z')
            {
                *ch=str[i-1];
            line(x1+50,y1,x1+100,y1);
            x1=x1+100;
            outtextxy(x1-15,y1-30,ch);
            free(ch);
            ch=(char*)calloc(10,sizeof(char));
            flag++;
            }
            }
            i++;
            if(str[i]=='(')
                i++;
            *ch=str[i];
            if(str[i-2]!='*')
            {
            line(x1,y1,x1+50,y1);
            x1=x1+50;
            circle(x1+50,y1,r);
            x1=x1+50;
            }
            line(x1+50,y1,x1+100,y1);
            x1=x1+100;
            //line(x1,y1,x1+50,y1);
            //x1=x1+50;

            outtextxy(x1-15,y1-30,ch);
            i++;
            if(str[i]==')' && i==len-1)
            {
                line(x1,y1,x1+50,y1);
                x1=x1+50;
                circle(x1+50,y1,r);
                circle(x1+50,y1,r-20);
                i++;

            }
             if(str[i]==')' && str[i+1]=='*')
            {
                line(x1,y1,x1+50,y1);
                x1=x1+50;
                circle(x1+50,y1,r);
                x1=x1+50;
            }
            if(str[i]!='*' && str[i]!='+' && str[i]!='.')
            i++;
            free(ch);
            ch=(char*)calloc(10,sizeof(char));
        }
        else if(str[i]=='*')
        {
            int xsl,ysl,j=0;
            xsl=x1;
            ysl=y1-50;
            if(str[i]=='*' && (str[i-1]>='a' && str[i-1]<='z') && i+1==len-1 && len!=4)
            {
                line(x1,y1,x1+50,y1);
                x1=x1+50;
                circle(x1+50,y1,r);
                x1=x1+100;
                xsl=x1-50;
                x1=x1-50;

            }
            if(str[i-1]>='a' && str[i-1]<='z')
            {
                *ch=str[i-1];

            }
            if(str[i-1]!=')')
                arc(xsl,ysl,0,180,25);

             if(str[i-1]==')' && str[i-3]=='.' && str[i-5]=='.')
            {
                printf("here loop");
                xsl=x1-100;
                arc(x1-200,y1-50,0,180,200);
                i++;

            }
            if(str[i-1]==')' && str[i-3]=='.')
            {
                printf("here loop");
                xsl=x1-100;
                arc(x1-100,y1-50,0,180,100);
                //arc(xsl,ysl,0,180,100);

                //line(x1,y1,x1+50,y1);
                //x1=x1+50;
                //circle(x1+50,y1,r);
              /*  while(str[i]!='(')
                {
                    i--;
                }
                while(str[i]!=')')
                {
                    i++;
                    ch[j]=str[i];
                    j++;
                } */
                i++;

            }
            if(str[i-1]==')' && str[i-3]=='+')
            {
                printf("here loop");
                xsl=x1-100;
                arc(x1,y1-50,0,180,25);
                i++;

            }

            if(str[i]==')' && i==len-1 || str[i]=='*' && str[i+1]==')' && i+1==len-1)
            {
                circle(x1,y1,r-20);
                i++;
            }


            outtextxy(xsl,ysl-45,ch);

            //if(str[i]!='*' && str[i]!='+' && str[i]!='.')
            if(str[i-1]!='*' && str[i]=='.')
            i++;

            if(str[i]=='*' && str[i+1]=='.' && str[i-1]!=')' )
                i++;

            free(ch);
            ch=(char*)calloc(10,sizeof(char));
        }
        else if(str[i]==')' && i==len-1 && str[i-1]!='*')
        {

            if(str[i-1]>='a' && str[i-1]<='z')
            {
            line(x1+50,y1,x1+100,y1);
            x1=x1+100;
            *ch=str[i-1];
            outtextxy(x1-15,y1-30,ch);
            free(ch);
            ch=(char*)calloc(10,sizeof(char));
            }
            line(x1,y1,x1+50,y1);
            x1=x1+50;
            circle(x1+50,y1,r);
            circle(x1+50,y1,r-20);
            i++;

        }
        else
        {
            i++;

        }

    }
    getch();
    closegraph();
}
