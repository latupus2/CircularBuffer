//#include <iostream>
//#include "CircularBuffer.h"
//
// Функция для вывода элементов буфера
//void printBuffer(const CircularBuffer& cb) {
//    if (cb.empty()) {
//        std::cout << "(empty)" << std::endl;
//        return;
//    }
//
//    std::cout << "Buffer contents: ";
//    for (int i = 0; i < cb.size(); ++i) {
//        std::cout << cb[i] << " "; // Используем оператор[] для доступа к элементам
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    CircularBuffer cb(5); // Создаем кольцевой буфер с емкостью 5
//
//     Заполняем буфер
//    cb.push_back('A');
//    cb.push_back('B');
//    cb.push_back('C');
//    cb.push_back('D');
//    cb.push_back('E');
//
//    std::cout << "Buffer after pushing A, B, C, D, E: ";
//    printBuffer(cb);
//
//    cb.push_back('F');
//    printBuffer(cb); // Вывод: B C D E F
//
//    cb.pop_front();
//    printBuffer(cb); // Вывод: C D E F
//
//    std::cout << "Front element: " << cb.front() << std::endl; // Вывод: C
//    std::cout << "Back element: " << cb.back() << std::endl;   // Вывод: F
//
//    cb.insert(1, 'X');
//    printBuffer(cb); // Вывод: C X D E F
//
//    cb.erase(1, 2);
//    printBuffer(cb); // Вывод: C D E F
//
//    cb.clear();
//    printBuffer(cb);
//
//    cb.resize(3, 'Y');
//    printBuffer(cb); // Вывод: Y Y Y
//
//    std::cout << cb.is_linearized() << std::endl;
//
//    cb.push_front('F');
//    printBuffer(cb); // Вывод: F Y Y Y
//    std::cout << cb.is_linearized() << std::endl;
//
//    cb.linearize();
//    std::cout << cb.is_linearized() << std::endl;
//    printBuffer(cb);
//
//    int a;
//    std::cin >> a;
//    return 0;
//}
