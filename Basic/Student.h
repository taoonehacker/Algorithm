//
// Created by Tao on 6/7/20.
//

#include <string>
#include <iostream>

#ifndef ALGORITHM_STUDENT_H
#define ALGORITHM_STUDENT_H

#endif //ALGORITHM_STUDENT_H

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return score != otherStudent.score ? this->score < otherStudent.score : this->name < otherStudent.name;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Student:" << student.name << " " << student.score << endl;
        return os;
    }
};
