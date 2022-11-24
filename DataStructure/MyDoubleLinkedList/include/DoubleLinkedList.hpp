#ifndef __DOUBLELINKEDLIST_HPP__
#define __DOUBLELINKEDLIST_HPP__

#include <iostream>

template<class T> class Node;

template <class T>
class DoubleLinkedList {
private:
    Node<T>* head = nullptr;
    
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void showList();
    void clearList();
    Node<T>* findNode(const T& element);
    Node<T>* findBackNode();
    void pushFront(const T& element);
    void popFront();
    void pushMiddle(Node<T>* preNode, const T& element);
    void popMiddle(Node<T>* targetNode);
    void pushBack(const T& element);
    void popBack();
};

template <class T>
class Node {
private:
    T element = '\0';
    Node* right = nullptr;
    Node* left = nullptr;

public:
    friend DoubleLinkedList<T>;
};

#endif // __DOUBLELINKEDLIST_HPP__