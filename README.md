CS212_Lab2
==========

Lab assignment TWO from Programming for Engineers II in C

- Eric Kang
- 02/21/2011
- Section 53
- Lab2

- poly.c

Program Description:
	This program utilizes the use of macros and structures 
	to store polynomial equations and display their sums.

Idiosyncracies:
This program uses only one pointer through out the entire program.
The function TERM() accepts a pointer to a term structure as one of the arguments in order to write or update the value to the member of the structure. This is useful for summing the coefficiens of a term structure by calling the function multiple times with the same nth position argument.
