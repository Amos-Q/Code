#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<math.h>
#include<list>
using namespace std;
 
int function(int n, int a[], int len){
	int m;
	int n2=n;
	for(int i=0;i<len;i++){//找到该数的所有平方根组合，不保证平方和是原来的数 
		m = sqrt(n);
		a[i]=m*m;   //存储平方根m， m*m是平方 
		if(m*m==n)
			break;
		else if(m!=1){
			n=n-m*m;
		}else 
			break;
	}
	// 这部分把得到的平方和与元素比对是否相等 
	int sum=0; //变量一定要初始化 否则会出错 
	for(int i=0;i<len;i++){
		if(a[i]!='\0'){
			sum=sum+a[i];
		}
	}
	if(sum==n2) //相等输出平方组合 
		for(int i=len-1;i>=0;i--)
		{
			if(a[i]!='\0')
			{
				cout<<a[i]<<+" ";
			}	
		}
	else //不相等输出NA 
		cout<<"NA";
} 
 
int main(){
	int n;
	cin>>n;
	int len = sqrt(n);
	int ar[len];
	for(int i=0;i<len;i++){ //数组初始化为0  
		ar[i]=0;
	}
	function(n,ar,len);	//调用函数 
	return 0;
} 