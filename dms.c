#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int getGIS(char* filename, struct coordinate* a, struct coordinate* b) {
    printf("%s\n", filename);
    FILE* fp = fopen(filename, "r");
    int cur = 0;
    while (!feof(fp)) {
        fscanf(fp, "(%d%c, %d%c) (%d%c, %d%c) \n",
            &a[cur].longitude.dms, &a[cur].longitude.direction,
            &a[cur].latitude.dms, &a[cur].latitude.direction,
            &b[cur].longitude.dms, &b[cur].longitude.direction,
            &b[cur].latitude.dms, &b[cur].latitude.direction);
        cur++;
    }
    fclose(fp);
    return cur;
}

void setValues(struct coordinate* a, int cur) {
    for (int i = 0; i < cur; i++) {
        // set longitude's value
        int div = a[i].longitude.dms / 10000;
        int rest = a[i].longitude.dms % 10000;

        a[i].longitude.degree = div;
        a[i].longitude.minute = rest / 100;
        a[i].longitude.second = rest % 100;
        a[i].longitude.totalSec = a[i].longitude.degree * 3600 + a[i].longitude.minute * 60 + a[i].longitude.second;

        // set latitude's value
        div = a[i].latitude.dms / 10000;
        rest = a[i].latitude.dms % 10000;

        a[i].latitude.degree = div;
        a[i].latitude.minute = rest / 100;
        a[i].latitude.second = rest % 100;
        a[i].latitude.totalSec = a[i].latitude.degree * 3600 + a[i].latitude.minute * 60 + a[i].latitude.second;
    }
}
