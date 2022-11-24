#include "DoubleLinkedList.hpp"
#include "DoubleLinkedList.cpp"

#include <iostream>

int main() {
    DoubleLinkedList<char> head;
    Node<char>* node;

    std::cout << "리스트 맨 앞에 a 원소 삽입" << std::endl;
    head.pushFront('a');
    head.showList();
    
    std::cout << "b 원소 삽입" << std::endl;
    head.pushFront('b');
    head.showList();

    std::cout << "리스트 맨 뒤에 c 원소 삽입" << std::endl;
    head.pushBack('c');
    head.showList();

    std::cout << "리스트 맨 앞 원소 삭제" << std::endl;
    head.popFront();
    head.showList();

    std::cout << "리스트 맨 뒤 원소 삭제" << std::endl;
    head.popBack();
    head.showList();

    std::cout << "b, c, d, e 원소 삽입" << std::endl;
    head.pushFront('b');
    head.pushFront('c');
    head.pushFront('d');
    head.pushFront('e');
    head.showList();

    std::cout << "c 원소 다음 위치에 x 원소 삽입" << std::endl;
    node = head.findNode('c');
    head.pushMiddle(node, 'x');
    head.showList();

    std::cout << "c 원소 삭제" << std::endl;
    head.popMiddle(node);
    head.showList();

    std::cout << "리스트 비우기" << std::endl;
    head.clearList();
    head.showList();

	return 0;
}
