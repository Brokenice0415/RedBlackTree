#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
	Tree t;
	for(int i = 1; i < 119; i++){
		t.insertElem(i, t.getRoot());
	}
	
	int a[10] = {
		5, 61, 61, 47, 29, 111, 34, 31
	};
	
	for(int i = 0; i < 7; i++){
		if(t.deleteElem(a[i], t.getRoot())){
			cout<<"Delete "<<a[i]<<" Successfully !"<<endl;
		}
		else{
			cout<<"ERROR: Delete "<<a[i]<<endl;
		}
	}
	
	
	return 0;
}