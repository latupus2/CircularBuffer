#include "CircularBuffer.h"
#include <cstring>

// Default constructor
CircularBuffer::CircularBuffer()
    : buffer_size(0), buffer_capacity(0), start(0), end(0), buffer(nullptr) {}

// Constructor with specified capacity
CircularBuffer::CircularBuffer(int capacity)
    : buffer_size(0), buffer_capacity(capacity), start(0), end(0), buffer(new value_type[capacity]) {}

// Constructor with specified capacity and filling of elements
CircularBuffer::CircularBuffer(int capacity, const value_type& elem)
    : CircularBuffer(capacity) {
    for (int i = 0; i < buffer_capacity; ++i) {
        buffer[i] = elem;
    }
    buffer_size = capacity;
}

// Copy constructor
CircularBuffer::CircularBuffer(const CircularBuffer& cb)
    : buffer_size(cb.buffer_size), buffer_capacity(cb.buffer_capacity), start(cb.start), end(cb.end) {
    buffer = new value_type[buffer_capacity];
    std::memcpy(buffer, cb.buffer, buffer_capacity * sizeof(value_type));
}

// destructor
CircularBuffer::~CircularBuffer() {
    delete[] buffer;
}

// Assignment operator
CircularBuffer& CircularBuffer::operator=(const CircularBuffer& cb) {
    if (this != &cb) {
        delete[] buffer;
        buffer_size = cb.buffer_size;
        buffer_capacity = cb.buffer_capacity;
        start = cb.start;
        end = cb.end;
        buffer = new value_type[buffer_capacity];
        std::memcpy(buffer, cb.buffer, buffer_capacity * sizeof(value_type));
    }
    return *this;
}

// Access by index (unchecked)
value_type& CircularBuffer::operator[](int i) {
    return buffer[(start + i) % buffer_capacity];
}

const value_type& CircularBuffer::operator[](int i) const {
    return buffer[(start + i) % buffer_capacity];
}

// Access by index (with check)
value_type& CircularBuffer::at(int i) {
    if (i < 0 || i >= buffer_size) {
        throw std::out_of_range("Index out of range");
    }
    return (*this)[i];
}

const value_type& CircularBuffer::at(int i) const {
    if (i < 0 || i >= buffer_size) {
        throw std::out_of_range("Index out of range");
    }
    return (*this)[i];
}

// Link to the first element
value_type& CircularBuffer::front() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    return buffer[start];
}

const value_type& CircularBuffer::front() const {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    return buffer[start];
}

// Link to the last element
value_type& CircularBuffer::back() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    return buffer[(end - 1 + buffer_capacity) % buffer_capacity];
}

const value_type& CircularBuffer::back() const {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    return buffer[(end - 1 + buffer_capacity) % buffer_capacity];
}

// Linearization
value_type* CircularBuffer::linearize() {
    if (is_linearized()) {
        return buffer;
    }
    value_type* new_buffer = new value_type[buffer_capacity];
    for (int i = 0; i < buffer_size; ++i) {
        new_buffer[i] = (*this)[i];
    }
    delete[] buffer;
    buffer = new_buffer;
    start = 0;
    end = buffer_size % buffer_capacity;
    return buffer;
}

// Linearization check
bool CircularBuffer::is_linearized() const {
    return start <= end;
}

// Shifts the buffer so that the element with index new_begin is at the zero index
void CircularBuffer::rotate(int new_begin) {
    if (new_begin < 0 || new_begin >= buffer_size) {
        throw std::out_of_range("New begin index out of range");
    }
    start = (start + new_begin) % buffer_capacity;
}

// Number of elements
int CircularBuffer::size() const {
    return buffer_size;
}

// Empty check
bool CircularBuffer::empty() const {
    return buffer_size == 0;
}

// Buffer capacity
int CircularBuffer::capacity() const {
    return buffer_capacity;
}

// Number of free cells
int CircularBuffer::reserve() const {
    return buffer_capacity - buffer_size;
}

// Full check
bool CircularBuffer::full() const {
    return buffer_size == buffer_capacity;
}

// Set new capacity of buffer
void CircularBuffer::set_capacity(int new_capacity) {
    if (new_capacity < buffer_size) {
        throw std::invalid_argument("New capacity cannot be less than current size");
    }
    value_type* new_buffer = new value_type[new_capacity];
    for (int i = 0; i < buffer_size; ++i) {
        new_buffer[i] = (*this)[i];
    }
    delete[] buffer;
    buffer = new_buffer;
    buffer_capacity = new_capacity;
    start = 0;
    end = buffer_size % buffer_capacity;
}

// Changing the buffer size
void CircularBuffer::resize(int new_size, const value_type& item) {
    if (new_size < 0) {
        throw std::invalid_argument("New size must be non-negative");
    }
    if (new_size > buffer_capacity) {
        set_capacity(new_size);
    }

    for (int i = buffer_size; i < new_size; ++i) {
        push_back(item);
    }
    buffer_size = new_size;
    end = buffer_size % buffer_capacity;
}

// Swapping buffer contents
void CircularBuffer::swap(CircularBuffer& cb) {
    std::swap(buffer, cb.buffer);
    std::swap(buffer_size, cb.buffer_size);
    std::swap(buffer_capacity, cb.buffer_capacity);
    std::swap(start, cb.start);
    std::swap(end, cb.end);
}

// Adding an item to the end
void CircularBuffer::push_back(const value_type& item) {
    if (full()) {
        pop_front(); // Перезапись первого элемента, если буфер полон
    }
    buffer[end] = item;
    end = (end + 1) % buffer_capacity;
    buffer_size++;
}

// Adding an item to the start
void CircularBuffer::push_front(const value_type& item) {
    if (full()) {
        pop_back(); // Перезапись последнего элемента, если буфер полон
    }
    start = (start - 1 + buffer_capacity) % buffer_capacity;
    buffer[start] = item;
    buffer_size++;
}

// Deleting the last item
void CircularBuffer::pop_back() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    end = (end - 1 + buffer_capacity) % buffer_capacity;
    buffer_size--;
}

// Deleting the first element
void CircularBuffer::pop_front() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    start = (start + 1) % buffer_capacity;
    buffer_size--;
}

// Inserting an element by index
void CircularBuffer::insert(int pos, const value_type& item) {
    if (pos < 0 || pos > buffer_size) {
        throw std::out_of_range("Position out of range");
    }

    if (full()) {
        pop_front();
    }

    for (int i = buffer_size; i > pos; --i) {
        buffer[(start + i) % buffer_capacity] = buffer[(start + i - 1) % buffer_capacity];
    }

    buffer[(start + pos) % buffer_capacity] = item;
    end = (end + 1) % buffer_capacity;
    buffer_size++;
}

// Deleting items from the buffer
void CircularBuffer::erase(int first, int last) {
    if (first < 0 || last > buffer_size || first >= last) {
        throw std::out_of_range("Invalid range");
    }

    for (int i = first; i < buffer_size - (last - first); ++i) {
        (*this)[i] = (*this)[i + (last - first)];
    }
    buffer_size -= (last - first);
    end = (start + buffer_size) % buffer_size;
}

// Clearing the buffer
void CircularBuffer::clear() {
    buffer_size = 0;
    start = 0;
    end = 0;
}

// ==
bool operator==(const CircularBuffer& a, const CircularBuffer& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

//  !=
bool operator!=(const CircularBuffer& a, const CircularBuffer& b) {
    return !(a == b);
}
