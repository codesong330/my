#include<iostream>

//7.2.1 线性表的查找

typedef int KeyType;

typedef struct{
	KeyType key;
}ElemType;

typedef struct{
	ElemType *R;
	int length;
}SSTable;

//7.1 顺序查找

int Search_Seq(SSTable ST , KeyType key){
	
	for(int i = ST.length; i >= 1; --i){
		if(ST.R[i].key == key) return i;
	}
	return 0;
}

//7.2 监视哨的顺序查找

int Search_Sed(SSTable ST, KeyType key){
	
	ST.R[0].key = key;
	for(int i = ST.length; ST.R[i].key != key; --i)
	return i;
}

//7.2.2 二分查找

int Search_Bin(SSTable ST,KeyType key){
	int low,high;
	low = 1;
	high = ST.length;
	while( low <= high){
		
		int mid = (low + high) / 2;
		if(key == ST.R[mid].key) return mid;
		else if(key < ST.R[mid].key) high = mid + 1;
		else low = mid + 1;
	}
	return 0;
}

//7.1 二叉排序树

typedef struct BSTNode{
	ElemType data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T,KeyType key){
	if((!T) || key == T -> data.key) return T;
	else if(key < T -> data.key) return SearchBST(T -> lchild,key);
	else return SearchBST(T -> rchild,key);
}




