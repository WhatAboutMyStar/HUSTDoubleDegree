/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Replace.cpp

#include <stdio.h>
#include <conio.h>
#include <iostream.h>

#define MAXSTRLEN 255

typedef unsigned char SString[MAXSTRLEN+1];         //from 0 to 256 becoz '\0'

/* 串B从位置y开始，长度为len的子串，拷贝到串A的x位置 */
void Copy(SString &A,SString B,int x,int y,int len) //Copy() function
{   //copy to SString A in x position from y position in SString B, in all be len character
	int i,j,k;
	for(i=x,j=y,k=1;k<=len;i++,j++,k++)
		A[i]=B[j];
}//end of Copy() function

/* 用串V替换串S的子串T，结果保存于D */
int Replace(SString &D,SString S,SString T,SString V)
{   //Replace the SubSString T with V where T
	int m,n,p,i,j,k,q,overflow;
	for(m=0;S[m]!='\0';m++); // 串S的长度
	for(n=0;T[n]!='\0';n++); // 串T的长度
	for(p=0;V[p]!='\0';p++); // 串V的长度
	overflow=0;                                              //Set overflow flag
	i=0;
	k=0;
	q=0; 
    while(!overflow&&m-k>=n)           //have been modified      
	{
		j=0;
		/* 匹配所有T */
		while((j<n) && (S[k+j]==T[j]))//modified
			j++;
		if(j<n)                       //modified
			k++;
		//------------------------------------------
		else // j>=n，说明匹配一个T成功
			if(q+k-i+p>MAXSTRLEN) // 长度超过限制              
				return (0);          //failure to match SString
	        else
			{ 
			    Copy(D,S,q,i,k-i); // 串S从位置i开始，长度为k-i的子串，拷贝到串D的q位置
		        q=q+k-i;                  //modify
		        Copy(D,V,q,0,p);   // 串V从位置0开始，长度为p的子串，拷贝到串D的q位置
			    i=k+n; // 跳过一个V，i为S的当前偏移
			    q=q+p; // 修改D的此次偏移
			    k=i; // 修改S的此次偏移				     
			}//end of if
	}//end of while 
	if((!overflow)&&(i<=m)&&((q+m-i+1)<=MAXSTRLEN))
		/* 拷贝剩余的串S */
		Copy(D,S,q,i,m-i+1); // 串S从位置i开始，长度为m-i+1的子串，拷贝到串D的q位置
	else 
		overflow=1; // 操作失败
	return(!overflow);
}//end of Replace() function
   
void main()                                            //main() function
{
    SString D,S,T,V;
    cout<<"Replace.cpp"<<endl<<"============"<<endl<<endl;
    cout<<"Please input the previous SString S: <eg. abcb ccbcbad> ";
    cin.getline(S,MAXSTRLEN);
    cout<<"Find the key SString T : <eg. bc> ";
    cin.getline(T,MAXSTRLEN);
    cout<<"Replaced by the SString V: <eg. @> ";
    cin.getline(V,MAXSTRLEN);

    if(Replace(D,S,T,V))                                //call Replace function
	{ 
		printf("The new SString D= %s",D);               //Output the new SString D
        cout<<endl<<"...OK!..."<<endl;
	}
    else 
		cout<<"Failure to Replace the SString!"<<endl;
    getch();
}//end of main() function
