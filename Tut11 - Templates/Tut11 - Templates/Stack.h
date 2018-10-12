#pragma once
template <typename T>
class Stack
{
public:

	Stack();
	~Stack();

	void Pop();
	void Push(T elem);
	int getSize();
	bool empty();

	//zzzz
	void printElem(int i) { cout << "Element " << i << " is equal to " << items[i] << endl; };

protected:
	int size;
	int cap;
	T* items;

};

template <typename T>
Stack<T>::Stack() :
	size(0),
	cap(100),
	items(new T[size]){
}

template <typename T>
Stack<T>::~Stack() {
	for (int i = 0; i < size; i++) {
		delete items[i];
		delete temp[i];
	}
	delete[] items;
	delete[] temp;
}

template <typename T>
void Stack<T>::Pop() {
	if (size != 0) { 
		T* temp = new T[size--];
		for (int i = 0; i < size; i++) {
			temp[i] = items[i];
		}
		items = temp;
		//delete[] temp;
	}
}

template <typename T>
void Stack<T>::Push(T elem) {
	if (size != cap) {
		T* temp = new T[size+1];
		if (size != 0) {
			for (int i = 0; i < size; i++) {
				temp[i] = items[i];
			}
		}
		temp[size] = elem;
		items = temp;
		size++;
		//delete[] temp;
	}
}

template <typename T>
int Stack<T>::getSize() {
	return size;
}

template <typename T>
bool Stack<T>::empty() {
	if (size == 0) return true; else return false;
}