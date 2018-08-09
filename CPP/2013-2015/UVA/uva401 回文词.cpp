//uva401
#include <string.h>
#include <stdio.h> //gets()
#include <fstream>  
#define MAXN 1010

const char  *ch1="AEHIJLMOSTUVWXYZ12358";
const char  *ch2="A3HILJMO2TUVWXY51SEZ8";
char str[MAXN];
int len;

int is_p(const char *str){
	if(len==1)return 1;
	for(int i=0;i<len-1-i;i++){
		if(str[i]!=str[len-1-i]){
			//printf("%c  !=  %c\n", str[i],str[len-1-i]);
			return 0;
		}
	}
	return 1;
}
/*int is_m(const char *str){

	int pos1=-1,pos2=-1;
	if(len==1){
		for(int j=0;j<21;j++){
			if(ch1[j]==str[0])
				pos1=j;
		}
		//printf("pos1 = %d\n",pos1 );
		if(pos1==-1){
			//printf("pos=-1 return 0\n");
			return 0;
		}

		//printf("ch1 ch2 : %c %c\n",ch1[pos1],ch2[pos1] );
		if( ch1[pos1]==ch2[pos1] ){
			//printf("return 1\n");
			return 1;
		}
		else return 0;
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<21;j++){
			if(ch1[j]==str[i])
				pos1=j;
		}
		for(int j=0;j<21;j++){
			if(ch2[j]==str[len-1-i])
				pos2=j;
		}
		if( pos1 !=pos2 ) {
			//printf("pos: %d %d\n",pos1,pos2 );
			return 0;
		}
	}
	return 1;
}*/
int is_m(const char *str)
{
	int table_len = 21;
	int i,j;
	if(len == 1)
	{
		for(j=0; j<21 ; j++)
		{
			if(ch1[j] == str[0])
				break;
		}
		if(j == 21 || ch2[j] != str[0])
			return 0;
	}
	else if(len > 1)
		for(i=0; i<len/2; i++)
		{
			for(j=0; j<21 ; j++)
			{
				if(ch1[j] == str[i])
					break;
			}	
			if(j == 21 || ch2[j] != str[len-i-1])
				return 0;
		}
	return 1;
}
int main(){
	freopen("in.txt","r",stdin);
	while( scanf("%s",str) != EOF ){
		len=strlen(str);
		//printf("len = %d\n",len );
		if(is_p(str))  
        {  
            if(is_m(str))  
                printf("%s -- is a mirrored palindrome.\n\n",str);  
            else  
                printf("%s -- is a regular palindrome.\n\n",str);  
        }  
        else  
        {  
            if(is_m(str))  
                printf("%s -- is a mirrored string.\n\n",str);  
            else  
                printf("%s -- is not a palindrome.\n\n",str);  
        }  
	}

}