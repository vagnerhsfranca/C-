#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>

template <class T>
class Queue {
private:

	struct Node {
		T data;
		Node * next;
		Node(const T & data) : data(data), next(NULL) {}
	};

	int len;
	Node * head, * tail;

public:
	Queue() {
		this->len = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	~Queue() {
		while (!this->empty()) {
			this->dequeue();
		}
	}

	void enqueue(const T & item) {
		Node * node = new Node(item);
		if (node == NULL) throw "Memória cheia!";

		if (head == NULL)
			head = node;
		else
			tail->next = node;
		tail = node;
		len++;
	}

	T dequeue() {
		if (this->empty()) throw "Fila vazia!";
		Node * tmp;
		T data;
		tmp = head;
		data = tmp->data;
		head = head->next;
		if (head == NULL)
			tail = NULL;
		delete tmp;
		len--;
		return data;
	}

	int full() {
		return 0;
	}

	int empty() {
		return len == 0;
	}

	int length() {
		return len;
	}
};


#endif /* QUEUE_H_ */
