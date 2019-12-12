cmake_minimum_required(VERSION 3.14)
project(StudentExamRecordSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(StudentExamRecordSystem main.cpp choiceHandler.h StudentRecord.h Student.h)