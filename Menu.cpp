#include <iostream>
#include "CircularList.h"
#include "CircularList.cpp"
#include "Teacher.h"

template <class T>
void checkIfListEmpty(CircularList<T>* list) {
    if (list->isEmpty()) {
        printf("The list is empty \n");
    } else {
        printf("The list has %i item(s)\n", list->length());
    }
}

template <class T>
void printList(CircularList<T>* list) {
    std::cout << "The list:" << std::endl;
    std::cout << *list << std::endl;
}

template <class T>
void deleteFromList(CircularList<T>* list) {
    std::string surname;
    printf("Input the surname of teacher to be deleted: \n");
    std::cin >> surname;
    const bool isDeleted = list->deleteItem([=](Teacher value) { return value.getSurname() == surname;});
    if (isDeleted) {
        printf("Successfully deleted \n");
    } else {
        printf("No such teacher \n");
    }
}

Teacher getValueToCreateListWith() noexcept(false) {
    std::string surname;
    std::string department;
    std::string degree;
    std::string academicTitle;
    unsigned short int scientificWorksCount;
    printf("Creating a new Teacher object \n");
    printf("Input the surname: \n");
    std::cin >> surname;
    printf("Input the department: \n");
    std::cin >> department;
    printf("Input the degree: \n");
    std::cin >> degree;
    printf("Input the academic title: \n");
    std::cin >> academicTitle;
    printf("Input the count of scientific works: \n");
    std::cin >> scientificWorksCount;
    if (std::cin.fail()) {
        throw std::runtime_error("Incorrect input. Bye! \n");
    }
    Teacher teacher(surname, department, degree, academicTitle, scientificWorksCount);
    return teacher;
}

template <class T>
void addToList(CircularList<T>* list)  {
    list->add(getValueToCreateListWith());
    printf("Successfully added \n");
}

template <class T>
void printReport(CircularList<T>* list) {
    Teacher *allTeachers = list->toArray();
    auto *uniqDepartments = new std::string[list->length()];
    unsigned short int uniqDepartmentsIdx = 0;
    for (int i = 0; i < list->length(); i++) {
        bool isDepartmentChecked = false;
        for (int j = 0; j < list->length(); j++) {
            if (uniqDepartments[j] == allTeachers[i].getDepartment()) {
                isDepartmentChecked = true;
            }
        }
        if (!isDepartmentChecked) {
            uniqDepartments[uniqDepartmentsIdx++] = allTeachers[i].getDepartment();
        }
    }
    for (int i = 0; i < uniqDepartmentsIdx; i++) {
        unsigned short int count = list->countOf([=](Teacher value) {
            return value.getDepartment() == uniqDepartments[i] && !value.getAcademicTitle().empty();
        });
        printf("Department %s has %i teacher(s)\n", uniqDepartments[i].c_str(), count);
    }
}

void menu() {
    unsigned short int currentItem = 0;
    unsigned short int level = 1;
    CircularList<Teacher>* list = NULL;
    do {
        if (level == 1) {
            printf("Select action: \n\n");
            printf("1. Create empty list \n");
            printf("2. Create list with start value \n");
            std::cin >> currentItem;
            switch (currentItem) {
                case 1:
                    list = new CircularList<Teacher>();
                    printf("An empty list has been created  \n");
                    break;
                case 2:
                    try{
                        list = new CircularList<Teacher>(getValueToCreateListWith());
                    } catch (std::runtime_error& e){
                        std::cerr << e.what();
                        return;
                    }
                    break;
                default:
                    printf("No such action \n");
                    break;
            }
            level = 2;
        } else if (list != NULL){
            currentItem = 0;
            printf("Select action: \n\n");
            printf("1. Add item to the list \n");
            printf("2. Delete item from the list \n");
            printf("3. Check if the list is empty \n");
            printf("4. Print the list \n");
            printf("5. Report by department \n");
            std::cin >> currentItem;
            switch (currentItem) {
                case 1:
                    try {
                        addToList(list);
                    } catch (std::runtime_error& e){
                        std::cerr << e.what();
                        return;
                    }
                    break;
                case 2:
                    deleteFromList(list);
                    break;
                case 3:
                    checkIfListEmpty(list);
                    break;
                case 4:
                    printList(list);
                    break;
                case 5:
                    if (!list->isEmpty()) {
                        printReport(list);
                    } else {
                        printf("The list is empty\n");
                    }
                    break;
                default:
                    printf("No such action \n");
                    break;
            }
            printf("Continue? (1 - yes, 0 - no)\n");
            std::cin >> currentItem;
            if (std::cin.fail()) {
                printf("Incorrect input. Bye! \n");
                return;
            }
        } else {
            return;
        }
    } while (currentItem);
}

