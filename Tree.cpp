#include "Tree.h"
#include <iostream> 

/*
 * constructor
 */
Tree::Tree(){
	root = NULL;
}

/*
 * the right rotation function
 */
void Tree::rightTurn(Node* node){	
	Node* lef = node->getLeft();
	
	node->setLeft(lef->getRight());
	if(node->getLeft() != NULL){
		node->getLeft()->setParent(node);
	}
	
	lef->setParent(node->getParent());
	if(node->getParent() != NULL){
		if(node == node->getParent()->getLeft()){
			node->getParent()->setLeft(lef);
		}
		else{
			node->getParent()->setRight(lef);
		}
	}
	else{
		root = lef;
	}
	
	node->setParent(lef);
	lef->setRight(node);
} 

/*
 * the left rotation function
 */
void Tree::leftTurn(Node* node){
	Node* rig = node->getRight();
	
	node->setRight(rig->getLeft());
	if(node->getRight() != NULL){
		node->getRight()->setParent(node);
	}
	
	rig->setParent(node->getParent());
	if(node->getParent() != NULL){
		if(node == node->getParent()->getLeft()){
			node->getParent()->setLeft(rig);
		}
		else{
			node->getParent()->setRight(rig);
		}
	}
	else{
		root = rig;
	}
	
	node->setParent(rig);
	rig->setLeft(node);
	
} 

/*
 * the balance function of insert
 */
void Tree::insertBalance(Node* node){
	/*
	 * is root
	 */
	if(node->getParent() == NULL){
		node->setColor(black);
		root = node;
		return;
	}
	/*
	 * parent is black -> needn't balance
	 */
	if(node->getParent()->getColor() == black){
		return;
	} 
	/*
	 * parent is red -> grand must be black ann exist
	 * 
	 ******************************************parent is grand's left son
	 */
	if(node->getParent() == node->getParent()->getParent()->getLeft()){
		Node* uncle = node->getParent()->getParent()->getRight();
		/*
		 * judge whether uncle is black or not exist
		 */
		bool blackUncle = false;
		if(uncle == NULL){
			blackUncle = true;
		}
		else if(uncle->getColor() == black){
			blackUncle = true;
		}
		/*
		 *----------------------------uncle is red
		 */
		if(blackUncle == false){
			node->getParent()->setColor(black);
			uncle->setColor(black);
			node->getParent()->getParent()->setColor(red);
			//consider node's parent as curr node to another balance
			insertBalance(node->getParent()->getParent());
		}
		else{//-----------------------uncle is black or not exist
			/*
			 * is parent's left son
			 */
			if(node == node->getParent()->getLeft()){
				//change color 
				node->getParent()->setColor(black);
				node->getParent()->getParent()->setColor(red);
				//rotation
				rightTurn(node->getParent()->getParent());
			}
			else{//parent's right son
				//rotation
				leftTurn(node->getParent());
				//consider node's parent as curr node to another balance
				insertBalance(node->getLeft());
			}
		}
	}
	else{//**************************************parent is grand's right son
		Node* uncle = node->getParent()->getParent()->getLeft();
		/*
		 * judge whether uncle is black or not exist
		 */
		bool blackUncle = false;
		if(uncle == NULL){
			blackUncle = true;
		}
		else if(uncle->getColor() == black){
			blackUncle = true;
		}
		/*
		 *--------------------------uncle is red
		 */
		if(blackUncle == false){
			node->getParent()->setColor(black);
			uncle->setColor(black);
			node->getParent()->getParent()->setColor(red);
			//consider node's parent as curr node to another balance
			insertBalance(node->getParent()->getParent());
		}
		else{//---------------------uncle is black or not exist
			/*
			 * is parent's right son
			 */
			if(node == node->getParent()->getRight()){
				//change color 
				node->getParent()->setColor(black);
				node->getParent()->getParent()->setColor(red);
				//rotation
				leftTurn(node->getParent()->getParent());
			}
			else{//parent's left son
				//rotation
				rightTurn(node->getParent());
				//consider node's parent as curr node to another balance
				insertBalance(node->getRight());
			}
		}
	}
}

/*
 * the balance function of delete
 */
void Tree::deleteBalance(Node* par, bool left){
	/*
	 * node is parent's left son
	 */
	if(left){
		Node* bro = par->getRight();
		if(bro->getColor() == red){
			/*
			 * bro is red -> par must be black
			 */
			par->setColor(red);
			bro->setColor(black);
			
			leftTurn(par);
			//another balance
			deleteBalance(par, true);
		}
		else{// bro is black
			/*
			 * bro's right son is red
			 */
			if(bro->getRight() != NULL){
				if(bro->getRight()->getColor() == red){
					bro->setColor(par->getColor());
					par->setColor(black);
					bro->getRight()->setColor(black);
					//rotation
					leftTurn(par);
					
					return;
				}
				/*
				 * bro's right son is black and bro's left son is red
				 */
				if(bro->getLeft() != NULL){
					if(bro->getLeft()->getColor() == red){
						bro->setColor(red);
						bro->getLeft()->setColor(black);
						//rotation
						rightTurn(bro);
						//another balance
						deleteBalance(par, true);
						
						return;
					}
				}
			}
			/*
			 * bro's left son is red and bro's left son is black
			 */
			if(par->getRight() != NULL){
				if(par->getRight()->getColor() == red){
					leftTurn(par);
				}
				return;
			}
			/*
			 * both bro are black or NULL
			 */
			bro->setColor(red);
			if(par->getParent() != NULL){
				if(par = par->getParent()->getLeft()){
					deleteBalance(par->getParent(), true);
				}
				else{
					deleteBalance(par->getParent(), false);
				}
			}
			else{
				root = par;
				par->setColor(black);
			}
		}
	}
	else{//node is par's right son
		Node* bro = par->getLeft();
		if(bro->getColor() == red){
			/*
			 * bro is red -> par must be black
			 */
			par->setColor(red);
			bro->setColor(black);
			
			rightTurn(par);
			//another balance
			deleteBalance(par, false);
		}
		else{// bro is black
			/*
			 * bro's left son is red
			 */
			if(bro->getLeft() != NULL){
				if(bro->getLeft()->getColor() == red){
					bro->setColor(par->getColor());
					par->setColor(black);
					bro->getLeft()->setColor(black);
					//rotation
					rightTurn(par);
					
					return;
				}
				/*
				 * bro's left son is black and bro's right son is red
				 */
				if(bro->getRight() != NULL){
					if(bro->getRight()->getColor() == red){
						bro->setColor(red);
						bro->getRight()->setColor(black);
						//rotation
						leftTurn(bro);
						//another balance
						deleteBalance(par, false);
						
						return;
					}
				}
			}
			/*
			 * bro's left son is red and bro's left son is black
			 */
			if(par->getRight() != NULL){
				if(par->getRight()->getColor() == red){
					rightTurn(par);
				}
				return;
			}
			/*
			 * both bro are black or NULL
			 */
			bro->setColor(red);
			if(par->getParent() != NULL){
				if(par = par->getParent()->getLeft()){
					deleteBalance(par->getParent(), true);
				}
				else{
					deleteBalance(par->getParent(), false);
				}
			}
			else{
				root = par;
				par->setColor(black);
			}
		}
	}
	
}

/*
 * the delete function
 */
void Tree::deleteFunction(Node* node){
	/*
	 *************************************************** both sons are NULL
	 *
	 * just delete node
	 */ 
	if(node->getLeft() == NULL && node->getRight() == NULL){
		/*
		 * node is root
		 */
		if(node->getParent() == NULL){
			root = NULL;
		}
		else{// node is not root
			Node* par = node->getParent();
			
			node->setParent(NULL);
			
			if(node == par->getLeft()){
				par->setLeft(NULL);
				//--------------------------Balance
				/*
				 * if node is red -> needn't balance
				 */
				if(node->getColor() == black){
					deleteBalance(par, true);
				}
			}
			else{
				par->setRight(NULL);
				//--------------------------Balance
				/*
				 * if node is red -> needn't balance
				 */
				if(node->getColor() == black){
					deleteBalance(par, false);
				}
			}
		}
		
		delete node;
	} 
	else if(node->getLeft() == NULL){// ***************** has one son which is right
		/*
		 * node can only be black and son can only be red
		 * only to replace node and color the son black
		 */ 
		
		/*
		 * node is root
		 */
		if(node->getParent() == NULL){
			node->getRight()->setParent(NULL);
			root = node->getRight();
		}
		else{// node is not root
			if(node == node->getParent()->getLeft()){
				node->getParent()->setLeft(node->getRight());
			}
			else{
				node->getParent()->setRight(node->getRight());
			}
			node->getRight()->setParent(node->getParent());
		}
		
		//color son black
		node->getRight()->setColor(black);
		
		delete node;
	}
	else if(node->getRight() == NULL){// **************** has one son which is left -> replace node with the son
		/*
		 * node is root
		 */
		if(node->getParent() == NULL){
			node->getLeft()->setParent(NULL);
			root = node->getLeft();
		}
		else{// node is not root
			if(node == node->getParent()->getLeft()){
				node->getParent()->setLeft(node->getLeft());
			}
			else{
				node->getParent()->setRight(node->getLeft());
			}
			node->getLeft()->setParent(node->getParent());
		}
		
		//color son black
		node->getLeft()->setColor(black);
		
		delete node;
	}
	else{// ********************************************** has both sons -> swap node with the first suffix node 
		Node* suffix = node->getRight();
		while(suffix->getLeft() != NULL){
			suffix = suffix->getLeft();
		}
		
		/*
		 * renew the root
		 */
		if(root == node){
			root = suffix;
		}
		
		Node* par = node->getParent();
		Node* rig = suffix->getRight();
		
		/*
		 * node is not root
		 *
		 * link node's parent with suffix
		 */
		if(par != NULL){
			//node is parent's left son
			if(node == par->getLeft()){
				par->setLeft(suffix);
			}
			else{
				par->setRight(suffix);
			}
		}
		else{//is root
			root = suffix;
		}
		
		/*
		 * link node with suffix's parent
		 */
		if(rig != suffix){
			suffix->getParent()->setLeft(node);
			node->setParent(suffix->getParent());
		}
		else{
			node->setParent(suffix);
			suffix->setRight(node);
		}
		//link suffix with node's parent
		suffix->setParent(par);
		
		
		/*
		 * link 2 sons
		 */
		if(rig != suffix){
			node->getRight()->setParent(suffix);
			suffix->setRight(node->getRight());
			node->setRight(rig);
			if(rig != NULL){
				rig->setParent(node);
			}
		}
		node->getLeft()->setParent(suffix);
		suffix->setLeft(node->getLeft());
		node->setLeft(NULL);
		
		/*
		 * swap color of node and suffix
		 */
		Color nodeColor = node->getColor();
		node->setColor(suffix->getColor());
		suffix->setColor(nodeColor);
		
		/*
		 * delete the replaced node
		 */ 
		 deleteFunction(node);
	}
	
}

/*
 * set the root node
 */
void Tree::setRoot(Node* node){
	root = node;
}

/*
 * insert an elem
 */
void Tree::insertElem(int e, Node* node){
	/*
	 * root node is NULL
	 */
	if(node == NULL){
		node = new Node;
		node->addElem(e);
		root = node;
		
		//balance
		insertBalance(node);
		
		return;
	}
	int tmp = node->getElem();
	if(e < tmp){
		/*
		 * left son is NULL
		 */
		if(node->getLeft() == NULL){
			Node* n = new Node;
			n->addElem(e);
			n->setParent(node);
			node->setLeft(n);
			
			//balance
			insertBalance(n);
			
			return;
		}
		
		insertElem(e, node->getLeft());
		
	}
	else if(e > tmp){
		/*
		 * right son is NULL
		 */
		if(node->getRight() == NULL){
			Node* n = new Node;
			n->addElem(e);
			n->setParent(node);
			node->setRight(n);
			
			//balance
			insertBalance(n);
			
			return;
		}
		
		insertElem(e, node->getRight());
	}
	else{
		node->addElem(e);
	}
}

/*
 * search an elem
 */
bool Tree::findElem(int e, Node* node){
	if(node == NULL){
		return false;
	}
	int tmp = node->getElem();
	if(e < tmp){
		std::cout<<"left"<<std::endl;
		return findElem(e, node->getLeft());
	}
	else if(e > tmp){
		std::cout<<"right"<<std::endl;
		return findElem(e, node->getRight());
	}
	else return true;
}

/*
 * delete an elem
 */
bool Tree::deleteElem(int e, Node* node){
	if(node == NULL){
		return false;
	}
	int tmp = node->getElem();
	if(e < tmp){
		return deleteElem(e, node->getLeft());
	}
	else if(e > tmp){
		return deleteElem(e, node->getRight());
	}
	else{
		if(node->getNum() > 1){
			node->delElem();
		}
		else{
			deleteFunction(node);
		}
		return true;
	}
}

/*
 * get the root node
 */
Node* Tree::getRoot(){
	return root;
}
