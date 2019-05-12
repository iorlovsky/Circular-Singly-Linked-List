#include <iostream>
#include "CircularList.h"
//#include "Teacher.h"


/**
 * Implementation of Circular List Node
 *
 */


/**
 * Default constructor
 *
 * @tparam T - type of Node data
 */
template <class T>
Node<T>::Node(T initData) {
    data = initData;
    next = NULL;
}


/**
 * Implementation of Circular List
 *
 */


/**
 * Default constructor
 *
 * @tparam T - Node type
 */
template <class T>
CircularList<T>::CircularList() {
    head = NULL;
    tail = NULL;
}

/**
 * Copy constructor
 *
 * @tparam T - Node type
 * @param circularList - the list to create a new one from
 */
template <class T>
CircularList<T>::CircularList(const CircularList& circularList) {
    tail = NULL;
    head = NULL;
    Node<T>* current = circularList.head;
    while(current->next != circularList.head) {
        add(current->data);
        current = current->next;
    }
    add(circularList.tail->data);
}

/**
 * Conversion constructor
 *
 * @tparam T - Node type
 * @param data - value to create a list from
 */
template <class T>
CircularList<T>::CircularList(T data) {
    tail = NULL;
    head = NULL;
    add(data);
}

/**
 * Destructor
 *
 * @tparam T - Node type
 */
template <class T>
CircularList<T>::~CircularList() {
    if(head == NULL) {
        return;
    }
    Node<T> * tmp = head;
    while (tmp->next != head)
    {
        Node<T> * t = tmp;
        tmp = tmp->next;
        delete(t);
    }
    delete tmp;
    head = NULL;
}

/**
 * Add data to the list
 *
 * @tparam T - Node type
 * @param data - value to add
 */
template <class T>
void CircularList<T>::add(T data) {
    auto* newNode = new Node<T>(data);
    if(isEmpty()) {
        newNode->next = newNode;
        head = newNode;
        tail = head;
        return;
    }
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

/**
 * Delete element from the list.
 *
 * @tparam T - Node type
 * @param predicate - the function is invoked for each node. Returns "true" - if should be deleted, "false" if not
 * @return "true" if value was successfully deleted from the list; "false" - if not found
 */
template <class T>
bool CircularList<T>::deleteItem(std::function<bool(const T&)> predicate) {
    if (isEmpty()) {
        return false;
    }
    Node<T>* current = head;
    Node<T>* prev = tail;
    bool isFound = false;
    while (current->next != head) {
        if (predicate(current->data)) {
            isFound = true;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (isFound) {
        if (current == head) {
            tail->next = head->next;
            head = head->next;
        } else {
            prev->next = current->next;
            delete current;
        }
        return true;
    } else if (head->next == head && predicate(head->data)) {
        head = NULL;
        tail = NULL;
        return true;
    } else if (predicate(tail->data)) {
        delete tail;
        prev->next = head;
        tail = prev;
        return true;
    }
    return false;
}

/**
 * Find a node in the list;
 *
 * @tparam T - Node type
 * @param predicate - the function is invoked for each node. Returns "true" - if should be returned, "false" if not
 * @return an array of found nodes
 */
template <class T>
T* CircularList<T>::find(std::function<bool(const T&)> predicate) {
    Node<T>* current = head;
    T *tmpResult = new T[length()];
    unsigned short int idx = 0;
    unsigned short int count = 0;
    while (current->next != head) {
        if (predicate(current->data)) {
            tmpResult[idx++] = current->data;
            count++;
        }
        current = current->next;
    }
    if (predicate(tail->data)) {
        tmpResult[idx] = tail->data;
        count++;
    }
    if (!count) {
        return NULL;
    }
    T *result = new T[count];
    for (int i = 0; i < count; i++) {
        result[i] = tmpResult[i];
    }
    return result;
}

/**
 * Get count of nodes in the list by condition
 *
 *
 * @tparam T - Node type
 * @param predicate - the function is invoked for each node to check if it meet the predicate condition
 * @return count of found nodes
 */
template <class T>
unsigned short int CircularList<T>::countOf(std::function<bool(const T &)> predicate){
    Node<T>* current = head;
    unsigned short int count = 0;
    while (current->next != head) {
        if (predicate(current->data)) {
            count++;
        }
        current = current->next;
    }
    if (predicate(tail->data)) {
        count++;
    }
    return count;
}


/**
 * Convert list to array
 *
 * @tparam T - Node type
 * @return an array of nodes in the list
 */
template <class T>
T* CircularList<T>::toArray(){
    if (isEmpty()) {
        return NULL;
    }
    Node<T>* current = head;
    T *result = new T[length()];
    int idx = 0;
    while (current->next != head) {
        result[idx++] = current->data;
        current = current->next;
    }
    result[idx] = tail->data;
    return result;
}

/**
 * Get length of the list
 *
 * @tparam T - Node type
 * @return count of nodes in the list
 */
template <class T>
unsigned int CircularList<T>::length() {
    unsigned int count = 1;
    if (isEmpty()) {
        return 0;
    }
    Node<T>* current = head;
    while(current->next != head) {
        current = current->next;
        count++;
    }
    return count;
}

/**
 * Check if the list is empty
 *
 * @tparam T - Node type
 * @return "true" if the list is empty; "false" - if the list has at least one node
 */
template <class T>
bool CircularList<T>::isEmpty() {
    return head == NULL;
}


/**
 * The assignment operator overloading
 *
 * @tparam T - Node type
 * @param circularList - A list to assign from
 * @return the address of an assigned list
 */
template <class T>
CircularList<T>& CircularList<T>::operator=(const CircularList& circularList) {
    head = NULL;
    tail = NULL;
    Node<T>* current = circularList.head;
    while(current->next != circularList.head) {
        add(current->data);
        current = current->next;
    }
    add(circularList.tail->data);
    return *this;
}

/**
 * The output operator overloading.
 * This overloading only works with Circular List with Teacher as a data
 *
 * @param out - out stream
 * @param circularList - a circular list to output
 * @return ostream
 */
template <class T>
std::ostream& operator<<(std::ostream &out, const CircularList<T>& circularList) {
    Node<T>* current = circularList.head;
    if (current == NULL) {
        out << "\n";
        return out;
    }
    while(current->next != circularList.head) {
        out << current->data << "\n";
        current = current->next;
    }
    out << circularList.tail->data;
    return out;
}