cmake_minimum_required(VERSION 3.9)
project(.)

set(CMAKE_CXX_STANDARD 14)

add_executable(. main.cpp DoublyLinkedList.h DoublyLinkedListIterator.h DoubleLinkedNode.h ReverseDoublyLinkedListIterator.h)