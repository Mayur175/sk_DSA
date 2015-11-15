
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


/*This file contains all the special function codes*/



#include "cal.h"
#include <ncurses.h>
# define EXP 2.718
#define PI 3.142857
#define ERROR 1.0e-6

/*Takes two arguments x and y and returns x raised to y*/
double powerfun(float x,float y) {
			float z = y * ln(x);
			float p = expo(10000,z);
			return p;
}

/*Takes two arguments x and y and returns x raised to y*/
double expo(int n, float x)
{	
	int i;
     float sum = 1; 
 	for (i = n - 1; i > 0; --i )
        sum = 1 + x * sum / i;
 	 return sum;
}
/*Takes a double value and returns its tan inverse*/
double tan_inv(double x) {
	int q = 3;
	float p = x;
	float term = 1;
	float sum = 0;
	int sign = (-1);
	while((term * term) > ERROR) {
	p = p * x * x;
	term = p/q;
	sum = sum + (sign)*term;
	q = q + 2;
	sign = sign*(-1);
}	
	return ((sum + x));
	   
}

/*sine calculation function*/

double sine(double x) {
	double sum, term, sqx = x * x;
	int i;
	sum = x;
	term = x;
	i = 3;
	while(term > ERROR || -term > ERROR ) {
		term = (-1) * (term * sqx) / (i * (i - 1));
		sum = sum + term;
		
		i = i + 2;
	}
	return (sum);
}
/*calculates ln of a float*/
float ln(float x) {
	int i;
	float term2 = (x-1)/(x+1);
	float prod=term2*term2;
	float term=term2*term2*term2;
	float prod2 = term2 +term/3;
	i = 5;
	float sum = 0;
	while(i < 1000) {
		sum = sum + term * prod/i;
		term = term*prod; 
		i = i + 2;
	}
	return ((sum+prod2) *2);
}

/*factorial calculation*/
int fact(int n){
  if(n==0)
       return 1;
   else
       return(n*fact(n-1));

	return n;
 }


/*clears screen by filling it with blank spaces*/
void clrscr() {
	int i;
	for(i = 40;i<100;i++){
		mvprintw(6,i," ");
		mvprintw(7,i," ");
		mvprintw(8,i," ");			
	}
}
/*calculates cosine of a number*/
double cosine(double x) {
		float y= sine(x);
		float z = powerfun((1-(y*y)),0.5);
		return z;
}

/*sine inverse*/
float sininv(float x) {
	float term = x;
	float term2 = x * x;
	int i,p,q;
	float j,k;
	i=3;
	p=1;
	j=1;
	k=2;
	q=2;
	float sum=0;
	while(i<1000){
		sum = sum + (j * term2 * term)/(i * k);
		term=term * term2;
		j=j * (p+2);
		k=k * (q+2);
		p=p+2;
		q=q+2;
		i=i+2;
	}
	return (x+sum);
}
/*cosine inverse*/
float cosinv(float x) {
		float y = (PI/2)-sininv(x);
		return y;
}




