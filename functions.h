#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<string>

//Define the ticker axis sizes
const int M=10;
const int N=70;


//Define the random number seed
const int S=51;

//Primary functions
void genStockTimeSeries(float[],int);
void plotTicker(const std::string, float[], char[][N], int, int);

//Helper functions
float genRandNumber(float,float);
void findMax(float[],int,float &, int &);
void findMin(float[],int,float &, int &);
int scaleTimeSeries(float, float, float, int);

#endif