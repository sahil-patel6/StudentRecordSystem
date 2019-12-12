#include <iostream>
#include "choiceHandler.h"
using namespace std;


void startTheProgram(){
    int c;
    cout << "Enter any of the following choices:\n1 - Display All Student Record\n2 - Add A New Student Record\n3 - Read A Student Record\n4 - Update A Student Record\n5 - Delete A Student Record\n6 - Quit The Program\n";
    cin>>c;
    switch (c){
        case 1:
            displayAllStudentRecords();
            startTheProgram();
            break;
        case 2:
            createANewStudentRecord();
            startTheProgram();
            break;
        case 3:
            readAStudentRecord();
            startTheProgram();
            break;
        case 4:
            updateAStudentRecord();
            startTheProgram();
            break;
        case 5:
            deleteAStudentRecord();
            startTheProgram();
            break;
        case 6:
            cout << "Quitting the program\n";
            exit(0);
        default:
            cout << "Invalid Choice\n";
            startTheProgram();
    }
}

int main() {
    startTheProgram();
    return 0;
}
