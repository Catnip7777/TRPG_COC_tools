#include<stdio.h>
#include<windows.h>

#define CODE_MAX 5//指令最长长度5

int errornum=0; 
int ordercode=0; 
int messagenum=0;
char coderegist[CODE_MAX]={'0'};
int codelength=0;
int showplid=0;//show pl now in details
	

int num=0;int face=0;int dicevalue[99]={0};//dice

struct pcnpc{
	char name[100];
	char sex[100];
	char job[100];
	int age;

	int str;
	int con;
	int pow;
	int dex;
	int app;
	int siz;
	int inta;
	int edu;
	
	int mov;
	
	int hp;
	int san;
	int mp;
	int luk;
	
	char wa1[100];
	char wa2[100];
	char wa3[100];
	char wa4[100];
	char wa5[100];
	char wa6[100];
	char wa7[100];
	char wa8[100];
	char wa9[100];
	char ha1[100];
	char ha2[100];
	char ha3[100];
	char ha4[100];
	
	char bgmes[500];
	char things[500];
};
struct pcnpc pcnpcarray[10];//data 

int screenstate=0;//0=default,1=details 
int scenepl=0;//0000 0000 00

int readcode();
int input(void);
int process();
void print(void);
void changevalue(); 
void changeScreenState();
void battleScene();
int pcnpcwrite();

int main(){
	 
	
	while(1){
		print();
		readcode();
		input(); 
		process();
		
	}
	return 0;
} 

int readcode(){//指令模块 
	int readnum=CODE_MAX+1;int i,j,k;char tmp[readnum];int orderlength=0; 
	
	for(j=0;j<readnum;j++) {
			tmp[j]='0'; 
		} 
	
	for(j=0;j<readnum;j++){
		scanf("%c",&tmp[j]);
		if(tmp[j]=='\n'||tmp[j]==' '){
			orderlength=j; 
			break;	
		}
	} 
	if(tmp[orderlength]!=' '){
		fflush(stdin);
	} 

	if(tmp[readnum-1]!=' '&&tmp[readnum-1]!='0'&&tmp[readnum-1]!='\n'){
		return 0;//printf("error1");return 0;//errornum=1;单独指令头超长的情况是不存在的，往往是整个指令才能超长 
	}else{
		for(k=0;k<orderlength;k++){
			coderegist[k]=tmp[k];
		}
		coderegist[orderlength]='\0';
				/*for(k=0;k<orderlength;k++){
			printf("%c",coderegist[k]);
		}*/
		codelength=orderlength;//printf("%d",orderlength);
		
		return 0;
	}
}

int input(void){
	
	if(strcmp(coderegist,"dd")==0){
		ordercode=1;//printf("code1");
	}else if(strcmp(coderegist,"in")==0){
		ordercode=2;//printf("code2");
	}else if(strcmp(coderegist,"out")==0){
		ordercode=3;
	}else if(strcmp(coderegist,"cv")==0){
		ordercode=4;
	}else if(strcmp(coderegist,"cdt")==0){
		ordercode=5;
	}else if(strcmp(coderegist,"bts")==0){
		ordercode=6;
	}else{
		errornum=1;//printf("error4");
	}
	
	int i;
	for(i=0;i<CODE_MAX;i++){
		coderegist[i]=0;
	} 
	codelength=0;
} 
int process(){
	if(ordercode==1){
		if(scanf("%d %d",&num,&face)==2){
			random(num,face);
		}else{
			errornum=2; 
		}
		ordercode=0;fflush(stdin);
	}else if(ordercode==2){
		pcnpcread();
		ordercode=0;fflush(stdin);
	}else if(ordercode==3){
		pcnpcwrite();
		ordercode=0;fflush(stdin);
	}else if(ordercode==4){
		changevalue();
		ordercode=0;fflush(stdin);
	}else if(ordercode==5){
		changeScreenState();
		ordercode=0;fflush(stdin);
	}else if(ordercode==6){
		battleScene();
		ordercode=0;fflush(stdin);
	}
}

void print(void){
	system("cls"); 
	printf("COC显示面板@版本：v1.0.0\n\n"); 
	printf("--状态面板--\n");
	if(screenstate==0){
		printf("pc：\n");
			printf("---------------id=0----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[0].name,pcnpcarray[0].sex,pcnpcarray[0].job,pcnpcarray[0].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[0].hp,pcnpcarray[0].san,pcnpcarray[0].mp,pcnpcarray[0].luk);
			printf("随身物品:%s\n",pcnpcarray[0].things);
			
			printf("---------------id=1----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[1].name,pcnpcarray[1].sex,pcnpcarray[1].job,pcnpcarray[1].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[1].hp,pcnpcarray[1].san,pcnpcarray[1].mp,pcnpcarray[1].luk);
			printf("随身物品:%s\n",pcnpcarray[1].things);
			
			printf("---------------id=2----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[2].name,pcnpcarray[2].sex,pcnpcarray[2].job,pcnpcarray[2].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[2].hp,pcnpcarray[2].san,pcnpcarray[2].mp,pcnpcarray[2].luk);
			printf("随身物品:%s\n",pcnpcarray[2].things);
			
			printf("---------------id=3----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[3].name,pcnpcarray[3].sex,pcnpcarray[3].job,pcnpcarray[3].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[3].hp,pcnpcarray[3].san,pcnpcarray[3].mp,pcnpcarray[3].luk);
			printf("随身物品:%s\n",pcnpcarray[3].things);
			
			printf("---------------id=4----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[4].name,pcnpcarray[4].sex,pcnpcarray[4].job,pcnpcarray[4].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[4].hp,pcnpcarray[4].san,pcnpcarray[4].mp,pcnpcarray[4].luk);
			printf("随身物品:%s\n",pcnpcarray[4].things);
		
		printf("\n");
		
		printf("npc：\n");
			printf("---------------id=5----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[5].name,pcnpcarray[5].sex,pcnpcarray[5].job,pcnpcarray[5].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[5].hp,pcnpcarray[5].san,pcnpcarray[5].mp,pcnpcarray[5].luk);
			printf("随身物品:%s\n",pcnpcarray[5].things);
			
			printf("---------------id=6----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[6].name,pcnpcarray[6].sex,pcnpcarray[6].job,pcnpcarray[6].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[6].hp,pcnpcarray[6].san,pcnpcarray[6].mp,pcnpcarray[6].luk);
			printf("随身物品:%s\n",pcnpcarray[6].things);
			
			printf("---------------id=7----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[7].name,pcnpcarray[7].sex,pcnpcarray[7].job,pcnpcarray[7].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[7].hp,pcnpcarray[7].san,pcnpcarray[7].mp,pcnpcarray[7].luk);
			printf("随身物品:%s\n",pcnpcarray[7].things);
			
			printf("---------------id=8----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[8].name,pcnpcarray[8].sex,pcnpcarray[8].job,pcnpcarray[8].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[8].hp,pcnpcarray[8].san,pcnpcarray[8].mp,pcnpcarray[8].luk);
			printf("随身物品:%s\n",pcnpcarray[8].things);
			
			printf("---------------id=9----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[9].name,pcnpcarray[9].sex,pcnpcarray[9].job,pcnpcarray[9].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[9].hp,pcnpcarray[9].san,pcnpcarray[9].mp,pcnpcarray[9].luk);
			printf("随身物品:%s\n",pcnpcarray[9].things);
	}else if(screenstate==1){
		printf("\n");
		printf("---------------id=%d---------------------------------------------------------------------------------\n",showplid);
			printf("基本信息：\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[showplid].name,pcnpcarray[showplid].sex,pcnpcarray[showplid].job,pcnpcarray[showplid].age); 
			printf("\n");
			printf("基本属性：\n");
			printf("力量:%d|体质:%d|意志:%d|敏捷:%d|外貌:%d|体型:%d|智力:%d|教育:%d\n",pcnpcarray[showplid].str,pcnpcarray[showplid].con,pcnpcarray[showplid].pow,pcnpcarray[showplid].dex,pcnpcarray[showplid].app,pcnpcarray[showplid].siz,pcnpcarray[showplid].inta,pcnpcarray[showplid].edu);
			printf("\n");
			printf("次要属性：\n");
			printf("伤害加值DB:|体格Build:|移动速度MOV:%d|幸运:%d\n",pcnpcarray[showplid].mov,pcnpcarray[showplid].luk);
			printf("\n");
			printf("状态：\n");
			printf("耐久HP:%d|理智SAN:%d|魔法MP:%d\n",pcnpcarray[showplid].hp,pcnpcarray[showplid].san,pcnpcarray[showplid].mp);
			printf("\n");
			printf("职业技能：\n");
			printf("1.%s|2.%s|3.%s|4.%s|5.%s|6.%s|7.%s|8.%s|9.%s \n",pcnpcarray[showplid].wa1,pcnpcarray[showplid].wa2,pcnpcarray[showplid].wa3,pcnpcarray[showplid].wa4,pcnpcarray[showplid].wa5,pcnpcarray[showplid].wa6,pcnpcarray[showplid].wa7,pcnpcarray[showplid].wa8,pcnpcarray[showplid].wa9); 
			printf("\n");
			printf("个人兴趣技能：\n");
			printf("1.%s|2.%s|3.%s|4.%s\n",pcnpcarray[showplid].ha1,pcnpcarray[showplid].ha2,pcnpcarray[showplid].ha3,pcnpcarray[showplid].ha4);
			printf("\n");
			printf("背景信息:%s\n",pcnpcarray[showplid].bgmes);
			printf("随身物品:%s\n",pcnpcarray[showplid].things);
	}else if(screenstate==2){
		//printf("blank");
		//printf("%d",scenepl);
		if(scenepl&0x01!=0){
			printf("---------------id=0----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[0].name,pcnpcarray[0].sex,pcnpcarray[0].job,pcnpcarray[0].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[0].hp,pcnpcarray[0].san,pcnpcarray[0].mp,pcnpcarray[0].luk);
			printf("随身物品:%s\n",pcnpcarray[0].things);printf("\n");
		}
		if((scenepl&0x02)!=0){
			printf("---------------id=1----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[1].name,pcnpcarray[1].sex,pcnpcarray[1].job,pcnpcarray[1].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[1].hp,pcnpcarray[1].san,pcnpcarray[1].mp,pcnpcarray[1].luk);
			printf("随身物品:%s\n",pcnpcarray[1].things);printf("\n");
		}
		if((scenepl&0x04)!=0){
			printf("---------------id=2----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[2].name,pcnpcarray[2].sex,pcnpcarray[2].job,pcnpcarray[2].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[2].hp,pcnpcarray[2].san,pcnpcarray[2].mp,pcnpcarray[2].luk);
			printf("随身物品:%s\n",pcnpcarray[2].things);printf("\n");
		}
		if((scenepl&0x08)!=0){
			printf("---------------id=3----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[3].name,pcnpcarray[3].sex,pcnpcarray[3].job,pcnpcarray[3].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[3].hp,pcnpcarray[3].san,pcnpcarray[3].mp,pcnpcarray[3].luk);
			printf("随身物品:%s\n",pcnpcarray[3].things);printf("\n");
		}
		if((scenepl&0x10)!=0){
			printf("---------------id=4----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[4].name,pcnpcarray[4].sex,pcnpcarray[4].job,pcnpcarray[4].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[4].hp,pcnpcarray[4].san,pcnpcarray[4].mp,pcnpcarray[4].luk);
			printf("随身物品:%s\n",pcnpcarray[4].things);printf("\n");
		}
		if((scenepl&0x20)!=0){
			printf("---------------id=5----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[5].name,pcnpcarray[5].sex,pcnpcarray[5].job,pcnpcarray[5].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[5].hp,pcnpcarray[5].san,pcnpcarray[5].mp,pcnpcarray[5].luk);
			printf("随身物品:%s\n",pcnpcarray[5].things);printf("\n");
		}
		if((scenepl&0x40)!=0){
			printf("---------------id=6----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[6].name,pcnpcarray[6].sex,pcnpcarray[6].job,pcnpcarray[6].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[6].hp,pcnpcarray[6].san,pcnpcarray[6].mp,pcnpcarray[6].luk);
			printf("随身物品:%s\n",pcnpcarray[6].things);printf("\n");
		}
		if((scenepl&0x80)!=0){
			printf("---------------id=7----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[7].name,pcnpcarray[7].sex,pcnpcarray[7].job,pcnpcarray[7].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[7].hp,pcnpcarray[7].san,pcnpcarray[7].mp,pcnpcarray[7].luk);
			printf("随身物品:%s\n",pcnpcarray[7].things);printf("\n");
		}
		if((scenepl&0x100)!=0){
			printf("---------------id=8----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[8].name,pcnpcarray[8].sex,pcnpcarray[8].job,pcnpcarray[8].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[8].hp,pcnpcarray[8].san,pcnpcarray[8].mp,pcnpcarray[8].luk);
			printf("随身物品:%s\n",pcnpcarray[8].things);printf("\n");
		}
		if((scenepl&0x200)!=0){
			printf("---------------id=9----------------\n");
			printf("姓名:%s|性别:%s|职业:%s|年龄:%d\n",pcnpcarray[9].name,pcnpcarray[9].sex,pcnpcarray[9].job,pcnpcarray[9].age); 
			printf("HP%d|SAN:%d|MP:%d|LUK:%d\n",pcnpcarray[9].hp,pcnpcarray[9].san,pcnpcarray[9].mp,pcnpcarray[9].luk);
			printf("随身物品:%s\n",pcnpcarray[9].things);printf("\n");
		}
		if(scenepl==0){
			printf("blank_这里没有人");printf("\n");
		}
	}
		
		
		
		
		printf("\n");
		printf("\n");
	printf("--命令--\n");
		printf("导入/导出：in/out 文件名 id\t修改状态数值：cv id 属性名 值\t\n");
		printf("查看/退出卡详细信息:cdt id\t战斗轮：bts 添加+id|删除-id|打开界面*|清除场景/\n");
	printf("\n");
	printf("--常用工具--\n");
		printf("骰子工具：dd\t其他工具开发中。。。\n\n");
			
	 
		  if(errornum==1){
		printf("指令错误，未知指令\n\n"); errornum=0;
	}else if(errornum==2){
		printf("数值错误，输入非数值\n"); errornum=0;
	}else if(errornum==3){
		printf("数值错误，请输入合法范围!\n"); errornum=0;
	}else if(errornum==4){
		printf("文件错误，找不到卡文件\n");errornum=0;	
	}else{
		if(num!=0&&face!=0){
			int i=0;
			for(i=0;i<num;i++){
				printf("%dD%d骰子的结果是(%d/%d)\n",num,face,dicevalue[i],face);
			} 
			for(i=0;i<num;i++){
				dicevalue[i]=0;
			}num=0;face=0;
		}
		if(messagenum==1){
			printf("修改完成\n");messagenum=0;
		}else if(messagenum==2){
			printf("读取完成\n");messagenum=0;
		}else if(messagenum==3){
			printf("写入完成\n");messagenum=0;
		}

	} 
	
	printf("命令>>");
	
}
int random(int num,int face){
	int i=0;
	int onetry=0;
	int facevalue=0;
	if(num>0&&num<=10&&face>0&&face<=400) {

	for(i=0;i<num;i++){
		onetry=rand();
		facevalue=(onetry-onetry%(RAND_MAX/face))/(RAND_MAX/face);//);onetry%(
		if(onetry%(RAND_MAX/face)>0){
			facevalue+=1;
		}
		dicevalue[i]=facevalue;
		//printf("%dD%d骰子的结果是(%d/%d)\n",num,face,facevalue,face);
	}
			
	}else{
		errornum=3;num=0;face=0;
	}
}
int pcnpcread(){
	char tmpfile[100];int pcnpcid;
	//printf("输入文件名");
	scanf("%s %d",&tmpfile,&pcnpcid);
	FILE *fp=NULL;
	fp=fopen(tmpfile,"r");
	if(fp==NULL){errornum=4;return 0;}
	//printf("打开成功");
	int lock=1;int lock1=1;
	while(lock1){
		while(lock){
			char c=fgetc(fp);
			if(c==-1){messagenum=2;fclose(fp); return 0;
			}
		//printf("%c",c);
			if(c=='#')lock=0;
		} 
		char char1[100];
		fscanf(fp,"%s",&char1);
		
		
		
		if(strncmp(char1,"name",4)==0){//修改name、4、5即可 
			char *char2=char1+5;
			strcpy(pcnpcarray[pcnpcid].name, char2);//printf("%s",pcnpcarray[pcnpcid].name);//字符提取
		}else if(strncmp(char1,"sex",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].sex, char2);//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"job",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].job, char2);//printf("%s",char2);//字符提取
		} else if(strncmp(char1,"age",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].age=i;//printf("%s",char2);//字符提取
			
		} else if(strncmp(char1,"str",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].str=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"con",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].con=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"pow",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].pow=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"dex",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].dex=i;//printf("%s",char2);//字符提取
		} else if(strncmp(char1,"app",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].app=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"siz",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].siz=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"inta",4)==0){
			char *char2=char1+5;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].inta=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"edu",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].edu=i;//printf("%s",char2);//字符提取
		}
		
		
		else if(strncmp(char1,"mov",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].mov=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"luk",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].luk=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"hp",2)==0){
			char *char2=char1+3;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].hp=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"san",3)==0){
			char *char2=char1+4;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].san=i;//printf("%s",char2);//字符提取
		}else if(strncmp(char1,"mp",2)==0){
			char *char2=char1+3;
			int i=atoi(char2);
			pcnpcarray[pcnpcid].mp=i;//printf("%s",char2);//字符提取
		}
		
		
		else if(strncmp(char1,"wa1",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa1, char2);
		}else if(strncmp(char1,"wa2",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa2, char2);
		}else if(strncmp(char1,"wa3",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa3, char2);
		}else if(strncmp(char1,"wa4",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa4, char2);
		}else if(strncmp(char1,"wa5",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa5, char2);
		}else if(strncmp(char1,"wa6",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa6, char2);
		}else if(strncmp(char1,"wa7",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa7, char2);
		}else if(strncmp(char1,"wa8",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa8, char2);
		}else if(strncmp(char1,"wa9",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].wa9, char2);
		}else if(strncmp(char1,"ha1",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].ha1, char2);
		}else if(strncmp(char1,"ha2",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].ha2, char2);
		}else if(strncmp(char1,"ha3",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].ha3, char2);
		}else if(strncmp(char1,"ha4",3)==0){
			char *char2=char1+4;
			strcpy(pcnpcarray[pcnpcid].ha4, char2);
		}else if(strncmp(char1,"bgmes",5)==0){
			char *char2=char1+6;
			strcpy(pcnpcarray[pcnpcid].bgmes, char2);
		}else if(strncmp(char1,"things",6)==0){
			char *char2=char1+7;
			strcpy(pcnpcarray[pcnpcid].things, char2);
		}

		//printf("找到了");识别字符 
		//printf("%s\n",char1);读取文件 
		lock=1;
	}
	
} 
void changevalue(){
	int a,c;
	char b[10];
	scanf("%d %s %d",&a,b,&c);
	//printf("%d %s %d\n",a,b,c);
	
	if(strcmp(b,"hp")==0){
		pcnpcarray[a].hp=c;
	}else if(strcmp(b,"san")==0){
		pcnpcarray[a].san=c;
	}else if(strcmp(b,"mp")==0){
		pcnpcarray[a].mp=c;
	}
	messagenum=1; 
	//printf("%d\n",myst.abb);

}
void changeScreenState(){
	int a;
	scanf("%d",&a);
	showplid=a;
	if(screenstate==1){
		screenstate=0;
	}else{
		screenstate=1;
	}
	
	messagenum==1; 
}

void battleScene(){
	char c;int a;
	scanf("%c",&c);
	if(c=='+'){
		scanf("%d",&a);//id
		scenepl+=1<<a;
	}else if(c=='-'){
		scanf("%d",&a);//id
		scenepl-=1<<a; 
	}else if(c=='*'){
		if(screenstate==2){
			screenstate=0;
		}else{
			screenstate=2;
		}
		
	}else if(c=='/'){
		scenepl=0;
	}
}

int pcnpcwrite(){
	char tmpfile[100];int pcnpcid;
	//printf("输入文件名");
	scanf("%s %d",&tmpfile,&pcnpcid);
	FILE *fp=NULL;
	fp=fopen(tmpfile,"r+");
	if(fp==NULL){errornum=4;return 0;}
	
	int lock=1;int lock1=1;fpos_t offsetnow;
	while(lock1){
		while(lock){
			char c=fgetc(fp);//printf("%c",c);
			if(c==-1){messagenum=3; fclose(fp); return 0;}
			if(c=='#')lock=0;
		} 
		fgetpos(fp,&offsetnow);
		char char1[100];
		fscanf(fp,"%s",&char1);
		
		
		
		/*if(strncmp(char1,"name",4)==0){//修改name、4、5即可 
			fsetpos(fp,&offsetnow);	
			printf("%s",char1);fprintf(fp,"name=%s_",pcnpcarray[pcnpcid].name);fflush(fp);
		}*/
		if(strncmp(char1,"hp",2)==0){//修改name、4、5即可 
			fsetpos(fp,&offsetnow);	
			fprintf(fp,"hp=%d  ",pcnpcarray[pcnpcid].hp);fflush(fp);
		}else if(strncmp(char1,"san",3)==0){
			fsetpos(fp,&offsetnow);	
			fprintf(fp,"san=%d  ",pcnpcarray[pcnpcid].san);fflush(fp);
		}else if(strncmp(char1,"mp",2)==0){
			fsetpos(fp,&offsetnow);	
			fprintf(fp,"mp=%d  ",pcnpcarray[pcnpcid].mp);fflush(fp);
		}
		lock=1;
	}
}
