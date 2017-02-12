#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<Windows.h>

#include"functions.h"

float genRandNumber(float min, float max)
{
	
	   float randvalue = (max-min)*((float)rand()/RAND_MAX)+min;
	return(randvalue);
}

void genStockTimeSeries(float ts[],int N)
{
    float scale = 0.01f;
    for(int i=0; i<N; i++)
    {
        if (i==0)
        {
        ts[i] = 1.0f;
        }
        else
	   {
            ts[i] = ts[i-1]+genRandNumber(-scale,scale);
        }
	   //std:: cout<< ts[i] << std::endl;
    }


}

//Compute the maximum of the time-series array
void findMax(float ts[], int N, float & max, int & maxIndex)
{
    for(int i=0; i<N; i++)
    {
        if(max < ts[i])
        {
            max = ts[i];
            maxIndex = i;
        }
    }
}

//Compute the minimum of the time-series array
void findMin(float ts[], int N, float & min, int & minIndex)
{
    for(int i=0; i<N; i++)
    {
        if(min > ts[i])
        {
            min = ts[i];
            minIndex = i;
        }
    }

}


int scaleTimeSeries(float ts, float min, float max, int M)
{
	int d;
        for(int i=0; i<M; i++){
		d = int((M-1)*(ts-min)/(max-min));
        }
	return(d);
}


void plotTicker(const std::string sybmol, float ts[], char ticker[][N], int M, int N)
{

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hstdout, 2+15*16);
	float min = 1.0f;
	float max = 0.0f;
	int minIndex = -1;
	int maxIndex = 1;
	findMin(ts, N, min, minIndex);
	findMax(ts, N, max, maxIndex);
	const int n=70;
	const int m=10;
	int tsint[n];
	int stInt[m];
	char tickertwo[m][n];
	std::cout << sybmol << std::endl;
    for(int i=0; i<N; i++)
    {
	    tsint[i] = scaleTimeSeries(ts[i],min,max,M);
		ticker[tsint[i]][i] = '*';
		   //std::cout << ticker[tsint[i]][i];
    }
    
    for(int j=M; j>0; --j)
	// have this decrement by M-1
    {
	   if( j == 10)
	    {
		    std::cout << "1.01 ";
	    }
	    else if( j == 1)
	    {
		    std::cout << "0.94 ";
	    }
	    else
	    {
		    std::cout<< "     ";
	    }
	    std::cout << "|";
		for(int i=0; i<N; i++)
		{
			if(tsint[i] == j)
			{
				ticker[j][i] == ticker[tsint[i]][i];
			}
			else if(tsint[i] != j)
			{
				ticker[j][i] = ' ';
			}
		std::cout << ticker[j][i];
		}
		std::cout << std::endl;
    }
    for(int k=0; k<N; k++)
    {
	if(k == 1)
	{
		std::cout << "+";
	}
	else if(k > 0)
	    {
		    std::cout << "-";
	    }
	    else
	    {
		    std::cout << "     ";
	    }
    }
   std::cout << std::endl;
   for(int l=0; l<N; l++)
    {
	if(l == 56)
	{
		std::cout << "+";
	}
	else if(l == 32)
	    {
		    std::cout << "-";
	    }
	else
	{
		std::cout << " ";
	}
    }
   std::cout << std::endl;
  
}
