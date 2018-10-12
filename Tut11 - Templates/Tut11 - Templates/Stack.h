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
	void printElem(int i) {if(size!=0) cout << "Element " << i << " is equal to " << items[i] << endl; };

protected:
	int size;
	int cap;
	T* items;

};

template <typename T>
Stack<T>::Stack() :
	size(0),
	cap(4460),
	items(new T[size]){
}

template <typename T>
Stack<T>::~Stack() {
	delete[] items;
	items = nullptr;
}

template <typename T>
void Stack<T>::Pop() {
	if (size != 0) {
		T* temp = new T[--size];
		if (size + 1 > 0) {
			for (int i = 0; i < size; i++) {
				temp[i] = items[i + 1];
			}
		}
		delete[] items;
		items = new T[size];
		memcpy(items, temp, size * sizeof(int));
		delete[] temp;
		temp = nullptr;
		if (size == 0) items = nullptr;
	}
}

template <typename T>
void Stack<T>::Push(T elem) {
	if (size != cap) {
		T* temp = new T[++size];
		if (size-1 > 0) {
			for (int i = 1; i <= size; i++) {
				temp[i] = items[i-1];
			}
		}
		temp[0] = elem;
		delete[] items;
		items = new T[size];
		memcpy(items, temp, size * sizeof(int));
		delete[] temp;
		temp = nullptr;
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