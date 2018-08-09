#include <algorithm>   
#include <iostream>
#include <iomanip>     
#include <fstream>     
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      
using namespace std; 

int main()
{

	
	char ch;
	int Apple=0,iPhone=0,iPad=0,iPod=0,Sony=0;
	while(ch=getchar())
	{
		if(ch==EOF)break;
		if(ch==' ')continue;
		switch(ch){
			case 'A':{
				Apple++;
				break;
			}
			case 'S':{
				Sony++;
				break;
			}
			case 'i':{
				iPod++;
				iPhone++;
				iPad++;
				break;
			}
			case 'p':{
				if(Apple==1||Apple==2){
					Apple++;
				}
				break;
			}
			case 'l':{
				if(Apple==3){
					Apple++;
				}
				break;
			}
			case 'e':{
				if(Apple==4){
					printf("MAI MAI MAI!\n");
					Apple=0;
				}
				if(iPhone==5){
					printf("MAI MAI MAI!\n");
					iPhone=0;
				}
				break;
			}
			case 'h':{
				if(iPhone==2){
					iPhone++;
				}
				break;
			}
			case 'P':{
				if(iPhone==1){
					iPhone++;
				}
				if(iPod==1){
					iPod++;
				}
				if(iPad==1){
					iPad++;
				}
				break;
			}
			case 'o':{
				if(iPhone==3){
					iPhone++;
				}
				if(iPod==2){
					iPod++;
				}
				if(Sony==1){
					Sony++;
				}
				break;
			}
			case 'n':{
				if(iPhone==4){
					iPhone++;
				}
				if(Sony==2){
					Sony++;
				}
				break;
			}
			case 'a':{
				if(iPad==2){
					iPad++;
				}
				break;
			}
			case 'd':{
				if(iPad==3){
					printf("MAI MAI MAI!\n");
					iPad=0;
				}

				if(iPod==3){
					printf("MAI MAI MAI!\n");
					iPod=0;
				}
				break;
			}
			case 'y':{
				if(Sony==3){
					printf("SONY DAFA IS GOOD!\n");
				}
				Sony=0;
				break;
			}
			Apple=0;iPad=0;iPod=0;iPhone=0;Sony=0;

		}
	}
	
	//printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );

}
