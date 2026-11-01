#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>

class List {
    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
        };

        Node* first;
        Node* last;
        std::size_t _size;

    public:
        List() : first(nullptr), last(nullptr), _size(0) {}

        List(const List& list) : first(nullptr), last(nullptr), _size(0) {
            try {
                Node* current = list.first;
                while(current != nullptr) {
                    push_back(current->data);
                    current = current->next;
                }
            } catch(...) {
                clear();
                throw;
            }
        }

        void push_back(const T& value) {
            Node* newNode = new Node(value);
            if(_size == 0) {
                first = newNode;
                last = newNode;
            } else {
                last->next = newNode;
                newNode->prev = last;
                last = newNode;
            }
            _size++;
        }

        void push_front(const T& value) {
            Node* newNode = new Node(value);
            if(_size == 0) {
                first = newNode;
                last = newNode;
            } else {
                newNode->next = first;
                first->prev = newNode;
                first = newNode;
            }
            _size++;
        }

        void pop_back() {
            if(_size == 0) {
                return;
            }
            if(_size == 1) {
                delete last;
                first = nullptr;
                last = nullptr;
            } else {
                Node* temp = last;
                last = last->prev;
                last->next = nullptr;
                delete temp;
            }
            _size--;
        }

        void pop_front() {
            if(_size == 0) {
                return;
            }
            if(_size == 1) {
                delete first;
                first = nullptr;
                last = nullptr;
            } else {
                Node* temp = first;
                first = first->next;
                first->prev = nullptr;
                delete temp;
            }
            _size--;
        }

        T& front() {
            if(_size == 0)  {
                throw std::out_of_range("List is empty");
            }
            return first->data;
        }

        T& back() {
            if(_size == 0) {
                throw std::out_of_range("List is empty");
            }
            return last->data;
        }

        List& operator=(const List& list) {
            if(this != &list) {
                List temp(list);

                Node* tempFirst = first;
                first = temp.first;
                temp.first = tempFirst;

                Node* tempLast = last;
                last = temp.last;
                temp.last = tempLast;

                std::size_t tempSize = _size;
                _size = temp._size;
                temp._size = tempSize;

            }
            return *this;
        }

        void clear() {
            while(_size > 0) {
                pop_back();
            }
        }

        std::size_t size() const {
            return _size;
        }

        class Iterator {
            private:
               Node* current;
            
            public:
               Iterator(Node* ptr) : current(ptr) {}

               T& operator*() {
                return current->data;
               }

               Iterator& operator++() {
                if(current) {
                    current = current->next;
                }
                return *this;
               }

               Iterator operator++(int) {
                Iterator temp = *this;
                ++(*this);
                return temp;
               }

               bool operator==(const Iterator& list) const {
                return current == list.current;
               }

               bool operator!=(const Iterator& list) const {
                return current != list.current;
               }
        };

        Iterator begin() {
            return Iterator(first);
        }

        Iterator end() {
            return Iterator(nullptr);
        }

        ~List() {
            clear();
        }
};

int main() {
    List<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_front(3);

    list.front() = 5;
    list.back() = 20;
    
    for(int i : list) {
        std::cout << i << " ";
    }
    
    return 0;
}