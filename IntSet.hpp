#ifndef INSET_HPP
#define INSET_HPP
#include <iostream>

class IntSet {
private:
    int* arr;   // динамический массив
    int n;      // количество элементов

public:
    // Конструкторы
    IntSet();                         // по умолчанию (пустое множество)
    IntSet(int* a, int size);          // параметризованный (из массива)
    IntSet(const IntSet& other);       // конструктор копирования

    // Оператор присваивания
    IntSet& operator=(const IntSet& other);

    // Деструктор
    ~IntSet();

    // Методы
    void add(int x);
    void remove(int x);
    bool contains(int x) const;
    int size() const;
    void clear();
    bool isEmpty() const;

    // Операторы множеств
    IntSet operator+(const IntSet& other) const; // объединение
    IntSet operator-(const IntSet& other) const; // разность
    IntSet operator*(const IntSet& other) const; // пересечение

    // Сравнение
    bool operator==(const IntSet& other) const;
    bool operator!=(const IntSet& other) const;

    // Вывод
    friend std::ostream& operator<<(std::ostream& out, const IntSet& s);
};
#endif
