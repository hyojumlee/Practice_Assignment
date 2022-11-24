#include "DoubleLinkedList.hpp"

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    std::cout << "=====리스트 생성=====" << std::endl;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    std::cout << "=====리스트 소멸=====" << std::endl;
}

template<class T>
void DoubleLinkedList<T>::showList() {
    Node<T>* pos = head;
    
    std::cout << "List : ";
    while (nullptr != pos) {
        if (nullptr == pos->right) {
            std::cout << pos->element << std::endl;
        } else {
            std::cout << pos->element << " - ";
        }
        pos = pos->right;
    }
    std::cout << std::endl;
}

template<class T>
void DoubleLinkedList<T>::clearList() {
    Node<T>* p = nullptr;

    while (nullptr != head) {
        p = head;
        head = head->right;
        delete p;
    }
}

template<class T>
Node<T>* DoubleLinkedList<T>::findNode(const T& element) {
    Node<T>* find = head;

    if (nullptr == head) {
        find = nullptr;
    } else {
        while (nullptr != find) {
            if (find->element == element) {
                break;
            } else {
                find = find->right;
            }
        }
    }

    return find;
}

template<class T>
Node<T>* DoubleLinkedList<T>::findBackNode() {
    Node<T>* find = head;

    if (nullptr != head) {
        while (nullptr != find->right) {
            find = find->right;
        }
    } else {}

    return find;
}

template<class T>
void DoubleLinkedList<T>::pushFront(const T& element) {
    Node<T>* newNode = new Node<T>;

    newNode->element = element;
    if (nullptr == head) {
        head = newNode;
    } else {
        newNode->right = head;
        newNode->right->left = newNode;
        head = newNode;
    }
}

template<class T>
void DoubleLinkedList<T>::popFront() {
    if (nullptr != head) {
        Node<T>* pos = head;

        head = head->right;
        head->left = nullptr;

        delete pos;
    } else {}
}

template<class T>
void DoubleLinkedList<T>::pushMiddle(Node<T>* preNode, const T& element) {
    Node<T>* newNode = new Node<T>;

    newNode->element = element;
    if (nullptr == head) {
        head = newNode;
    } else if (nullptr == preNode->right) {
        newNode->right = preNode->right;
        preNode->right = newNode;
        newNode->left = preNode;
    } else {
        newNode->right = preNode->right;
        preNode->right = newNode;
        newNode->left = preNode;
        newNode->right->left = newNode;
    }
}

template<class T>
void DoubleLinkedList<T>::popMiddle(Node<T>* targetNode) {
    if (head == targetNode) {
        head = targetNode->right;
        targetNode->right->left = nullptr;
    } else if (nullptr == targetNode->right) {
        targetNode->left->right = nullptr;
    } else {
        targetNode->right->left = targetNode->left;
        targetNode->left->right = targetNode->right;
    }
    delete targetNode;
}

template<class T>
void DoubleLinkedList<T>::pushBack(const T& element) {
    Node<T>* newNode = new Node<T>;
    Node<T>* find = nullptr;

    newNode->element = element;
    if (nullptr == head) {
        head = newNode;
    } else {
        find = findBackNode();
        find->right = newNode;
        newNode->left = find;
    }
}

template<class T>
void DoubleLinkedList<T>::popBack() {
    Node<T>* find = findBackNode();

    if (find != head) {
        find->left->right = nullptr;
        
        delete find;
    } else {}
}