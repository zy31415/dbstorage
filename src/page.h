#ifndef DBSTORAGE_PAGE_H
#define DBSTORAGE_PAGE_H

#include <stdbool.h>
#include "data.h"

#define PageSize 1024

#define HeaderSectionStart  0
#define HeaderSectionTo 100
#define DataSectionStart 100
#define BitMapIndex PageSize - 1

#define MaxNumOfRecordsPerPage 8

typedef struct Page {
    char data[PageSize];
} Page;

bool isPageFull(Page *page, int * pos);


int pgInsert(Page *page, Employee *employee, int pos);


long getPageId(Page *page);


#endif //DBSTORAGE_PAGE_H