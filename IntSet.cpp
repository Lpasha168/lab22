#include "IntSet.hpp"

// ====== Конструктор по умолчанию ======
IntSet::IntSet() {
    arr = nullptr;
    n = 0;
}

// ====== Конструктор из массива ======
IntSet::IntSet(int* a, int size) {
    arr = nullptr;
    n = 0;

    // добавляем элементы через add(), чтобы не было повторов
    for (int i = 0; i < size; i++) {
        add(a[i]);
    }
}

// ====== Конструктор копирования (глубокая копия) ======
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

// ====== Оператор присваивания ======
IntSet& IntSet::operator=(const IntSet& other) {
    // защита от самоприсваивания
    if (this == &other) {
        return *this;
    }

    // удаляем старую память
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

// ====== Деструктор ======
IntSet::~IntSet() {
    delete[] arr;
}

// ====== Проверка наличия элемента ======
bool IntSet::contains(int x) const {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return true;
    }
    return false;
}

// ====== Добавление элемента ======
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

// ====== Удаление элемента ======
void IntSet::remove(int x) {
    // если элемента нет — ничего не делаем
    if (!contains(x)) return;

    // новый массив на 1 меньше
    int* newArr = nullptr;

    if (n - 1 > 0) {
        newArr = new int[n - 1];
    }

    int j = 0; // индекс для нового массива

    // копируем все элементы кроме x
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

// ====== Размер множества ======
int IntSet::size() const {
    return n;
}

// ====== Очистка множества ======
void IntSet::clear() {
    delete[] arr;
    arr = nullptr;
    n = 0;
}

// ====== Проверка на пустоту ======
bool IntSet::isEmpty() const {
    return n == 0;
}

// ====== Объединение множеств ======
IntSet IntSet::operator+(const IntSet& other) const {
    // result сначала копия текущего множества
    IntSet result(*this);

    // добавляем элементы другого множества
    for (int i = 0; i < other.n; i++) {
        result.add(other.arr[i]);
    }

    return result;
}

// ====== Разность множеств ======
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

// ====== Пересечение множеств ======
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

// ====== Сравнение множеств ======
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

// ====== Вывод множества ======
std::ostream& operator<<(std::ostream& out, const IntSet& s) {
    out << "{ ";

    for (int i = 0; i < s.n; i++) {
        out << s.arr[i];
        if (i != s.n - 1) out << ", ";
    }

    out << " }";
    return out;
}
