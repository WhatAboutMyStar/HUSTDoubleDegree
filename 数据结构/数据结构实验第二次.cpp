#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef int status;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

status InitaList(LinkList &L) //初始化单链表 
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
	{
		return ERROR;	
	}	
	L->next=NULL;
	return TRUE;
}

status DestroyList(LinkList&L) //销毁单链表 
{
	LinkList p;
	p=L;
	if(!L) return ERROR;
	while(L)
	{
		p=L->next;
		free(L);
		L=p;		
	} 
	return OK;
}

status ClearList (LinkList&L) //清空单链表 
{
	LinkList p,q;
	if(!L) return ERROR;
	p=L->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return OK;
}
status ListEmpty(LinkList L) //判断链表是否为空 
{
	if(!L) return ERROR;
	if(L->next==NULL) return OK;
	else return ERROR;
}

status ListLength(LinkList L)	//返回链表长度 
{
	int count=0;
	if(!L) return ERROR;
	while(L->next)
	{
		count++;
		L=L->next;
	}
	return count;
}

status GetElem(LinkList L,ElemType i,ElemType &e) //获取i位置的元素 
{
	if(!L) return ERROR;
	int c=1;
	LinkList p;
	p=L->next;
	while(c<i&&p)
	{
		p=p->next;
		c++;
	} 
	if(c<i) return ERROR;
	e=p->data;
	return OK;
}

status LocateElem(LinkList L,ElemType e) //查找元素的位置 
{
	if(!L) return ERROR;
	LinkList p;
	p=L;
	int count=0;
	while(p->next)
	{
		p=p->next;
		count++;
		if(p->data==e) return count; 
	}
	return ERROR;
}

status PriorElem(LinkList L,ElemType cur_e,ElemType& pre_e) //查找元素的前驱 
{
	if(!L) return ERROR;
	LinkList p,q;
	p=L->next;
	q=L;
	while(p->next)
	{
		if((p->data==cur_e)&&q!=L) 
		{
			pre_e=q->data;
			return OK;
		}
		p=p->next;
		q=q->next;
	}
	if(p->data==cur_e) 
	{
		pre_e=q->data;
		return OK;
	}
	return ERROR;
}

status NextElem(LinkList L,ElemType cur_e,ElemType& next_e) //查找元素的后继 
{
	if(!L) return ERROR;
	LinkList p;
	p=L;
	while(p->next)
	{
		p=p->next;
		if(p->data==cur_e)
		{
			if(p->next)
			{
				next_e=p->next->data;
				return OK;
			}
			else return ERROR;
		}
	}
	return ERROR;
}

status ListInsert(LinkList &L,ElemType i,ElemType e) //在指定位置插入元素 
{
	if(!L) return ERROR;
	LinkList p,s;
	p=L;
	int c=0;
	while(p&&c<i-1)
	{
		p=p->next;
		c++;	
	} 
	if(!p||c>i-1) return ERROR;
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

status ListDelete(LinkList &L,ElemType i,ElemType& e) //删除单链表的指定位置元素 
{
	if(!L) return ERROR;
	LinkList p,q;
	p=L;
	int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;++j;
	}
	if(!(p->next)||j>i-1) return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
	
}
status ListTraverse(LinkList L) //遍历单链表 
{
	if(!L)
	{
		printf("单链表不存在。");
		return ERROR;
	}
	LinkList p;
	p=L;
	printf("\n-----------all elements -----------------------\n");
	while(p->next)
	{
		p=p->next;
		printf("%d ",p->data);
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}


int main()
{
	LinkList L=NULL;
	int op=1; 
	int i,e;
	ElemType cur_e,pre_e,next_e; 
	while(op){
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On LinkList Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty     10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem       12. ListTrabverse\n");
		printf("    	  0. Exit        \n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~12]:");
		scanf("%d",&op);
   		switch(op){
		   	case 1:
			 	if(InitaList(L)==OK) printf("单链表创建成功！\n");
		     	else printf("单链表创建失败！\n");
			 	getchar();getchar();
		 		break;
			case 2:
				if(DestroyList(L)==OK) printf("单链表销毁成功！\n");
		     	else printf("本来就不存在单链表！\n");
			 	getchar();getchar();
				break;
			case 3:
				if(ClearList(L)==OK) printf("单链表清空成功！\n");
		     	else printf("不存在单链表！\n");
			 	getchar();getchar();
				break;
			case 4:
				if(ListEmpty(L)==OK) printf("单链表是空的！\n");
		     	else printf("单链表不是空的或不存在！\n");
			 	getchar();getchar();
				break;
			case 5:
				if(ListLength(L)) printf("单链表长度为%d\n",ListLength(L));
		     	else printf("单链表不存在或长度为0！\n");
			 	getchar();getchar();
				break;
			case 6:
				printf("请输入要查找的元素位置：");
				scanf("%d",&i);
				if(GetElem(L,i,e)==OK) printf("第%d个元素是%d\n",i,e);
		     	else printf("单链表不存在或者没有这个位置！\n");
			 	getchar();getchar();
				break;
			case 7:
				printf("请输入你想查找的元素值：");
				scanf("%d",&e);
				if(LocateElem(L,e)) printf("元素%d的位置是%d\n",e,LocateElem(L,e));
		     	else printf("单链表不存在或不存在这个元素！\n");
			 	getchar();getchar();
				break;
			case 8:
				printf("请输入元素将返回它前一个元素：");
				scanf("%d",&cur_e);
				if(PriorElem(L,cur_e,pre_e)==OK) printf("元素%d的前一个元素是%d\n",cur_e,pre_e);
		     	else printf("单链表不存在或不存在前一个元素！\n");
			 	getchar();getchar();
				break;
			case 9:
				printf("请输入一个元素值，将返回下一个元素：");
				scanf("%d",&cur_e);
				if(NextElem(L,cur_e,next_e)==OK) printf("元素%d的后一个元素是%d\n",cur_e,next_e);
		     	else printf("单链表不存在或元素不存在！\n");
			 	getchar();getchar();
				break;
			case 10:
				printf("请输入插入元素的位置:");
				scanf("%d",&i);
				printf("请输入插入元素的值：");
				scanf("%d",&e);
				if(ListInsert(L,i,e)==OK) printf("元素插入成功！\n");
		     	else printf("失败！\n");
			 	getchar();getchar();
				break;
			case 11:
				printf("请输入删除元素的位置:");
				scanf("%d",&i);
				if(ListDelete(L,i,e)==OK) printf("元素删除成功！删除元素为%d\n",e);
		     	else printf("失败！\n");
			 	getchar();getchar();
				break;
			case 12:
				ListTraverse(L);
			 	getchar();getchar();
				break;
	   		case 0:
         		break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
	return 0;
}

