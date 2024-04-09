#include <iostream>
#include <vector>

template <typename T>
class Vector {
private:
    std::vector<T> vec;

public:
    Vector() {}

    explicit Vector(int size) : vec(size) {}

    Vector(const std::vector<T>& v) : vec(v) {}

    T& operator[](int index) {
        return vec[index];
    }

    const T& operator[](int index) const {
        return vec[index];
    }

    Vector<T> operator*(T scalar) {
        Vector<T> result(vec.size());
        for (int i = 0; i < vec.size(); ++i) {
            result[i] = vec[i] * scalar;
        }
        return result;
    }

    T operator*(const Vector<T>& other) {
        T result = 0;
        for (int i = 0; i < vec.size(); ++i) {
            result += vec[i] * other[i];
        }
        return result;
    }

    int size() const {
        return vec.size();
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Vector<int> v1({ 1, 2, 3 });
    Vector<int> v2({ 4, 5, 6 });

    Vector<int> result = v1 * 2;
    std::cout << "Scalar multiplication result: ";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    int dotProduct = v1 * v2;
    std::cout << "Dot product result: " << dotProduct << std::endl;

    return 0;
}