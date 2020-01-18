/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//AddPolyn.cpp
//Add Polynomial Pa and Pb 
#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
struct Term
{
	float coef; // 系数
	int expn; // 指数
	struct Term *next; // 指向下一个结点
}*LinkList;										  //typedef LinkList with polynomial
                                                 
void CreateList_L(struct Term * &L,int n)
{                                                 //To Creatre a LinkList L with HeadNode 
  int i;
  struct Term *p;
  L=(struct Term *)malloc(sizeof(Term)); // 创建头结点
  L->next=NULL;
  for(i=n;i>0;--i) // 分配n个结点，并链接起来
  {
	  p=(struct Term *)malloc(sizeof(Term));
	  cout<<"coef = ";
	  cin>>p->coef;                               //Reverse order inputing for Creating a LinkList
	  cout<<"expn = ";
	  cin>>p->expn; 
	  p->next=L->next;
	  L->next=p;
  }//end of for                                              
  if(n) cout<<"Success to Create a LinkList !"<<endl;
  else cout<<"A NULL LinkList have been created !"<<endl;
} //end of function CreateList
                                              
char cmp(int qa_expn,int qb_expn)               //cmp() function            
{//compare qa->expn and qb->expn
	if(qa_expn==qb_expn) // 指数相等
		return '=';
	else // 指数不相等
		if(qa_expn>qb_expn) return '>';
			else return '<';
}//end of cmp() function

/* 多项式加法 */
void AddPolyn(struct Term * &Pa,struct Term * &Pb) //AddPolyn() function
{  //Add the polynomial Pa and Pb                                                
   struct Term *qa,*qb,*pre,*u;  
   float sum;
   qa=Pa->next;                                 //qa point to current node of Pa 
   qb=Pb->next;                                 //qb point to current node of Pb 
   pre=Pa;                                      //pre point to the HeadNode of Pa
   
   while(qa&&qb)                                //neither qa nor qb are NULL
   {
	   switch(cmp(qa->expn,qb->expn))
	   { 
		  case '<':
			  /*****************************
			   如果qa小于qb，取Pa下一个结点
			  *****************************/
			  pre=qa;qa=qa->next;
			  break;
			  /**************************************
			   如果qa等于qb，则系数相加：
			   1、相加不为零，修改qa系数
			   2、相加为零，链接Pa下一结点，删除qa
			   最后，调整pre，链接Pb下一结点，删除qb
			  **************************************/
		  case '=':                             //when the expn of qa == the expn of qb 
			  sum=qa->coef+qb->coef;
			  if(sum!=0.0)               
			  { 
				  qa->coef=sum;pre=qa;          //modify the current Node coef values of Pa
			  }                               //end of if
			  else
			  { 
				  pre->next=qa->next;           //otherwise qa->expn=qb->expn then delete current Node in Pa
			      free(qa);
			  }                               //end of else
			  qa=pre->next;u=qb;qb=qb->next;
			  free(u);
			  break;
		  case '>':
			  /*****************************
			   如果qa大于qb，把qb插入qa之前
			  *****************************/
              u=qb->next;
			  qb->next=qa;
			  pre->next=qb;
			  pre=qb;
			  qb=u;
			  break;
	   }                                       //end of switch
   }
   /* Pa已经没有多余项，把Pb剩余项链入Pa */
   if(!qa) pre->next=qb;                        //to link the rest of node of Pb
   free(Pb); // 释放Pb
   cout<<endl;
}//end of AddPolyn() function
         
int main()                                                 //main() function
{  
   struct Term *Pa,*Pb,*p;	    
   int InitLNodeNum_Pa,InitLNodeNum_Pb;                     //the Init LinkNode Numbers

   cout<<"AddPolyn.cpp"<<endl<<"============="<<endl;  
   cout<<endl<<"How many sessions of polynomial Pa do you want ? (eg. 4): "; // Pa不超过四项
   cin>>InitLNodeNum_Pa;  
   cout<<"Please input the Pa.coef and Pa.expn in descent order:"<<endl;
   cout<<"For example: (coef=3,expn=21);(coef=7,expn=9);(coef=4,expn=1);(coef=5,expn=0)"<<endl;
   /* 参数：头指针、项数 */
   CreateList_L(Pa,InitLNodeNum_Pa);                       //to create polynomial Pa LinkList with 
                                                           //the InitLNodeNum_Pa=input number +1  
   cout<<endl<<"How many sessions of polynomial Pb do you want ? (eg. 3): "; // Pb不超过三项
   cin>>InitLNodeNum_Pb;                                   
   cout<<"Please input the Pb.coef and Pb.expn in descent order:"<<endl;
   cout<<"For example: (coef=-7,expn=9);(coef=13,expn=6);(coef=8,expn=1)"<<endl;
   CreateList_L(Pb,InitLNodeNum_Pb);                       //to create polynomial Pb LinkList with
                                                           //the InitLNodeNum_Pb=input number +1  
   AddPolyn(Pa,Pb);                                        //AddPolyn Pa and Pb
   p=Pa;
   cout<<"Result:"<<endl;
   /* 打印多项式 */
   while(p->next)                                         //output Pa=Pa+Pb
   {
	  p=p->next;
      cout<<"(Pc.coef="<<p->coef<<",";
      cout<<"Pc.expn="<<p->expn<<")"<<endl;		  
   }// end of while
   cout<<endl<<"OK...!"<<endl;
   getch();
}//end of main() function
