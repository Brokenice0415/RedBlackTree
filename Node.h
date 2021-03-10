#ifndef NODE_H
#define NODE_H

#define red false
#define black true

typedef bool Color;

class Node{
	private:
		Color color;
		int elem;
		int num;
		Node* leftSon;
		Node* rightSon;
		Node* parent;
	public:
		Node();
		void addElem(int e);
		void delElem();
		void setColor(Color c);
		void setLeft(Node* node);
		void setRight(Node* node);
		void setParent(Node* node);
		Color getColor();
		int getElem();
		int getNum();
		Node* getLeft();
		Node* getRight();
		Node* getParent();
};

#endif
