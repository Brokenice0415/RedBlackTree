#include "Node.h"
#include <iostream>

/*
 * constructor
 */
Node::Node(){
	color = red;
	elem = 0;
	num = 0;
	leftSon = NULL;
	rightSon = NULL;
	parent = NULL;
}

/*
 * add an elem
 */
void Node::addElem(int e){
	elem = e;
	num++;
}

/*
 * delete an elem
 */
void Node::delElem(){
	num--;
}

/*
 * set color
 */
void Node::setColor(Color c){
	color = c;
}

/*
 * set the left son
 */
void Node::setLeft(Node* node){
	leftSon = node;
}

/*
 * set the right son
 */
void Node::setRight(Node* node){
	rightSon = node;
}

/*
 * set the parent
 */
void Node::setParent(Node* node){
	parent = node;
}

/*
 * get the color
 */
Color Node::getColor(){
	return color;
}

/*
 * get the elem
 */
int Node::getElem(){
	return elem;
}

/*
 * get the num of elem
 */
int Node::getNum(){
	return num;
}

/*
 * get the left son
 */
Node* Node::getLeft(){
	return leftSon;
}

/*
 * get the right son
 */
Node* Node::getRight(){
	return rightSon;
}

/*
 * get the parent
 */
Node* Node::getParent(){
	return parent;
}
