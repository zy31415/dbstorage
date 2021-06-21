#include <strings.h>
#include <printf.h>

#include "page.h"
#include "data.h"

/**
 * Use the last byte as a bit map to track if each row has value.
 * @param page
 * @return
 */
bool isPageFull(Page *page, int *pos) {

    unsigned char bm = page->data[BitMapIndex];

    printf("bit map: %d", bm);

    int n = 0;
    while ((bm != 0) && (bm & 1)) {
        bm >>= 1;
        n ++;
    }

    if (n >= MaxNumOfRecordsPerPage) {
        return true;
    } else {
        *pos = n;
        return false;
    }
}



int pgInsert(Page *page, Employee *employee, int pos) {

    if (pos >= MaxNumOfRecordsPerPage) {
        return -1;
    }

    char *p= &((page->data)[DataSectionStart + (RecordSize * pos)]);
    memcpy(p, employee, RecordSize);

    (page->data)[BitMapIndex] |= ( 1 << pos);

    return 1;
}

long getPageId(Page *page) {
    long l;
    memcpy(&l, page, sizeof(long));
    return l;
}