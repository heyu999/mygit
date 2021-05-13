#include<iostream>
using namespace std;
#define InitSize 50
typedef struct{
	int *data;
	int length,Maxsize;
}SqList; 
bool ListInit(SqList &L){
	L.Maxsize=InitSize;
	L.length=0;
	L.data=new int[InitSize];
}
bool ListInsert(SqList &L,int i, int e){
	if(i<1||i>L.length+1)
		return false;    //插入位置不合法 
	if(L.length>=L.Maxsize)
		return false;   //存储空间已满,无法插入
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1]; 
	L.data[i-1]=e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)   //删除位置不合法 
		return false;
	e=L.data[i-1];
	for(int j=i-1;j<L.length;j++){    
		L.data[j]=L.data[j+1];
	}
	L.length--;
	return true;
}
int LocateElem(SqList L,int &i,int e){
	for(int j=0;j<L.length;j++){
		if(L.data[j]==e){
			return i+1;    //查找成功,返回位置 
		}
	}
	return -1;  //查找失败 
}
void print(SqList L){
	cout<<endl<<"该线性表的长度为:"<<L.length<<endl;
	cout<<"该线性表的允许的最大长度为:"<<L.Maxsize;
	cout<<endl<<"其中数据为:"<<endl; 
	for(int i=0;i<L.length;i++){
		cout<<"  "<<L.data[i];
	}
}
void MinDelete(SqList &L,int &e){   //删除线性表中的最小值元素,并用最后一个元素填充空缺位置 
	if(L.length==0)
		cout<<"线性表为空!"<<endl;
	int min=0;
	for(int i=1;i<L.length;i++){
		if(L.data[min]>L.data[i])
			min=i;
	}
	e=L.data[min];
	L.data[min]=L.data[L.length-1];
}
void Reverse(SqList &L){    //逆置线性表 
	for(int i=0;i<L.length/2;i++){
		int t=L.data[i];
		L.data[i]=L.data[L.length-i-1];
		L.data[L.length-i-1]=t;
	} 
}
void Process(SqList &L,int x){
	for(int i=0;i<L.length;){
		if(L.data[i]==x){
			for(int j=i;j<L.length;j++){
				L.data[j]=L.data[j+1];
			}
			L.length--;
		}
		else i++;
	}
} 
int main(){
	SqList L;
	int e;
	ListInit(L);
	ListInsert(L,1,9);
	ListInsert(L,2,8);
	ListInsert(L,3,7);
	ListInsert(L,4,6);
	print(L);
	//Reverse(L);
	//MinDelete(L,e);
	Process(L,5);
	print(L);
	return 0;
} 
