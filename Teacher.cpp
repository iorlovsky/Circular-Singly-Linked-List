#include <string>
#include <iostream>
#include "Teacher.h"

/**
 * Implementation of the Teacher class
 *
 */

Teacher::Teacher() = default;

Teacher::Teacher(
        std::string &initSurname,
        std::string &initDepartment,
        std::string &initDegree,
        std::string &initAcademicTitle,
        unsigned short int initScientificWorksCount
) {
    surname = initSurname;
    department = initDepartment;
    degree = initDegree;
    academicTitle = initAcademicTitle;
    scientificWorksCount = initScientificWorksCount;
}

std::string Teacher::getSurname(){
    return surname;
}

std::string Teacher::getDepartment() {
    return department;
}

std::string Teacher::getAcademicTitle(){
    return academicTitle;
}

std::ostream& operator<<(std::ostream &out, const Teacher& teacher) {
    out << teacher.surname << std::endl;
    return out;
}