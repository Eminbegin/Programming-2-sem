#ifndef LAB3_CIRCULARBUFFER_H
#define LAB3_CIRCULARBUFFER_H

template<typename T>
class CircularBuffer {
private:
    size_t id_tail = 0, id_head = 0, capacity = 0, size = 0;
    T* buffer;

    void emptyError() {
        throw std::logic_error("Buffer is empty");
    }

    void outOfRangeError() {
        throw std::logic_error("Haven't element with this index");
    }

    void resize(size_t newSize, bool isHead) {
        T* copyBuffer = new T[size];
        for (int i = 0; i < size; ++i)
            copyBuffer[i] = this->operator[](i);

        delete[] buffer;
        capacity = newSize;
        buffer = new T[capacity];
        size = std::min(size, capacity);
        for (int i = 0; i < size; ++i)
            buffer[isHead ? i + 1 : i] = copyBuffer[i];

        id_head = isHead ? 1 : 0;
        id_tail = size;
    }

public:
    class CircularIterator : public std::iterator<std::random_access_iterator_tag, T> {
    public:
        explicit CircularIterator(CircularBuffer* buffer_ptr_ = nullptr, size_t current_ = 0, size_t it_size_ = 0) : buffer_ptr(buffer_ptr_), current(current_), it_size(it_size_) {}

        CircularIterator(const CircularIterator& it) = default;

        ~CircularIterator() = default;

        CircularIterator& operator=(const CircularIterator& iterator) = default;

        bool operator==(const CircularIterator& otherIterator) const {
            return it_size == otherIterator.it_size && buffer_ptr == otherIterator.buffer_ptr;
        }
        
        bool operator!=(const CircularIterator& otherIterator) const { return !(this->operator==(otherIterator)); }

        bool operator>=(const CircularIterator& otherIterator) const { return !this->operator<(otherIterator); }

        bool operator<=(const CircularIterator& otherIterator) const { return !this->operator>(otherIterator); }

        bool operator>(const CircularIterator& otherIterator) const { return it_size < otherIterator.it_size; }

        bool operator<(const CircularIterator& otherIterator) const { return it_size > otherIterator.it_size; }

        CircularIterator& operator+=(const size_t& movement) {
            current += movement;
            current %= buffer_ptr->capacity;
            it_size -= movement;
            return (*this);
        }

        CircularIterator& operator-=(const size_t& movement) {
            current -= movement;
            current += buffer_ptr->capacity;
            current %= buffer_ptr->capacity;
            it_size += movement;
            return (*this);
        }

        CircularIterator& operator++() {
            ++current;
            current %= buffer_ptr->capacity;
            --it_size;
            return *this;
        }

        CircularIterator& operator--() {
            current = current - 1 + buffer_ptr->capacity;
            current %= buffer_ptr->capacity;
            ++it_size;
            return *this;
        }

        CircularIterator operator++(int) {
            CircularIterator it = *this;
            ++it;
            return it;
        }

        CircularIterator operator--(int) {
            auto it = *this;
            --* this;
            return it;
        }

        CircularIterator operator+(const size_t& movement) {
            auto temp = *this;
            temp += movement;
            return temp;
        }

        CircularIterator operator-(const size_t& movement) {
            auto temp = *this;
            temp -= movement;
            return temp;
        }

        std::ptrdiff_t operator-(const CircularIterator& otherIterator) {
            return abs((int)it_size - otherIterator.it_size);
        }

        T operator*() { return buffer_ptr->buffer[current]; }

        T* operator->() { return &buffer_ptr->buffer[current]; }

    private:
        CircularBuffer* buffer_ptr;
        size_t current, it_size;
    };

    CircularBuffer() = default;

    explicit CircularBuffer(const std::vector<T>& vector) : capacity(vector.size()) {
        buffer = new T[capacity];
        for (int i = 0; i < capacity; ++i)
            push_back(vector[i]);
    }

    explicit CircularBuffer(size_t otherSize) : capacity(otherSize) {
        buffer = new T[capacity];
    }

    void push_back(const T& element) {
        if (isFull())
            resize(capacity * 2);
        buffer[id_tail++] = element;
        id_tail %= capacity;
        size++;
    }

    void push_front(const T& element) {
        if (isFull())
            resize(capacity * 2, true);
        id_head = (int)(id_head - 1) < 0 ? capacity - 1 : id_head - 1;
        buffer[id_head] = element;
        id_head %= capacity;
        size++;
    }

    void pop_front() {
        if (isEmpty()) {
            emptyError();
            return;
        }
        id_head = (id_head + 1) % capacity;
        size--;
    }

    void pop_back() {
        if (isEmpty()) {
            emptyError();
            return;
        }
        id_tail = (int)(id_tail - 1) < 0 ? capacity - 1 : id_tail - 1;
        size--;
    }

    T& first() {
        if (isEmpty())
            emptyError();
        return buffer[id_head];
    }

    T& last() {
        if (isEmpty())
            emptyError();
        return buffer[(int)(id_tail - 1) < 0 ? capacity - 1 : id_tail - 1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void resize(size_t newSize) {
        resize(newSize, false);
    }

    void print(std::ostream& out) {
        if (isEmpty()) return;
        for (int i = 0; i < size; ++i)
            out << this->operator[](i) << ' ';
    }

    T& operator[](size_t i) {
        if (i >= size || isEmpty()) {
            outOfRangeError();
            return buffer[capacity - 1];
        }
        return buffer[(id_head + i) % capacity];
    }
    size_t get_capacity() {
        return capacity;
    }

    CircularIterator begin() {
        return CircularIterator(this, id_head % capacity, size);
    }

    CircularIterator end() {
        return CircularIterator(this, id_tail % capacity, 0);
    }

    ~CircularBuffer() {
        delete[] buffer;
    }
};

#endif //LAB3_CIRCULARBUFFER_H
