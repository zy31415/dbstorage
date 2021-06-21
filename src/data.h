//
// Created by Yang Zhang on 2021-06-19.
//

#ifndef DBSTORAGE_DATA_H
#define DBSTORAGE_DATA_H

typedef struct Employee {
    unsigned long id;
    char name[30];
    char depart[30];
    unsigned int age;
    double salary;
} Employee;

#define RecordSize sizeof(Employee)

#endif //DBSTORAGE_DATA_H
