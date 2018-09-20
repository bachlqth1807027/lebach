#include <stdio.h>

void hoandoi2so(int *conTroCuaC, int *conTroCuaD) {
    int bientam = *conTroCuaC;
    *conTroCuaC = *conTroCuaD;
    *conTroCuaD = bientam;
    printf("sau khi hoán đổi , tại hàm hoandoi2so\n");
    printf("giá trị tại vùng nhớ của con trỏ C là :%d\n", *conTroCuaC);
    printf("giá trị tại vùng nhớ của con trỏ D là :%d\n", *conTroCuaD);

}

int main() {
    int *conTroCuaC;
    int *conTroCuaD;
    int c = 20;
    int d = 30;
    conTroCuaC = &c;
    conTroCuaD = &d;
    printf("Số thứ nhất là : %d\n", c);
    printf("Số thứ hai là : %d\n", d);

    hoandoi2so(conTroCuaC, conTroCuaD);
    printf("Giá trị hai số C và D tại hàm main\n");
    printf("giá trị số thứ nhất sau khi hoán đổi là : %d\n", c);
    printf("giá trị số thứ hai sau khi hoán đổi là : %d\n", d);

    return 0;
}