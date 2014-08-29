/*
Eric Kang
Section 53
Lab2

Program Description:
	This program utilizes the use of macros and structures 
	to store polynomial equations and display their sums.

Functions:
	void TERM()
		-Descriptipn:
			This function re-writes the value of specific members of a specified 
			term array based. The first argument is a pointer to a term array 
			that is incremented to the position specified by the n argument. 
			c is added to whatever value previously stored at that specific location.
		- Inputs:
			name	(term pointer)
			n		(int)
			c		(int)
			e 		(int)
		- Outputs
			(none)
		

	void addPoly()
		- Description:
			This function sums any two polynomial functions
			and writes their sum to total[] by calling the
			TERM() function. 
		- Inputs:
			name1[]	(term)
			n1Max	(int)
			name2[]	(term)
			n2Max	(int)
			total[]	(term)
			totalMax(int)
		- Outputs:
			(none)


	void printPoly()
		- Description:
			This function prints any size polynomial given a specified size.
		- Inputs:
			name[]	(term)
			m		(int)
		- Outputs:
			(none)
			
*/
#include <stdio.h>

#define  POLY(name,deg)                 \
              term   name[deg] = {0}; 

typedef struct 
          {   int  coeff;
              int  exp; 
          } term;

void TERM(term *name, int n, int c, int e);

void addPoly( term name1[], int n1Max, term name2[], int n2Max, term total[], int totalMax );

void printPoly( term name[], int m );


int main()
{


	//initialize polynomials
	POLY(p1,5);
	POLY(p2,10);
	POLY(p3,7);
	POLY(p4,10); // p1 + p2
	POLY(p5,10); // p1 + p2 + p3
	

	//p1 polynomial 3x^4 + 2x^3 + x^2 + 2x + 1
	TERM(p1,0,3,4);
	TERM(p1,1,2,3);
	TERM(p1,2,1,2);
	TERM(p1,3,2,1);
	TERM(p1,4,1,0);

	//p2 polynomial 3x^9 + 2x^3 + 1
	TERM(p2,0,3,9);
	TERM(p2,3,2,3);
	TERM(p2,9,1,0);

	//p3 polynomial 3x^6 + 1
	TERM(p3,0,3,6);
	TERM(p3,6,1,0);
	
	//Add p1 and p2 and store total in p4
	addPoly( p1, 5, p2, 10, p4, 10);
	//Add p4 and p3 and store total in p5
	addPoly( p4, 10, p3, 7, p5, 10);

	//Print Polynomials
	printf("\nPolynomial 1 is:\n");
	printPoly( p1, 5);
	
	printf("Polynomial 2 is:\n");
	printPoly( p2, 10);

	printf("Polynomial 3 is:\n");
	printPoly( p3, 7);

	printf("Polynomial 1 + Polynomial 2 is:\n");
	printPoly( p4, 10);

	printf("Polynomial 1 + Polynomial 2 + Polynomial 3 is:\n");
	printPoly( p5, 10);



	return 0;
}//END main()

void printPoly( term name[], int m )
{
	int j;	//counter
	
	for( j=0; j<=(m-1); j++ )
	{
		if(name[j].exp == 1)	//handling c*x
		{
			printf("%dx + ", name[j].coeff);
		}//END if
		else if( name[j].coeff && name[j].exp == 0 ) //handling constants
		{
			printf("%d\n", name[j].coeff);
		}//END constant else if
		else if( name[j].coeff )	//handling c*x^e
		{
			printf("%dx^%d + ", name[j].coeff, name[j].exp);
		}//End else if		
	}//END for
	printf("\n");
}//END printPoly()

void addPoly( term name1[], int n1Max, term name2[], int n2Max, term total[], int totalMax )
{
	int i;	//counter

	//Add name1 to total
	for( i = 0; i <= (n1Max-1); i++ )
	{
		if( name1[i].coeff )	//if coeff != 0
		{
			TERM(total,(totalMax-1)-name1[i].exp,name1[i].coeff,name1[i].exp);

		}//END name1 if
	}//END name1 for

	//Add name2 to total
	for( i = 0; i <= (n2Max-1); i++ )
	{
		if( name2[i].coeff ) //if coeff != 0
		{
			
			TERM(total,(totalMax-1)-name2[i].exp,name2[i].coeff,name2[i].exp);

		}//END name2 if
	}//END name2 for
}//END addPoly()

void TERM(term *name, int n, int c, int e)
{
	//move name pointer to nth position of term array	
	name += n;
	(*name).coeff += c;
	(*name).exp = e;
}//END TERM()
