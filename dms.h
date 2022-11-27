#ifndef _DMS_H_
#define _DMS_H_
struct geoinfo {
    int degree;
    int minute;
    int second;
    int totalSec;
    int dms;
    char direction;
};

struct coordinate {
    struct geoinfo longitude;
    struct geoinfo latitude;
};

int getGIS(char* filename, struct coordinate* a, struct coordinate* b);

void setValues(struct coordinate* a, int cur);
#endif
