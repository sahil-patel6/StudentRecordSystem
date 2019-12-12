//
// Created by User on 11-12-2019.
//

#ifndef STUDENTEXAMRECORDSYSTEM_STUDENTRECORD_H
#define STUDENTEXAMRECORDSYSTEM_STUDENTRECORD_H

#endif //STUDENTEXAMRECORDSYSTEM_STUDENTRECORD_H


#include <iostream>
using namespace std;
#include <fstream>
#include "Student.h"


class StudentRecord {
    Student s;
    float marksForEnglish, marksForLanguage2, marksForMaths, marksForChemistry, marksForPhysics, marksForBiologyORComputerScience;
    char grade;
    float totalMarks,percentage;
    int baseTotal;

    void calculateGrade(){
        if(percentage >= 85){
            grade = 'A';
        }else if (percentage < 85 && percentage >= 75 ){
            grade = 'B';
        }else if (percentage < 75 && percentage >= 65){
            grade = 'C';
        }else if (percentage < 65 && percentage >= 55){
            grade = 'D';
        }else if (percentage < 55 && percentage >= 45){
            grade = 'E';
        }else{
            grade = 'F';
        }
    }
public:
    StudentRecord(Student s1) {
        s = s1;
    }

    void getMarksInput() {
        cout << "Enter marks for English:\n";
        cin >> marksForEnglish;
        cout << "Enter marks for Lang II:\n";
        cin >> marksForLanguage2;
        cout << "Enter marks for Maths:\n";
        cin >> marksForMaths;
        cout << "Enter marks for Physics:\n";
        cin >> marksForPhysics;
        cout << "Enter marks for Chemistry:\n";
        cin >> marksForChemistry;
        cout << "Enter marks for Biology / Computer Science:\n";
        cin >> marksForBiologyORComputerScience;

        cout << "Enter the base total for each subject\n";
        cin >> baseTotal;
        totalMarks = marksForBiologyORComputerScience + marksForChemistry + marksForPhysics + marksForMaths +
                     marksForLanguage2 + marksForEnglish;
        percentage = (totalMarks/((float)baseTotal*6))*100;
        calculateGrade();
    }

    void writeToFile() {
        system("mkdir data");
        ofstream file;
        file.open("data/"+to_string(s.getRollNo()) + ".txt",ios::trunc);
        file << "Name : " + s.getName() + "\n";
        file << "Roll No: " + to_string(s.getRollNo()) + "\n";
        file << "Std : " + to_string(s.getStd()) + "\n";

        file << "Marks: \n";
        file << "English : " + to_string(marksForEnglish) + "\n";
        file << "Lang II : " + to_string(marksForLanguage2) + "\n";
        file << "Maths : " + to_string(marksForMaths) + "\n";
        file << "Physics : " + to_string(marksForPhysics) + "\n";
        file << "Chemistry : " + to_string(marksForChemistry) + "\n";
        file << "Biology / Computer Science : " + to_string(marksForBiologyORComputerScience) + "\n";

        file << "Total: " + to_string(totalMarks) + "\n";
        file << "Percentage : " + to_string(percentage) + "%\n";
        file << "Grade : ";
        file << grade;
        file << endl;

        file.close();
    }
};