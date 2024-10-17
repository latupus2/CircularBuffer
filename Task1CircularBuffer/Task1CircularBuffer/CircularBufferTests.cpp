#include "CircularBuffer.h"
#include <gtest/gtest.h>

// Test default constructor
TEST(CircularBufferTest, DefaultConstructor) {
    CircularBuffer cb;
    EXPECT_EQ(cb.size(), 0);
    EXPECT_TRUE(cb.empty());
}

// Test constructor with capacity
TEST(CircularBufferTest, ConstructorWithCapacity) {
    CircularBuffer cb(10);
    EXPECT_EQ(cb.size(), 0);
    EXPECT_EQ(cb.capacity(), 10);
}

// Test constructor with capacity and fill element
TEST(CircularBufferTest, ConstructorWithCapacityAndFill) {
    CircularBuffer cb(10, 'A');
    EXPECT_EQ(cb.size(), 10);
    EXPECT_EQ(cb.capacity(), 10);
    for (int i = 0; i < cb.size(); ++i) {
        EXPECT_EQ(cb[i], 'A');
    }
}

// Test swap function
TEST(CircularBufferTest, SwapBuffers) {
    CircularBuffer cb1(2);
    cb1.push_back('A');
    cb1.push_back('B');

    CircularBuffer cb2(2);
    cb2.push_back('C');
    cb2.push_back('D');

    cb1.swap(cb2);

    EXPECT_EQ(cb1[0], 'C');
    EXPECT_EQ(cb1[1], 'D');
    EXPECT_EQ(cb2[0], 'A');
    EXPECT_EQ(cb2[1], 'B');
}

// Test clear
TEST(CircularBufferTest, ClearBuffer) {
    CircularBuffer cb(5, 'A');
    cb.clear();
    EXPECT_EQ(cb.size(), 0);
    EXPECT_TRUE(cb.empty());
}

// Test push_back
TEST(CircularBufferTest, PushBack) {
    CircularBuffer cb(5);
    cb.push_back('A');
    cb.push_back('B');
    EXPECT_EQ(cb.size(), 2);
    EXPECT_EQ(cb[0], 'A');
    EXPECT_EQ(cb[1], 'B');
}

// Test push_front
TEST(CircularBufferTest, PushFront) {
    CircularBuffer cb(5);
    cb.push_front('A');
    cb.push_front('B');
    cb.push_front('C');
    EXPECT_EQ(cb.size(), 3);
    EXPECT_EQ(cb[0], 'C');
    EXPECT_EQ(cb[1], 'B');
    EXPECT_EQ(cb[2], 'A');
}

// Test overwriting when buffer is full
TEST(CircularBufferTest, OverwriteOnPushBackWhenFull) {
    CircularBuffer cb(3);
    cb.push_back('A');
    cb.push_back('B');
    cb.push_back('C');
    cb.push_back('D');
    EXPECT_EQ(cb.size(), 3);
    EXPECT_EQ(cb[0], 'B');
    EXPECT_EQ(cb[1], 'C');
    EXPECT_EQ(cb[2], 'D');
}

// Test pop_back
TEST(CircularBufferTest, PopBack) {
    CircularBuffer cb(5);
    cb.push_back('A');
    cb.push_back('B');
    cb.pop_back();
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.back(), 'A');
}

// Test pop_front
TEST(CircularBufferTest, PopFront) {
    CircularBuffer cb(5);
    cb.push_back('A');
    cb.push_back('B');
    cb.pop_front();
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.front(), 'B');
}

// Test at 
TEST(CircularBufferTest, AccessOutOfRange) {
    CircularBuffer cb(5);
    cb.push_back('A');
    cb.push_back('B');
    EXPECT_THROW(cb.at(2), std::out_of_range);
}

// Test resize to a larger capacity
TEST(CircularBufferTest, ResizeLarger) {
    CircularBuffer cb(3);
    cb.push_back('A');
    cb.push_back('B');
    cb.resize(5, 'C');
    EXPECT_EQ(cb.size(), 5);
    EXPECT_EQ(cb[0], 'A');
    EXPECT_EQ(cb[1], 'B');
    EXPECT_EQ(cb[2], 'C');
    EXPECT_EQ(cb[3], 'C');
    EXPECT_EQ(cb[4], 'C');
}

// Test resize to a smoller capacity
TEST(CircularBufferTest, ResizeSmoller) {
    CircularBuffer cb(5);
    cb.push_back('A');
    cb.push_back('B');
    cb.push_back('C');
    cb.push_back('D');
    cb.push_back('F');
    cb.resize(2, 'C');
    EXPECT_EQ(cb.size(), 2);
    EXPECT_EQ(cb[0], 'A');
    EXPECT_EQ(cb[1], 'B');
}

// Test equality operator
TEST(CircularBufferTest, EqualityOperator) {
    CircularBuffer cb1(5);
    cb1.push_back('A');
    cb1.push_back('B');

    CircularBuffer cb2(3);
    cb2.push_back('A');
    cb2.push_back('B');

    EXPECT_TRUE(cb1 == cb2);
    cb2.push_back('C');
    EXPECT_FALSE(cb1 == cb2);
}

// Test inequality operator
TEST(CircularBufferTest, InequalityOperator) {
    CircularBuffer cb1(5);
    cb1.push_back('A');
    cb1.push_back('B');

    CircularBuffer cb2(3);
    cb2.push_back('A');
    cb2.push_back('B');

    EXPECT_FALSE(cb1 != cb2);
    cb2.push_back('C');
    EXPECT_TRUE(cb1 != cb2);
}

// Test set_capacity
TEST(CircularBufferTest, SetCapacity) {
    CircularBuffer cb(5, 'A'); // Initial capacity of 5, filled with 'a'

    EXPECT_EQ(cb.size(), 5);
    EXPECT_EQ(cb.capacity(), 5);

    cb.set_capacity(8);
    EXPECT_EQ(cb.size(), 5);
    EXPECT_EQ(cb.capacity(), 8);
    for (int i = 0; i < cb.size(); ++i) {
        EXPECT_EQ(cb[i], 'A');
    }

    EXPECT_THROW(cb.set_capacity(4), std::invalid_argument);
}

// Test insert
TEST(CircularBufferTest, InsertElement) {
    CircularBuffer cb(5);
    cb.push_back('A');
    cb.push_back('B');
    cb.insert(1, 'C');
    EXPECT_EQ(cb[0], 'A');
    EXPECT_EQ(cb[1], 'C');
    EXPECT_EQ(cb[2], 'B');
    EXPECT_EQ(cb.size(), 3);
}

// Test erase
TEST(CircularBufferTest, EraseElements) {
    CircularBuffer cb(5);
    cb.push_back('A');
    cb.push_back('B');
    cb.push_back('C');
    cb.erase(0, 2);  // erase A and B
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.front(), 'C');
}
