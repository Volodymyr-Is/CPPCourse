#pragma once
//#define N 10

#define INPUTMAS(mas,n)\
{ for (int i=0;i<n;i++){\
std::cout<<"Enter element "<<i<<": ";\
std::cin>>mas[i];}\
}

#define OUTMAS(mas,n)\
{ std::cout<<std::endl;\
for (int i=0;i<n;i++)\
std::cout<<mas[i]<<"\t";\
}

#define FINDMAX(mas,n, indexMax)\
{int indexMax=0;\
for (int i=1;i<n;i++)\
if(mas[i]>mas[indexMax])\
indexMax=i;\
std::cout<<"\nMax element index: "<<indexMax;\
}

#define MULTBETWEENZEROS(mas,n, mult)\
{int firstZeroIndex=-1, lastZeroIndex=-1;\
for(int i=0;i<n;i++){\
if (mas[i] == 0){\
if (firstZeroIndex == -1) firstZeroIndex = i;\
lastZeroIndex = i;\
}}\
int mult=1;\
if(firstZeroIndex!=-1 && lastZeroIndex!=-1 && firstZeroIndex != lastZeroIndex){\
for(int i=firstZeroIndex+1;i<lastZeroIndex;i++)\
mult*=mas[i];\
}\
else mult=0;\
std::cout<<std::endl<<"Mult: "<<mult;\
}

#define ARRAYREBUILD(mas,n)\
{int temp[n];\
int evenIndex=0, oddIndex=(n+1)/2;\
for(int i=0; i<n; i++){\
if(i%2==0) temp[evenIndex++] = mas[i];\
else temp[oddIndex++] = mas[i];\
}\
for(int i=0; i<n; i++)\
mas[i]=temp[i];\
OUTMAS(mas,n);\
std::cout<<std::endl;\
}