#ifndef TEACHER_H
#define TEACHER_H

#include <string>

/**
 * The definition of Teacher class.
 * It's a class to demonstrate how the Circular List works with different data types.
 */
class Teacher {
public:
    Teacher();
    Teacher(
            std::string& initSurname,
            std::string& initDepartment,
            std::string& initDegree,
            std::string& initAcademicTitle,
            unsigned short int initScientificWorksCount
    );
    std::string getSurname();
    std::string getDepartment();
    std::string getAcademicTitle();
    friend std::ostream& operator<<(std::ostream &out, const Teacher& teacher);
private:
    std::string surname;
    std::string department;
    std::string degree;
    std::string academicTitle;
    unsigned short int scientificWorksCount;
};


#endif //TEACHER_H
