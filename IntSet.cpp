#include "IntSet.hpp"

// конструктор по умолчанию
IntSet::IntSet() {
    arr = nullptr;
    n = 0;
}

// конструктор из массива
IntSet::IntSet(int* a, int size) {
    arr = nullptr;
    n = 0;

    // добавляем элементы через add(), чтобы не было повторов
    for (int i = 0; i < size; i++) {
        add(a[i]);
    }
}

// конструктор копирования (глубокая копия) 
IntSet::IntSet(const IntSet& other) {
    n = other.n;

    if (n == 0) {
        arr = nullptr;
        return;
    }

    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = other.arr[i];
    }
}

// оператор присваивания
IntSet& IntSet::operator=(const IntSet& other) {
    // защита от самоприсваивания
    if (this == &other) {
        return *this;
    }

    // очищаем память
    delete[] arr;

    n = other.n;

    if (n == 0) {
        arr = nullptr;
        return *this;
    }

    // выделяем новую память и копируем
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = other.arr[i];
    }

    return *this;
}

// деструктор
IntSet::~IntSet() {
    delete[] arr;
}

// проверка наличия элемента
bool IntSet::contains(int x) const {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return true;
    }
    return false;
}

// добавление элемента
void IntSet::add(int x) {
    // если элемент уже есть — не добавляем
    if (contains(x)) return;

    // создаём новый массив на 1 больше
    int* newArr = new int[n + 1];

    // копируем старые элементы
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }

    // добавляем новый элемент в конец
    newArr[n] = x;

    // удаляем старый массив
    delete[] arr;

    // обновляем данные
    arr = newArr;
    n++;
}

// удаление элемента
void IntSet::remove(int x) {
    // если элемента нет — ничего не делаем
    if (!contains(x)) return;

    // новый массив на 1 меньше
    int* newArr = nullptr;

    if (n - 1 > 0) {
        newArr = new int[n - 1];
    }

    int j = 0; // индекс для нового массива

    // копируется все кроме х
    for (int i = 0; i < n; i++) {
        if (arr[i] != x) {
            newArr[j] = arr[i];
            j++;
        }
    }

    delete[] arr;
    arr = newArr;
    n--;
}

// размер
int IntSet::size() const {
    return n;
}

// очистка
void IntSet::clear() {
    delete[] arr;
    arr = nullptr;
    n = 0;
}

// проверка на пустоту
bool IntSet::isEmpty() const {
    return n == 0;
}

// объединение множеств
IntSet IntSet::operator+(const IntSet& other) const {
    // result сначала копия текущего множества
    IntSet result(*this);

    // добавляем элементы другого множества
    for (int i = 0; i < other.n; i++) {
        result.add(other.arr[i]);
    }

    return result;
}

// разность множеств
IntSet IntSet::operator-(const IntSet& other) const {
    IntSet result;

    // добавляем элементы, которых нет в other
    for (int i = 0; i < n; i++) {
        if (!other.contains(arr[i])) {
            result.add(arr[i]);
        }
    }

    return result;
}

// пересечение множеств 
IntSet IntSet::operator*(const IntSet& other) const {
    IntSet result;

    // добавляем элементы, которые есть и там и там
    for (int i = 0; i < n; i++) {
        if (other.contains(arr[i])) {
            result.add(arr[i]);
        }
    }

    return result;
}

// сравнение множеств
bool IntSet::operator==(const IntSet& other) const {
    if (n != other.n) return false;

    for (int i = 0; i < n; i++) {
        if (!other.contains(arr[i])) return false;
    }

    return true;
}

bool IntSet::operator!=(const IntSet& other) const {
    return !(*this == other);
}

// вывод
std::ostream& operator<<(std::ostream& out, const IntSet& s) {
    out << "{ ";

    for (int i = 0; i < s.n; i++) {
        out << s.arr[i];
        if (i != s.n - 1) out << ", ";
    }

    out << " }";
    return out;
}

