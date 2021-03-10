#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree{
	private:
		Node* root;
		void leftTurn(Node* node);
		void rightTurn(Node* node);
		void insertBalance(Node* node);
		void deleteBalance(Node* par, bool left);
		void deleteFunction(Node* node);
	public:
		Tree();
		void setRoot(Node* node);
		void insertElem(int e, Node* node);
		bool findElem(int e, Node* node);
		bool deleteElem(int e, Node* node); 
		Node* getRoot();
};

#endif
