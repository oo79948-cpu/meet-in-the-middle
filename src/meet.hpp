#pragma once

template <typename T>
struct Link {
    T number;
    Link* next;
    explicit Link(T num);
};

template <typename T>
class LinkedList {
    Link<T>* head;
    Link<T>* tail;
    int size;
public:
    LinkedList();
    ~LinkedList();
    void add(T item);
    double getMedian();
    double getMean();

};