#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int random(int num,int face);
int main(){
	int num=0;
	int face=0;
	int randvalue=0;
	time_t seconds=0;
	
	seconds=time(NULL)/3600;//获取1970-01-01 起的小时数 
	srand(seconds); 
	
	printf("请输入两个数字，分别代表次数和面数，格式为数字空格数字\n");
	while(1){
		scanf("%d %d",&num,&face);
		randvalue=random(num,face);
		
	}
} 
int random(int num,int face){
	int i=0;
	int onetry=0;
	int facevalue=0;
	
	for(i=0;i<num;i++){
		onetry=rand();
		facevalue=(onetry-onetry%(RAND_MAX/face))/(RAND_MAX/face);//);onetry%(
		if(onetry%(RAND_MAX/face)>0){
			facevalue+=1;
		}
		printf("%dn%d骰子的结果是(%d/%d)\n",num,face,facevalue,face);
	} 
	
}

