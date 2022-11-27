#include <stdio.h>
#include <stdlib.h>
#include "dms.h"

// Manhattan 방식
void calMan(struct coordinate* a, struct coordinate* b, int cur) {
    char str[1000];
    int cnt = 0;

    for (int i = 0; i < cur; i++) {
        int longDif = a[i].longitude.totalSec - b[i].longitude.totalSec;
        int latiDif = a[i].latitude.totalSec - b[i].latitude.totalSec;
        int dist, degDif, minDif, secDif;

        cnt += sprintf(str + cnt, "(%03dd %02dm %02ds %c, %03dd %02dm %02ds %c) (%03dd %02dm %02ds %c, %03dd %02dm %02ds %c)",
            a[i].longitude.degree, a[i].longitude.minute, a[i].longitude.second, a[i].longitude.direction,
            a[i].latitude.degree, a[i].latitude.minute, a[i].latitude.second, a[i].latitude.direction,
            b[i].longitude.degree, b[i].longitude.minute, b[i].longitude.second, b[i].longitude.direction,
            b[i].latitude.degree, b[i].latitude.minute, b[i].latitude.second, b[i].latitude.direction);

        if (longDif < 0) {
            longDif = -longDif;
        }
        if (latiDif < 0) {
            latiDif = -latiDif;
        }
        /*
        degree 최댓값 = 180도
        second 단위로 변환 시, 648000이므로
        최댓값보다 클 경우, 360도 * 2에서 빼도록 함
        */
        if (longDif > 648000) {
            longDif = 648000 * 2 - longDif;
        }
        if (latiDif > 648000) {
            latiDif = 648000 * 2 - latiDif;
        }

        dist = longDif + latiDif;
        degDif = dist / 3600;
        minDif = (dist % 3600) / 60;
        secDif = dist % 60;

        cnt += sprintf(str + cnt, " %06d %03dd %02dm %02ds\n",
            dist, degDif, minDif, secDif);
    }
    cnt += sprintf(str + cnt, "\0");

    printf(str);
}
