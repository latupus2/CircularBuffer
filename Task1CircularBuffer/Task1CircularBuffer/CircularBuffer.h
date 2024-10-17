#include <stdexcept>
#include <algorithm>

typedef char value_type;
class CircularBuffer {
private:
    value_type* buffer;
    int start;
    int end;
    int buffer_size;
    int buffer_capacity;

public:
    CircularBuffer(); // default constructor
    explicit CircularBuffer(int capacity); // constructor with capacity
    CircularBuffer(int capacity, const value_type& elem); // constructor with capacity and fill element
    CircularBuffer(const CircularBuffer& cb); // constructor with copy
    ~CircularBuffer(); // deconstructor

    // Index access. Do not check the index
    value_type& operator[](int i);
    const value_type& operator[](int i) const;

    // Index access. check the index
    value_type& at(int i);
    const value_type& at(int i) const;

    // Link to the first element
    value_type& front();
    const value_type& front() const;

    // Link to the last element
    value_type& back();
    const value_type& back() const;

    value_type* linearize(); // linearize
    bool is_linearized() const; // Checks if the buffer is linearized
    void rotate(int new_begin); // Shifts the buffer so that the element with index new_begin is at index zero.

    
    int size() const; // number of elements
    bool empty() const; // check if it is empty
    int capacity() const; // capacity of buffer
    int reserve() const; // Number of free cells
    bool full() const;// //true, если size() == capacity().
    void set_capacity(int new_capacity); // Changing the buffer capacity
    void resize(int new_size, const value_type& item = value_type()); // Changing the buffer size
    CircularBuffer& operator=(const CircularBuffer& cb);// Assignment operator
    void swap(CircularBuffer& cb);// Swapping buffer contents


    void push_back(const value_type& item); // Adding an item to the end
    void push_front(const value_type& item); // Adding an item to the start
    void pop_back(); // delete last element
    void pop_front(); // delete first element
    void insert(int pos, const value_type& item); // Inserting an element by index
    void erase(int first, int last); // Deleting items from the buffer
    void clear(); // Clearing the buffer

    // Comparison operators
    friend bool operator==(const CircularBuffer& a, const CircularBuffer& b);
    friend bool operator!=(const CircularBuffer& a, const CircularBuffer& b);
    
};


