#include <iostream>
using namespace std;

class LinkedListStack {

	//Stack�����`�I���c�A��Ƥ��e�O�sint
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

	//deconstructor����O���� �̧ǧR���C��node  delete�u��z�Lpointer�h��O����Ŷ��R��?
	~LinkedListStack()
	{
		Node * tempNode = nullptr;
		while (top)
		{
			tempNode = top;//�O���_�쥻top��node

			delete top;//�R��stack��e�̤W�h��node �P��top�]�|�]���ܦ����V�@�ӪŪ��O����Ŷ�
			top = tempNode->next;//���top���V����m�A���L�h���쥻top��next node
		}

		delete tempNode;//�����R���H�� �R��temp��node
	}

	//�[�J��ƨ�stack
	void push(int value)
	{
		Node * n = new Node;//�s�W�@�Ӧs��ƪ�stack�`�I

		n->data = value;//����stack�`�I���[�x�s���
		n->next = top;//�N��stack�`�I�P�{����stack�`�I�s���Y�s��

		top = n;//�����s��stack�`�I�Y

		size++;
	}

	int pop()
	{
		if (top != nullptr)//�p�Gstack�����F��
		{
			int value = top->data;//����
			Node * tempNode = top;

			//delete top;//�����{���`�I

			top = tempNode->next;//��top���Ы���쥻top�`�I���U�@��stack�`�I

			delete tempNode;//�����Ȧs���`�I

			return value;//�^�ǭnpop�����G
		}
		else//�p�Gstack�w�g�S�F��F
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