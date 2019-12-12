//
// Created by User on 11-12-2019.
//

#ifndef STUDENTEXAMRECORDSYSTEM_CHOICEHANDLER_H
#define STUDENTEXAMRECORDSYSTEM_CHOICEHANDLER_H

#endif //STUDENTEXAMRECORDSYSTEM_CHOICEHANDLER_H

#include <iostream>
#include"StudentRecord.h"
#include <string.h>
#include <dirent.h>
#include <windows.h>
using namespace std;

void displayAllStudentRecords(){
    DIR *dir;
    struct dirent *ent;
    char currentDirectry[260];
    GetCurrentDirectory(260,currentDirectry);
    strcat(currentDirectry,"\\data");
    if( (dir = opendir(currentDirectry)) != NULL){
        while((ent = readdir(dir)) != NULL){
            if(strcmp(ent->d_name, ".txt") == 1){
                cout << "Roll Number " << ent->d_name << ": \n";
                char name[250] = "";
                strcat(name,"data/");
                strcat(name,ent->d_name);
                ifstream fin;
                cout <<name<<endl;
                fin.open(name);
                if(!fin){
                    cout << "An error occurred\n";
                }else{
                    while(fin){
                        char c = fin.get();
                        cout << c;
                    }
                }
                cout<<endl;
                fin.close();
            }
        }
        closedir(dir);
    }else{
        cout << "An error occurred\n";
    }
}



void createANewStudentRecord(){
    cout << "Create A New Student Record\n";
    Student s;
    s.getNameInput();
    s.getRollNoInput();
    s.getStdInput();
    StudentRecord sr(s);
    sr.getMarksInput();
    sr.writeToFile();
    cout <<"Created Student Record Succesfully\n";
}

void readAStudentRecord(){
    int roll_no = 0;
    cout << "Enter a Roll Number\n";
    cin >> roll_no;
    ifstream fin;
    fin.open("data/"+to_string(roll_no) + ".txt");
    if(fin) {
        while (fin) {
            char c = fin.get();
            cout << c;
        }
    }else{
        cout << "Student Record Doesn't Exist\n";
    }
    fin.close();
}

void updateAStudentRecord(){
    int roll_no;
    cout <<"Enter the roll no\n";
    cin >> roll_no;
    ifstream fin;
    fin.open("data/"+to_string(roll_no)+".txt");
    if(fin){
        Student s;
        cout << "Opened File Successfuly\n";
        s.getNameInput();
        s.getRollNoInput();
        s.getStdInput();
        StudentRecord sr(s);
        sr.getMarksInput();
        sr.writeToFile();
        cout <<"Updated Record Successfuly\n";
    }else{
        cout << "Student Record Doesn't Exist\n";
    }
    fin.close();
}

void deleteAStudentRecord(){
    int roll_no;
    cout << "Enter roll no\n";
    cin>>roll_no;
    string s= "data/" + to_string(roll_no)+".txt";
    const char *c = s.c_str();
    int code = remove(c);
    if(code == 0)
        cout<<"Deleted Record Successfully\n";
    else
        cout << "Student Record doesn't exist";
}