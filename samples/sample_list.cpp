// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
using namespace std;
//---------------------------------------------------------------------------


// Объявление структуры узла
struct Node {
    int data;      // Данные, хранящиеся в узле
    Node* next;    // Указатель на следующий узел

    // Конструктор для создания узла
    Node(int value) : data(value), next(nullptr) {}
};

// Объявление класса для связного списка
class LinkedList {
private:
    Node* head;    // Указатель на первый узел списка

public:
    // Конструктор
    LinkedList() : head(nullptr) {}

    // Деструктор для освобождения памяти
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;

        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Метод для добавления элемента в конец списка
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode; // Если список пуст, новый узел становится головой
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next; // Перемещаемся к последнему узлу
        }
        current->next = newNode; // Добавляем новый узел в конец
    }

    // Метод для удаления узла по значению
    void remove(int value) {
        if (!head) return; // Если список пуст, ничего не делаем

        // Если нужно удалить голову списка
        if (head->data == value) {
            Node* temp = head;
            head = head->next; // Сдвигаем голову на следующий элемент
            delete temp;         // Освобождаем память
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next; // Поиск узла с заданным значением
        }

        if (current->next) {
            Node* temp = current->next; // Узел, который нужно удалить
            current->next = current->next->next; // Пропускаем удаляемый узел
            delete temp; // Освобождаем память
        }
    }

    // Метод для вывода элементов списка
    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl; // Конец списка
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    LinkedList list;

    // Добавление элементов в список
    list.append(10);
    list.append(20);
    list.append(30);

    // Вывод списка
    std::cout << "Содержимое списка: ";
    list.print(); // Ожидается вывод: 10 -> 20 -> 30 -> nullptr

    // Удаление элемента
    list.remove(20);
    std::cout << "После удаления 20: ";
    list.print(); // Ожидается вывод: 10 -> 30 -> nullptr

    // Удаление элемента, которого нет
    list.remove(40);
    std::cout << "После попытки удаления 40: ";
    list.print(); // Ожидается вывод: 10 -> 30 -> nullptr

    return 0;
}