//
// Created by User on 11-12-2019.
//

#ifndef STUDENTEXAMRECORDSYSTEM_STUDENT_H
#define STUDENTEXAMRECORDSYSTEM_STUDENT_H

#endif //STUDENTEXAMRECORDSYSTEM_STUDENT_H

#include <iostream>

using namespace std;

class Student {
    string name;
    int roll_no;
    int std;
public:
    void getNameInput() {
        cout << "Enter your name:\n";
        cin >> name;
    }

    void getRollNoInput() {
        cout << "Enter your roll no:\n";
        cin >> roll_no;
    }

    void getStdInput() {
        cout << "Enter you std that your studying in:(in number format)\n";
        cin >> std;
    }

    string getName() {
        return name;
    }

    int getRollNo() {
        return roll_no;
    }

    int getStd() {
        return std;
    }
};

