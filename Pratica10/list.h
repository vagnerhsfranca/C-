#ifndef LIST_H_
#define LIST_H_

#include <iostream>

using namespace std;

template <class T>
class List {
private:
	struct Node {
		T data;
		Node * next;
		Node(const T & data) : data(data), next(NULL) {}
	};

	int len;

	Node * head, * tail;

public:
	List() {
		this->len = 0;
		this->head = this->tail = NULL;
	}

	~List() {
		while (head != tail) {
			Node * temp  = head;
			head = head->next;
			delete temp;
		}
	}

	int length() {
		return len;
	}

	void add (const T & item) {
		Node * node = new Node(item);

		if (tail != NULL) {
			tail->next = node;
		} else {
			head = node;
		}

		tail = node;
		len ++;
	}

	T get(int idx) {
		if (idx >= len) throw "Invalid position";

		Node * tmp = find(idx);
		return tmp->data;
	}

	void insert (int idx, const T & item) {
		if (idx < 0 || idx >= len) throw "Invalid position";

		Node * node = new Node(item);

		if (idx == 0) {
			node->next = head;
			head = node;
		} else {
			Node * prev = find(idx - 1);
			node->next = prev->next;
			prev->next = node;
		}

		len++;
	}

	void remove(int idx) {
		if (idx < 0 || idx >= len) throw "Invalid position";

		Node * tmp = NULL, * prev;
		if (idx == 0) {
			tmp = head;
			head = tmp->next;
			if (tail == tmp) tail = NULL;
		} else {
			prev = find(idx - 1);
			tmp = prev->next;
			prev->next = prev->next->next;
			if (tail == tmp) tail = prev;
		}
		delete tmp;

		len--;
	}

	void print() {
		Node * tmp = head;
		while (tmp != NULL) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

private:
	Node * find(int idx) {
		Node * tmp = head;
		while (idx--) {
			tmp = tmp->next;
		}
		return tmp;
	}
};


#endif /* LIST_H_ */
