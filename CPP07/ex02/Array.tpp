template<typename T>;
Array<T>::Array() : elements(NULL), n(0) {
    std::cout << "Default constructor called. Size: " << n << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), n(n) {
    std::cout << "Parameterized constructor called. Size: " << n << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T> &other) : elements(new T[other.n]()), n(other.n) {
    std::cout << "Copy constructor called. Size: " << n << std::endl;
    for (unsigned int i = 0; i < n; ++i) {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        std::cout << "Assignment operator called. New size: " << other.n << std::endl;
        delete[] elements;
        n = other.n;
        elements = new T[n]();
        for (unsigned int i = 0; i < n; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] elements;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= n) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return n;
}