// This is the solution of the https://lexue.bit.edu.cn/mod/programming/submit.php?id=468902
// created by FUGUO using cursor 24.11.14
//
#include<stdio.h>

int dayOfWeek(int y, int m, int d) {
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    int day = (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    int result = (day + 5) % 7 + 1;
    if(result == 7) result = 0;
    return result;
};

int main() {
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
    printf("%d\n", dayOfWeek(year, month, day));
    return 0;
}
