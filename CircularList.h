#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include <functional>
/**
 * The definition of Circular List Node and Circular List itself
 *
 */

template <class T>
struct Node {
    T data;
    Node* next;
    Node(T initData);
};

template <class T>
class CircularList {
public:
    CircularList();
    CircularList(const CircularList& circularList);
    CircularList(T data);
    ~CircularList();
    void add(T data);
    bool deleteItem(std::function<bool(const T&)> predicate);
    unsigned int length();
    bool isEmpty();
    T* find(std::function<bool(const T&)> predicate);
    unsigned short int countOf(std::function<bool(const T&)> predicate);
    T* toArray();
    CircularList<T>& operator=(const CircularList& circularList);
    template<class U>
    friend std::ostream& operator<<(std::ostream &out, const CircularList<U>& circularList);
private:
    Node<T>* head;
    Node<T>* tail;
};


#endif //CIRCULARLIST_H
