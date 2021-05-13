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
		return false;    //����λ�ò��Ϸ� 
	if(L.length>=L.Maxsize)
		return false;   //�洢�ռ�����,�޷�����
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1]; 
	L.data[i-1]=e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)   //ɾ��λ�ò��Ϸ� 
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
			return i+1;    //���ҳɹ�,����λ�� 
		}
	}
	return -1;  //����ʧ�� 
}
void print(SqList L){
	cout<<endl<<"�����Ա�ĳ���Ϊ:"<<L.length<<endl;
	cout<<"�����Ա���������󳤶�Ϊ:"<<L.Maxsize;
	cout<<endl<<"��������Ϊ:"<<endl; 
	for(int i=0;i<L.length;i++){
		cout<<"  "<<L.data[i];
	}
}
void MinDelete(SqList &L,int &e){   //ɾ�����Ա��е���СֵԪ��,�������һ��Ԫ������ȱλ�� 
	if(L.length==0)
		cout<<"���Ա�Ϊ��!"<<endl;
	int min=0;
	for(int i=1;i<L.length;i++){
		if(L.data[min]>L.data[i])
			min=i;
	}
	e=L.data[min];
	L.data[min]=L.data[L.length-1];
}
void Reverse(SqList &L){    //�������Ա� 
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
