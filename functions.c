
/*****************************************************************************
 * Copyright (C) Shrikrushna D. Kulkarni kulkarnisd13.it@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include <ncurses.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cal.h"
# define EXP 2.718
#define PI 3.142857
#define ERROR 1.0e-6
char ch;
float ans;
char data[40];
/*initialises curses mode*/
void initcurses() {
	initscr();	
	raw();				
	keypad(stdscr, TRUE);		
	noecho();	
}	
/*Draws calculator on screen*/
void drawcal() {
	mvprintw(10,0,"MY CALCULATOR\n");
	mvprintw(5,50,"------------------------------------------------------");
	mvprintw(20,50,"-----------------------------------------------------");
	mvprintw(9,50,"------------------------------------------------------");
	mvprintw(11,50,"7    8    9    /    log       ln        1/x       PI");
	mvprintw(14,50,"4    5    6    *    sin       cos       tan       exp");
	mvprintw(17,50,"1    2    3    -    sin-1    cos-1      tan-1     ^");
	mvprintw(20,50,"C    0    =    +    ans      fac        sqt       OFF");
	mvprintw(30,0,"Instructions:  For Numeric calculations press 'A'(capital) before and press = to get result");
	mvprintw(32,0,"               For other functions move cursor on that function name using arrow keys and press '='");
	mvprintw(34,0,"	      C clears the calculator screen ");
	mvprintw(36,0,"	      OFF to exit calculator ");
}
/*exit curses mode*/
void endcurses() {
	refresh();			
    	getch();			
	endwin();	
}

/*Moving cursor through keys
 To exit the calculator press q*/
void mvcurs() {
	
	int input;
	curs_set(2);
	int y=11,x=50;
	int b;
	float a,p,q,w;
	mvprintw(22,0,"Press 'q'to exit");
	move(11,50);
	while(input != 'q') {
	
		cbreak();
		input = getch();
		switch(input) {
			case KEY_UP :
				if(y >= 14)
				move(y=y-3,x);
				break;
			case KEY_DOWN :
				if(y <= 17)
				move(y=y+3,x);
				break;
			case KEY_LEFT :
				if(x <= 70 && x>50)
				move(y,x=x-5);
				else if(x>70)
				move(y,x=x-10);
				
				break;
			case KEY_RIGHT :
				if(x < 70)
				move(y,x=x+5);
			     if(x>=70 && x<100)
				move(y,x=x+10);
				break;
			case '=':
				getyx(stdscr,y,x);
				if(y==20 && x==90){
					clrscr();
					mvprintw(7,70,"sqrt");
					scanw("%d",&b);
					mvprintw(7,74,"%d",b);
					mvprintw(8,76,"%f",powerfun(b,0.5));
				}
				if(y==20 && x==80){
					clrscr();
					mvprintw(7,70,"factorial");
					scanw("%d",&b);
					mvprintw(7,80,"%d",b);
					mvprintw(8,76,"%d",fact(b));
				}
				if(y==17 && x==100){
					clrscr();
					mvprintw(7,70,"powerfunction:",b);
					scanw("%f%f",&p,&q);
					mvprintw(7,80,"%f ^ %f",p,q);
					mvprintw(8,76,"%f",powerfun(p,q));
				}
		    		if(y==17 && x==90){
					clrscr();
					mvprintw(7,70,"tan inverse",b);
					scanw("%f",&p);
					if(p > -1 && p<=1)
						a=tan_inv(p);
					else if(p>1){
						w=1/p;
						a= (PI/2)-tan_inv(w);
					}
					else if(p<(-1)){
						w=1/p;
						a= (PI/2)-tan_inv(w);
						a=a*(-1);
					}
					mvprintw(7,80,"%f",p);
					mvprintw(8,76,"%f",a*180/PI);
				}
				if(y==14 && x==70){
					clrscr();
					mvprintw(7,70,"sine");
					scanw("%f",&p);
					mvprintw(7,75,"%f=",p);
					mvprintw(8,76,"%f",sine(p*(PI/180)));
				}
				if(y==17 && x==70){
					clrscr();
					mvprintw(7,70,"sineinv");
					scanw("%f",&p); 
					mvprintw(7,77,"%f",p);
					mvprintw(8,76,"%f",(asin(p)*(180/PI)));
				}
				if(y==14 && x==80){
					clrscr();
					mvprintw(7,70,"cos");
					scanw("%f",&p);
					mvprintw(7,77,"%f",p);
					mvprintw(8,76,"%f",cosine(p*(PI/180)));
				}
				if(y==20 && x==70){
					clrscr();
					for(a=50;a<85;a++){
						mvprintw(7,a," ");
					}
					mvprintw(8,76,"%f",ans);
				}
				if(y==11 && x==80){
					clrscr();
					mvprintw(7,70,"ln");
					scanw("%f",&p);
					mvprintw(7,73,"%f",p);
					mvprintw(8,76,"%f",ln(p));
				}
				if(y==20 && x==50){
					clrscr();
				}
				if(y==14 && x==100){
					clrscr();
					mvprintw(7,70,"e^");
					scanw("%f",&p);
					mvprintw(7,72,"%f",p);
					mvprintw(8,76,"%f",expo(10,p));
				}
				if(y==14 && x==90){
					clrscr();
					mvprintw(7,70,"tan");
					scanw("%f",&p);
					w=sine(p*PI/180)/cos(p*PI/180);
					mvprintw(7,74,"%f",p);
					mvprintw(8,76,"%f",w);
				}
		
				if(y==11 && x==70){
					clrscr();
					mvprintw(7,70,"log");
					scanw("%f",&p);
					mvprintw(7,74,"%f",p);
					mvprintw(8,76,"%f",(ln(p)/2.303));
				}
				if(y==11 && x==90){
					clrscr();
					mvprintw(7,70,"reciprocal");
					scanw("%f",&p);
					mvprintw(7,78,"%f",p);
					mvprintw(8,76,"%f",(1/p));
				}
				if(y==11 && x==100){
					clrscr();
					mvprintw(8,76,"3.1428");
				}
				if(y==20 && x==100){
					endcurses();
					exit(1);
				}
				if(y==17 && x== 80) {
					clrscr();
					mvprintw(7,70,"cosinv");
					scanw("%f",&p); 
					mvprintw(7,77,"%f",p);
					mvprintw(8,76,"%f",acos(p)*(180/PI));
				}
				break;
				
			case 'A' :							/*for numerical calculation press'A'*/
				 noecho();
				int i = 0;
				int y=65;
				while(1) {
					data[i] = getch();
					mvprintw(6,y,"%c",data[i]);
					y++;
					switch(data[i]) {
							case 'C':
								move(20,50);
								goto reset;
								break;
							case '1':
								move(17,50);
								break;
							case '2':
								move(17,55);
								break;
							case '3':
								move(17,60);
								break;
							case '4':
								move(14,50);
								break;
							case '5':
								move(14,55);
								break;
							case '6':
								move(14,60);
								break;
							case '7':
								move(11,50);
								break;
							case '8':
								move(11,55);
								break;
							case '9':
								move(11,60);
								break;
							case '+':
								move(20,65);
								break;
							case '-':
								move(17,65);
								break;
							case '*':
								move(14,65);
								break;
							case '/':
								move(11,65);
								break;
							case '=' :
								goto terminate;
								break;
						}
					i++;
				}
			terminate:	data[i]='\0';
						int j;
						int k;
						i=0;
						while(data[i]!='\0') {
								if(data[i]=='.'){
									i=j;
									 k=10;
									int num=data[i-1]-'0';
									while(isdigit(data[j+1])){
										num=num+(data[j+1]-'0')/k;
										k=k*10;
										j++;
									}
									data[i-1] = (char)(((int)'0')+num);
									k=i;
									while(data[j+1]!='\0'){
										data[k]=data[j];
										k++;
										j++;
									}
									data[k]=data[j];
									data[k+1]='\0';
								}
							i++;
			reset :	for(a=65;a<75;a++)
				mvprintw(6,a," ");
						}
				float x=calculateinfix(data);
				ans = x;
				mvprintw(6,65,"%s",data);
				mvprintw(8,76,"%f",x);
				refresh();
				break;
		}
		if(input == 'q') {
			endcurses();
			exit(1);
		}
	}
}	
 
/*Infix calculation
	It simply saves numbers and operators in diffrent strings
	and performs the calulation respectively
*/
float calculateinfix(char *str1){
	char  str3[64];
	float str2[64];
	int i = 0;
	int j = 0;
	int k = 0;
	int p;
	int num=0;
	float b;
	while(str1[i]!= '\0'){
	  if(isdigit(str1[i])) {					
			while(isdigit(str1[i+1]))
				i++;
			int a= i;
			b=0.1;
			num = 0;
			while(isdigit(str1[a])&& a>=0) {
				b=b*10;
				num = num + b * (str1[a]-'0');
				a--;
			}
			str2[j]=num;
			j++;
	  }
	  else {
			str3[k] = str1[i];
			k++;
     	}
		i++;
	}

	str3[k] = '\0';
	i = 0;
	k = 0;
	j = 0;	
	while(str3[k] != '\0') {
		if(str3[k] == '*' || str3[k] == '/') {
			switch(str3[k]) {
				case '*' :
					str2[i] = str2[i] * str2[i + 1];
					break;
				case '/' :
					str2[i] = str2[i] / str2[i + 1];    
					break;
				default :
					break;
			}
			j = i;
			p = k;
			while(j <= 5) {
				str2[j + 1] = str2[j + 2];
				j++;
			}
			while(str3[p] != '\0') {
				str3[p] = str3[p + 1];
				p++;
			}
			i--;
			k--;
		}
		k++;
		i++;
	} 
	k=0;
	i=0;
	while(str3[k] != '\0') {
		switch(str3[k]) {
			case '+' :
				str2[i + 1] = str2[i] + str2[i + 1];
				break;
			case '-' :
				str2[i + 1] = str2[i] - str2[i + 1];
				break;
			default :
				break;
		}
		i++;
		k++;
	}
	return str2[i];
}	







	




	
