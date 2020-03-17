/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status; 
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct     //顺序表（顺序结构）的定义
{ 
	ElemType * elem;
	int length;
	int listsize;
}SqList;

status IntiaList(SqList & L) //初始化线性表 
{
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L.elem) exit(OVERFLOW);
	L.length=0;
    L.listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList & L)	//销毁线性表 
{
	if(!L.elem) return ERROR;
	free(L.elem); 
	L.elem=NULL;
	return OK;	
}

status ClearList(SqList &L) //清空线性表 
{
	if(L.length==0||L.elem==NULL) return ERROR;
	L.length=0;
	return OK;
}

status ListEmpty(SqList L) //判断线性表是否为空 
{
	if(L.elem==NULL) return ERROR-1;
	if(L.length==0) return TRUE;
	else return FALSE;
}
int* ListLength(SqList L) //返回线性表的长度 
{
	int* p;
	p=&L.length;
	if(!L.elem) return ERROR;
	return p;
}

status GetElem(SqList L,int i,ElemType & e) //获取线性表的第i个位置上的元素并赋值给e返回。 
{
	if(!L.elem) return ERROR;
	if(L.length<i||i<=0) return ERROR-1;
	e=L.elem[i-1];
	return e;
}
status LocateElem(SqList L,ElemType e) //找出元素e在线性表中第一次出现的位置并返回它的位置 
{
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i]==e) return i+1;	
	}	
	return ERROR;
}
status PriorElem(SqList L,ElemType cur,ElemType & pre_e) //找到线性表的元素cur的前驱，并赋值给pre_e 
{
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		if(cur==L.elem[i]&&i>0) 	
		{
			pre_e=L.elem[i-1];
			return TRUE;
		}
	}
	return ERROR;
}
status NextElem(SqList L,ElemType cur,ElemType & next_e) //找到cur元素的后继，并赋值给next_e 
{
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		if(cur==L.elem[i]&&(i+1)!=L.length) 
		{
			next_e=L.elem[i+1];
			return TRUE;
		}
	}
	return ERROR;
}
status ListInsert(SqList & L,int i,ElemType e) //将元素e插入线性表的第i个位置 
{
	ElemType* newbase;
	ElemType*p;
	ElemType*q;
	if(!L.elem) return ERROR;
	if(i<1||i>L.length+1) return ERROR;
	if(L.length>=L.listsize) 
	{
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
} 

status ListDelete(SqList & L,int i,ElemType & e) //删除指定位置的线性表元素并将该元素通过e返回 
{
	ElemType*p;
	ElemType*q;
	if((i<1)||(i>L.length)) return ERROR;
	p=&(L.elem[i-1]);
	e=*p;
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)
	{
		*(p-1)=*p;
	}
	--L.length;
	return OK;
}
status ListTrabverse(SqList L){
   int i;
   printf("\n-----------all elements -----------------------\n");
   for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}  
/*-----------------附加功能-------------------------*/
status WriteFile(SqList& L,char* filename) //将线性表元素写入文件 
{
	FILE  *fp;
	if ((fp=fopen(filename,"w"))==NULL)
	{
		printf("File open erroe\n ");
		return ERROR;
	}
	fwrite(&L.elem,sizeof(ElemType),L.length,fp);
	fclose(fp);
  	return OK;
} 
status ReadFile(SqList& L,char* filename) //将文件中元素读入线性表 
{
	FILE *fp;
	L.length=0;
	if ((fp=fopen(filename,"r"))==NULL)
	{
	 printf("File open erroe\n ");
	 return 1;
	}
	while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
		L.length++;
	
	for(int i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	fclose(fp);
	return 0;
}


int main(void){
  SqList L;
  int op=1;
  int i;
  int e;
  int pre_e;
  int cur_e;
  int next_e;
  char filename[30];
  
  while(op){
	system("cls");
	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty     10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem       12. ListTrabverse\n");
	printf("          13.将现有表中元素写入文件 14.读文件\n");
	printf("    	  0. Exit        \n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~14]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiaList功能待实现！\n");
		 if(IntiaList(L)==OK) printf("线性表创建成功！\n");
		     else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList功能待实现！\n"); 
		 if(DestroyList(L)==OK) printf("线性表销毁成功！\n");
		 else printf("线性表不存在！\n");    
		 getchar();getchar();
		 break;
	   case 3:
		 //printf("\n----ClearList功能待实现！\n");   
		 if(ClearList(L)==OK) printf("线性表元素清除成功！\n");
		 else printf("线性表本来就是空的！\n");  
		 getchar();getchar();
		 break;
	   case 4:
		 //printf("\n----ListEmpty功能待实现！\n");     
		 if(ListEmpty(L)==OK) printf("线性表为空表！\n");
		 else if(ListEmpty(L)==FALSE)  printf("线性表不为空！\n");
		 else if(ListEmpty(L)==ERROR-1) printf("线性表不存在\n"); 
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength功能待实现！\n");     
		 if(ListLength(L)) printf("线性表有%d个元素",*(ListLength(L)));
		 else printf("线性表不存在！");
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem功能待实现！\n"); 
		 printf("请输入你要找的下标索引：");
		 scanf("%d",&i);    
		 if(GetElem(L,i,e)==ERROR) printf("线性表不存在！\n");
		 else if(GetElem(L,i,e)==ERROR-1) printf("线性表不存在这个下标的元素！\n");
		 else printf("第%d个元素为%d",i,e);
		 getchar();getchar();
		 break;
	   case 7:
		 //printf("\n----LocateElem功能待实现！\n");     
		 printf("请输入一个数，将返回线性表中第一个与他相同的位序：");
		 scanf("%d",&e);
		 if(LocateElem(L,e)==0) printf("这样的元素不存在！\n");
		 else printf("该元素的位序是：%d",LocateElem(L,e));
		 getchar();getchar();
		 break;
	   case 8:
		 //printf("\n----PriorElem功能待实现！\n");     
		 printf("请输入数据将返回该数据的前驱：");
		 scanf("%d",&cur_e);
		 if(PriorElem(L,cur_e,pre_e)==ERROR) printf("操作失败，pre_e无定义！\n");
		 else printf("前驱是%d",pre_e);
		 getchar();getchar();
		 break;
	   case 9:
		 //printf("\n----NextElem功能待实现！\n");  
		 printf("请输入数据将返回该数据的后继：");
		 scanf("%d",&cur_e);   
		 if(NextElem(L,cur_e,next_e)==ERROR) printf("next_e无定义！\n");
		 else printf("后继是%d",next_e);
		 getchar();getchar();
		 break;
	   case 10:
		 //printf("\n----ListInsert功能待实现！\n");     
		 printf("请输入插入的位置i:");
		 scanf("%d",&i);
		 printf("请输入将插入的数据：");
		 scanf("%d",&e);
		 if(ListInsert(L,i,e)==ERROR) printf("插入位置错误或线性表不存在\n");
		 else printf("插入成功！\n");
		 getchar();getchar();
		 break;
	   case 11:
		 //printf("\n----ListDelete功能待实现！\n");    
		printf("请输入删除的位置i:");
		 scanf("%d",&i);
		 if(ListDelete(L,i,e)==ERROR) printf("位置错误或线性表不存在\n");
		 else printf("删除位置元素%d",e);
		 getchar();getchar();
		 break;
	   case 12:
		 //printf("\n----ListTrabverse功能待实现！\n");     
		 if(!ListTrabverse(L)) printf("线性表是空表！\n");
		 getchar();getchar();
		 break;
		case 13:
			printf("input file name: ");
			scanf("%s",filename);
			if(WriteFile(L,filename)) printf("文件写入成功！\n");
			else printf("写入失败");
			getchar();getchar();
			break;
		case 14:
			printf("input filename:");
			scanf("%s",&filename);
			ReadFile(L,filename);
			getchar();getchar();
			break;

	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
}//end of main()






