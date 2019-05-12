#ifndef MENU_H
#define MENU_H

/**
 * This is the definition of UI functions which are supposed
 * to demonstrate how the Circular List works with the Teacher class
 *
 */

template <class T>
void addToList(CircularList<T>* list);
template <class T>
void checkIfListEmpty(CircularList<T>* list);
template <class T>
void printList(CircularList<T>* list);
template <class T>
void deleteFromList(CircularList<T>* list);
template <class T>
void printReport(CircularList<T>* list);
int getValueToCreateListWith() noexcept(false);
void menu();

#endif //MENU_H
