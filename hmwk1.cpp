/*
* Author:	James Norcross
*			UALR
* 
* Date:		Sep. 24, 2015	
*
* File:		hmwk1.cpp
*
* Purpose:	The purpose of this homework is to review all basic and advancedProgramming I topics
*           that was coveed in class
*           
*/

#include<cstdlib>
#include<ctime>
#include"functions.h"

int main()
{
	system("cls");
  //Initialized the random number generator
  srand(S);

  //Allocate space for the ticker
  float price[N];
  char ticker[M][N];


  //Generate floating point prices of size N
  genStockTimeSeries(price,N);
  //Plot the M-discretized, formatted ticker
  plotTicker("NYSE:BUSH",price,ticker,M,N);

  
  system("PAUSE");
  

  return 0;

}
