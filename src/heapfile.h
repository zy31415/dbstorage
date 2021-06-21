//
// Created by Yang Zhang on 2021-06-19.
//

#ifndef DBSTORAGE_HEAPFILE_H
#define DBSTORAGE_HEAPFILE_H

#include "data.h"

#define DbFile "storage.db"

FILE * hfOpen();
int hfInsert(FILE *fp, Employee *employee);

#endif //DBSTORAGE_HEAPFILE_H
