#pragma once

template <typename T>
class Matrix
{
public:
	Matrix(int x = default_x, int y = default_y);
	~Matrix();
	Matrix(const Matrix<T>& src);
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	T get_element(int x, int y) const;
	void set_element(int x, int y, T elem);


	// constant elements
	static const int default_x = 3;
	static const int default_y = 3;

protected:
	T** cells;
	int x_size;
	int y_size;
};

template <typename T>
Matrix<T>::Matrix(int x, int y) :
	x_size(x), y_size(y) {
	cells = new T*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new T[y_size];
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < x_size; ++i) {
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

/************************************************************* Matrix Int *****************************************************************/

class MatrixInt
{
public:
	MatrixInt(int x = default_x, int y = default_y);
	~MatrixInt();
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	int get_element(int x, int y) const;
	void set_element(int x, int y, int elem);
	// constant elements
	static const int default_x = 3;
	static const int default_y = 3;
protected:
	int** cells;
	int x_size;
	int y_size;
};

MatrixInt::MatrixInt(int x, int y) :
	x_size(x), y_size(y) {
	cells = new int*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new int[y_size];
	}
}

MatrixInt::~MatrixInt() {
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

int MatrixInt::get_element(int x, int y) const {
	return (cells[x][y]);
}

void MatrixInt::set_element(int x, int y, int elem) {
	cells[x][y] = elem;
}