#include <stdio.h>
#include <unistd.h>
#include <strings.h>

#include "heapfile.h"
#include "page.h"

FILE * hfOpen() {
    if ( access(DbFile, F_OK) == 0 ) {
        return fopen(DbFile, "rb+");
    } else {
        return fopen(DbFile, "wb+");
    }
}


void hfAppendPage(FILE *fp, long pageID, Page *page) {
    for (int i = 0; i < PageSize; i++) {
        page->data[i] = 0;
    }

    // Set page ID:
    memcpy(page, &pageID, sizeof(long));

    fwrite(page, PageSize, 1, fp);
}

size_t hfNextPage(FILE *fp, Page *page) {
    return fread(page, PageSize, 1, fp);
}

void hfNextPageOrAppend(FILE *fp, long pageID, Page *page) {
    if (hfNextPage(fp, page) != 1) {
        hfAppendPage(fp, pageID, page);
    }
}

size_t savePage(FILE *fp, Page *page) {
    long pageID = getPageId(page);
    fseek(fp, pageID * PageSize, SEEK_SET);
    return fwrite(page, PageSize, 1, fp);
}

int hfInsert(FILE *fp, Employee *employee) {
    Page page;

    long pageID = 0l;

    hfNextPageOrAppend(fp, pageID, &page);

    int insertPos = -1;
    while(isPageFull(&page, &insertPos)) {
        pageID ++;
        hfNextPageOrAppend(fp, pageID, &page);
    }

    pgInsert(&page, employee, insertPos);

    savePage(fp, &page);

    return 1;
}

int hfInsertMultiple(FILE *fp, Employee *employee) {
    Page page;

    long pageID = 0l;

    hfNextPageOrAppend(fp, pageID, &page);

    int insertPos = -1;
    while(isPageFull(&page, &insertPos)) {
        pageID ++;
        hfNextPageOrAppend(fp, pageID, &page);
    }

    pgInsert(&page, employee, insertPos);

    savePage(fp, &page);

    return 1;
}