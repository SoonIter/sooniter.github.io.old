/*  �ִ� ѭ������queue */
#include <iostream>
#define MAX_SIZE 5
using namespace std;

template <class T>
class Queue
{
	int count;
	int front;
	int rear;
	T data[MAX_SIZE];

public:
	Queue()
	{ //��ʼ������

		this->count = 0;
		this->front = 0;
		this->rear = -1;
	}

	bool isFull()
	{ //�ж϶����Ƿ���
		return this->count >= MAX_SIZE;
	}

	bool isEmpty()
	{ //�ж϶����Ƿ�Ϊ��
		return this->count <= 0;
	}

	void push(T item)
	{ //���

		if (this->isFull())
		{
			cerr << "��������!" << endl;
			return;
		}
		else
		{
			this->count++;
			this->rear = (this->rear + 1) % MAX_SIZE;
			this->data[this->rear] = item;
		}
	}

	void pop()
	{ //����
		if (this->isEmpty())
		{
			cerr << "����Ϊ��!" << endl;
			return;
		}
		else
		{
			this->count--;
			this->front = (this->front + 1) % MAX_SIZE;
		}
	}

	int size()
	{ //���ض��г���
		return this->count;
	}

	void show()
	{ //��������
		if (this->isEmpty())
		{
			cout << "����Ϊ��!" << endl;
			return;
		}
		else
		{
			cout << "���б���: ";
			int i = this->front;
			while (i != this->rear)
			{
				cout << this->data[i] << " ";
				i++;
				i = i % MAX_SIZE;
			}
			cout << this->data[this->rear] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Queue<int> dummy; //������ռ�

	dummy.push(11);
	dummy.push(5);
	dummy.push(23);
	dummy.push(18);
	dummy.pop();
	dummy.show();

	dummy.push(33);
	dummy.pop();
	dummy.show();

	dummy.push(77);
	dummy.show();

	return 0;
}

//���н����
//
//���б���: 5 23 18
//���б���: 23 18 33
//���б���: 23 18 33 77
