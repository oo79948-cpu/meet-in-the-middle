
#include "meet.hpp"
#include <iostream>

template <typename T>
Link<T>::Link(T num) {
    this->number = num;
    this->next = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
}

template <typename T>
void LinkedList<T>::add(T item) {
    Link<T>* new_node = new Link<T>(item);

    if (this->head == nullptr) {
        this->head = new_node;
        this->tail = new_node;
    } else {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    size++;
}

template <typename T>
double LinkedList<T>::getMedian() {
    if (size == 0) {
        throw std::out_of_range("Cannot get median of empty list");
    }
    if (size % 2 == 1) {
        int position = (size / 2);
        Link<T>* current = this->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current->number;
    } else {
        int position = (size / 2)-1;
        Link<T>* current = this->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return (static_cast<double>(current->number) + static_cast<double>(current->next->number))/2;
    }
}

template <typename T>
double LinkedList<T>::getMean() {
    if (size == 0) {
        throw std::out_of_range("Cannot get mean of empty list");
    }

    Link<T> *current = this->head;
    int total = 0;
    while(current != nullptr) {
        total += current->number;
        current = current->next;
    }
    return total/static_cast<double>(size);
}

template<typename T>
double LinkedList<T>::getMode() {
    if (size == 0) {
        throw std::out_of_range("Cannot get mode of empty list");
    }

    Link<T> *current = this->head;
    int current_number = current->number;
    int current_count = 0;
    int top_number = current_number;
    int top_count = 0;

    while (current != nullptr) {

        if (current->number != current_number) {
            if (top_count < current_count) {
                top_number = current_number;
                top_count = current_count;
            }
            current_number = current->number;
            current_count = 1;
        } else {
            current_count++;
        }
        current = current->next;
    }
    if (top_count < current_count) {
        top_number = current_number;
    }
    return top_number;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Link<T> *next = nullptr;
    Link<T> *current = this->head;
    while(current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}