#pragma once

template <typename T>
class Matrix
{
public:

	static const int default_x = 3;
	static const int default_y = 3;
	Matrix(int x = default_x, int y = default_y);
	~Matrix();

	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	T get_element(int x, int y) const;
	void set_element(int x, int y, T elem);

protected:
	T** cells;
	int x_size;
	int y_size;
};

template <typename T>
Matrix<T>::Matrix(int x = default_x, int y = default_y) {
	cells = new T*[x_size];
	for (int i = 0; i < x_size; i++) {
		cells[i] = new T[y_size];
		memset(cells[i], 0, (y_size * sizeof(T)));
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < x_size; i++) {
		delete[] cells[i];
	}
	delete[] cells;
}

template <typename T>
T Matrix<T>::get_element(int x, int y) const {
	return (cells[x][y]);
}

template <typename T>
void Matrix<T>::set_element(int x, int y, T elem) {
	cells[x][y] = elem;
}