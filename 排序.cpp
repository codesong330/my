#include<iostream>

#define MAXSIZE 20 //表长最大长度
typedef int KeyType; //定义关键字类型

typedef struct{
	KeyType key;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1]; // r[0]做哨兵单元
	int length; //顺序表长度
}SqList;

//8.2插入排序
//8.2.1 直接插入排序

void InsertSort(SqList &L){
	for(int i = 2; i <= L.length; ++i){
		int j = i -2;
		if(L.r[i].key < L.r[i - 1].key){
			L.r[0] = L.r[i];//将待插入的记录暂存到监视哨点
			L.r[i] = L.r[i - 1];//r[i - 1]后移;
			for( j = i - 2; L.r[0].key < L.r[j].key; --j){
				L.r[j + 1] = L.r[j];//逐一后移，直到找到相应位置
			}
			L.r[j + 1] = L.r[0];//插入
		}
	}
}

//8.2.2 折半排序;
void BInsertSort(SqList &L){
	for(int i = 2; i <= L.length; ++i){
		
		L.r[0] = L.r[i];
		int low,hight;
		low = 1; hight = i - 1;
		while(low <= hight){
			int m = ( low + hight ) / 2;
			if(L.r[0].key < L.r[m].key) hight = m - 1;//定区域
			else low = m + 1;
			//二分查找找到相应位置 hight + 1 and low；
		}
		for(int j = i - 1; j >= hight + 1; --j) L.r[j + 1] = L.r[j];
		L.r[hight +1] = L.r[0];
	}
}

//8.2.3 希尔排序

void ShellInsert(SqList &L, int dk){
	for(int i = dk + 1; i <= L.length; ++i){
		int j;
		if(L.r[i].key < L.r[ i - dk].key){
			L.r[0] = L.r[i];
			for(j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk){
				L.r[ j + dk] = L.r[j];
			}
			L.r[ j + dk] = L.r[0];
		}
	}
}

void ShellSort (SqList &L, int dt[], int t){
	for(int k = 0; k < t; ++k){
		ShellInsert(L,dt[k]);
	}
}



//8.3.2 冒泡排序

void BubbleSort(SqList &L){
	int j;
	int m = L.length - 1;
	int flag = 1;
	while((m > 0) && (flag == 1)){
		flag = 0;
		for( j = 1; j <= m; j ++){
			if(L.r[j].key > L.r[j + 1].key){
				flag = 1;
				RedType t = L.r[j]; L.r[j] = L.r[j + 1]; L.r[ j + 1] = t;
			}
			--m;
		}
	}
}
//8.3.2 快速排序

int partition(SqList &L, int low, int hight){//填坑法划分左右区间
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while(low < hight){
		while( low < hight && L.r[hight].key >= pivotkey) --hight;
		L.r[low] = L.r[hight];
		while(low < hight && L.r[low].key <= pivotkey) ++low;
		L.r[hight] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}
void Qsort(SqList &L, int low, int high){//递归排序
    if(low < high){
        int pivotloc = partition(L, low, high);  // 划分
        Qsort(L, low, pivotloc - 1);             // 排序左边
        Qsort(L, pivotloc + 1, high);            // 排序右边
    }
}

void QuickSork(SqList &L){
	Qsort(L,1,L.length);
}

//---------------------------------------------------------------------












