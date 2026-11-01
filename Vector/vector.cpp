#include <iostream>
#include <stdexcept>
#include <new>
#include <memory>
#include <initializer_list>

template <typename T>

class Vector {
    private:
        size_t _size;
        size_t _capacity;
        T* data;
    public:
        Vector(size_t initialSize  = 0) : _size(initialSize), 
                                         _capacity(initialSize == 0 ? 1 : initialSize * 2), 
                                         data(static_cast<T*>(::operator new(sizeof(T) * _capacity))) {

            size_t i = 0;

            try {
                for(; i < _size; i++) {
                    new(&data[i]) T();
                }
            } catch(...) {
                for(size_t j = 0; j < i; j++) {
                    std::destroy_at(&data[j]);
                }
                ::operator delete(data);
                throw;
            }
        }

        Vector(std::initializer_list<T> list) : _size(list.size()), 
                                                _capacity(list.size() == 0 ? 1 : list.size() * 2), 
                                                data(static_cast<T*>(::operator new(sizeof(T) * _capacity))) {
            
            size_t i = 0;

            try {
               for(const T& value : list) {
                 new(&data[i]) T(value);
                 i++;
               }
            } catch(...) {
                for(size_t j = 0; j < i; j++) {
                    std::destroy_at(&data[j]);
                }
                ::operator delete(data);
                throw;
            }
        }

        Vector(const Vector& vec) : _size(vec._size), 
                                    _capacity(vec._capacity), 
                                    data(static_cast<T*>(::operator new(sizeof(T) * vec._capacity))) {

            size_t i = 0;

            try {
               for(; i < vec._size; i++) {
                   new(&data[i]) T(vec.data[i]);
               }
            } catch(...) {
                for(size_t j = 0; j < i; j++) {
                    std::destroy_at(&data[j]);
                }
                ::operator delete(data);
                throw;
            }
        }

        void push_back(const T& value) {
            if(_size == _capacity) {
                size_t newCap = _capacity * 2;
                T* newData = static_cast<T*>(::operator new(sizeof(T) * newCap));

                size_t i = 0;

                try {
                   for(; i < _size; i++) {
                       new (&newData[i]) T(data[i]);
                    }
                    new(&newData[i]) T(value);
                } catch(...) {
                    for(size_t j = 0; j < i; j++) {
                       std::destroy_at(&newData[j]);
                    }
                    ::operator delete(newData);
                    throw;
                }
              
                for(size_t j = 0; j < _size; j++) {
                    std::destroy_at(&data[j]);
                }
                ::operator delete(data);

                data = newData;
                _capacity = newCap;
                _size++;

            } else {
                new(&data[_size]) T(value);
                _size++;
            }
        }

        void pop_back() {
            if(_size > 0) {
                std::destroy_at(&data[_size - 1]);
                _size--;
            }
        }

        size_t size() const {
            return _size;
        }

        size_t capacity() const {
            return _capacity;
        }

        T& operator[](size_t index) {
           return data[index];
        }

        const T& operator[](size_t index) const {
            return data[index];
        }

        T& at(size_t index) {
            if(index >= _size) {
                throw std::out_of_range("Warning: Index out of range");
            }
            return data[index];
        }

        const T& at(size_t index) const {
            if(index >= _size) {
                throw std::out_of_range("Warning: Index out of range");
            }
            return data[index];
        }

        Vector& operator=(const Vector& vec) {
            if(this != &vec) {
                T* newData = static_cast<T*>(::operator new(sizeof(T) * vec._capacity));

                size_t i = 0;

                try {
                    for(; i < vec._size; i++) {
                        new(&newData[i]) T(vec.data[i]);
                    }
                } catch(...) {
                    for(size_t j = 0; j < i; j++) {
                        std::destroy_at(&newData[j]);
                    }
                    ::operator delete(newData);
                    throw;
                }

                for(size_t j = 0; j < _size; j++) {
                    std::destroy_at(&data[j]);
                }
                ::operator delete(data);

                data = newData;
                _size = vec._size;
                _capacity = vec._capacity;
            }
            return *this;
        }

        Vector operator+(const Vector& vec) const {
            Vector result;
            for(size_t i = 0; i < _size; i++) {
                result.push_back(data[i]);
            }
            for(size_t i = 0; i < vec._size; i++) {
                result.push_back(vec[i]);
            }
            return result;
        }

        Vector& operator+=(const Vector& vec) {
            size_t vecSize = vec._size;
            for(size_t i = 0; i < vecSize; i++) {
                this->push_back(vec.data[i]);
            }
            return *this;
        }

        bool operator==(const Vector& vec) const {
            if(_size != vec._size) {
                return false;
            }
            for(size_t i = 0; i < _size; i++) {
                if(data[i] != vec.data[i]) {
                    return false;
                }
            }
            return true;
        }

        ~Vector() {
            for(size_t i = 0; i < _size; i++) {
                std::destroy_at(&data[i]);
            }
            ::operator delete(data);
        }
};

int main() {
    Vector<int> v1;
    Vector<int> v2 = {10, 20, 30, 40, 50};
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(5);
    v1.pop_back();
    
    std::cout <<"Size = " << v1.size() <<std::endl;
    std::cout <<"Capacity = " << v1.capacity() <<std::endl;
    std::cout <<"Size = " << v2.size() <<std::endl;
}