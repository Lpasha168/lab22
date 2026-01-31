#include <iostream>
#include "IntSet.hpp"

int main() {
    // создание объектов
    IntSet A; // конструктор по умолчанию
    A.add(5);
    A.add(10);
    A.add(5); // повтор не добавится

    std::cout << "A = " << A << "\n";

    int arr[] = { 1, 2, 3, 2, 4 };
    IntSet B(arr, 5); // параметризованный

    std::cout << "B = " << B << "\n\n";

    // копирование
    IntSet C(B); // конструктор копирования
    std::cout << "C (copy of B) = " << C << "\n";

    // присваивание
    IntSet D;
    D = A; // operator=
    std::cout << "D (assigned from A) = " << D << "\n\n";

    // работа операторов
    IntSet unionSet = A + B;
    IntSet diffSet = B - A;
    IntSet interSet = A * B;

    std::cout << "A + B = " << unionSet << "\n";
    std::cout << "B - A = " << diffSet << "\n";
    std::cout << "A * B = " << interSet << "\n\n";

    // сравнение
    std::cout << "B == C ? " << (B == C ? "true" : "false") << "\n";
    std::cout << "A != B ? " << (A != B ? "true" : "false") << "\n\n";

    // констнатный объект
    const IntSet CONSTSET = A;
    std::cout << "CONSTSET = " << CONSTSET << "\n";
    std::cout << "CONSTSET contains 10? " << (CONSTSET.contains(10) ? "true" : "false") << "\n";
    std::cout << "CONSTSET size = " << CONSTSET.size() << "\n\n";

    // очистка
    A.remove(10);
    std::cout << "A after remove(10) = " << A << "\n";

    A.clear();
    std::cout << "A after clear() = " << A << "\n";
    std::cout << "A isEmpty? " << (A.isEmpty() ? "true" : "false") << "\n";

    return 0;
}

