# README

很久前写的

只实现了简单的增删改查

### Linux下编译运行

```shell
> g++ -o demo demo.cpp Tree.cpp Node.cpp 
```

### Tree红黑树主体

主要实现如下函数

```c++
private:
	/*左旋*/
	void leftTurn(Node* node);
	/*右旋*/
    void rightTurn(Node* node);
	/*插入时的自平衡*/
    void insertBalance(Node* node);
	/*删除时的自平衡*/
    void deleteBalance(Node* par, bool left);
	/*删除时的删除结点操作*/
    void deleteFunction(Node* node);
public:
	/*插入结点接口*/
    void insertElem(int e, Node* node);
	/*查找结点接口*/
    bool findElem(int e, Node* node);
	/*删除结点接口*/
    bool deleteElem(int e, Node* node); 
```

### demo

用于测试的main函数

实现依次插入值0~118的结点

然后依次删除值5, 61, 61, 47, 29, 111, 34, 31

**正常编译运行结果**

```shell
> ./demo
Delete 5 Successfully !
Delete 61 Successfully !
ERROR: Delete 61
Delete 47 Successfully !
Delete 29 Successfully !
Delete 111 Successfully !
Delete 34 Successfully !
```



