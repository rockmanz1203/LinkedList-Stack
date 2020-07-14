#include <iostream>
using namespace std;

class LinkedListStack {

	//Stack中的節點結構，資料內容是存int
	struct Node
	{
		int data;
		Node * next;
	};

public:

	//constructor 
	LinkedListStack()
	{
		top = nullptr;
		size = 0;
	}

	//deconstructor釋放記憶體 依序刪掉每個node  delete只能透過pointer去對記憶體空間刪除?
	~LinkedListStack()
	{
		Node * tempNode = nullptr;
		while (top)
		{
			tempNode = top;//記錄起原本top的node

			delete top;//刪掉stack當前最上層的node 同時top也會因此變成指向一個空的記憶體空間
			top = tempNode->next;//更改top指向的位置，讓他去指原本top的next node
		}

		delete tempNode;//全部刪光以後 刪掉temp的node
	}

	//加入資料到stack
	void push(int value)
	{
		Node * n = new Node;//新增一個存資料的stack節點

		n->data = value;//為該stack節點附加儲存資料
		n->next = top;//將該stack節點與現有的stack節點群的頭連接

		top = n;//成為新的stack節點頭

		size++;
	}

	int pop()
	{
		if (top != nullptr)//如果stack中有東西
		{
			int value = top->data;//取值
			Node * tempNode = top;

			//delete top;//不能這樣用，這樣這邊刪了一次，後面又刪了同一個記憶體位置中的內容，可能會有問題

			top = tempNode->next;//讓top指標指到原本top節點的下一個stack節點

			delete tempNode;//消滅暫存的節點

			return value;//回傳要pop的結果
		}
		else//如果stack已經沒東西了
		{
			cout << "Empty stack" << endl;
			return 0;
		}
	}

	bool isEmpty()
	{
		return size == 0;
	}

private:

	Node * top;
	int size;

};

int main() {
	LinkedListStack stack;
	stack.push(0);
	stack.push(39);
	stack.push(93);

	cout << "pop:" << stack.pop() << endl;
	cout << "pop:" << stack.pop() << endl;
	cout << "pop:" << stack.pop() << endl;

	system("pause");

}
