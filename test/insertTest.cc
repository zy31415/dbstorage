//
// Created by Yang Zhang on 2021-06-19.
//

#include <gtest/gtest.h>

extern "C" {
#include "heapfile.h"
#include "data.h"
}

TEST(InsertTest, InsertOneRecord) {

    FILE * fp = hfOpen();

    Employee employee;

    employee.id = 1;
    strcpy(employee.name, "Yang Zhang");
    strcpy(employee.depart, "Engineering");
    employee.age = 40;
    employee.salary = 12000;

    hfInsert(fp, &employee);

}

TEST(InsertTest, InsertMultipleRecord) {

    FILE * fp = hfOpen();

    Employee employee;

    employee.id = 1;
    strcpy(employee.name, "Yang Zhang");
    strcpy(employee.depart, "Engineering");
    employee.age = 40;
    employee.salary = 12000;

    hfInsert(fp, &employee);

}