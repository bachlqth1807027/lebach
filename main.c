#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct {
    char masinhvien[10];
    char name[30];
    char phonenumber[30];
} Student;

int themSinhVien(int count, int maxNumber, Student structstudent[]) {
    char a[10];
    for (int i = count; i < maxNumber; ++i) {
        printf("Vui lòng nhập mã sinh viên thứ %d: \n", i + 1);
        scanf("%s", structstudent[i].masinhvien);
        while (strlen(structstudent[i].masinhvien) != 5) {
            printf("Mã sinh viên không thể khác 5. Vui lòng nhập lại");
            printf("Vui lòng nhập mã sinh viên :\n");
            scanf("%s", structstudent[i].masinhvien);
        }
        printf("Vui lòng nhập tên của sinh viên thứ %d: \n", i + 1);
        fgetc(stdin);
        fgets(structstudent[i].name, 30, stdin);
        structstudent[i].name[strlen(structstudent[i].name) - 1] = '\000';
        printf("Vui lòng nhập số điện thọa của sinh viên thứ %d: \n", i + 1);
        scanf("%s", structstudent[i].phonenumber);
        printf("Nhập exit để dừng hoặc ấn Enter để tiếp tục.");
        fgetc(stdin);
        fgets(a, 10, stdin);
        if (strcmp(a, "exit\n") == 0) return count + 1;
    }
}

void hienthidanhsachSV(int count, Student structstudent[]) {
    printf("%-10s%-20s%-10s%-20s%-10s%-20s\n", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int i = 0; i < count; i++) {
        printf("%-8s%-20s%-10s%-20s%-10s%-20s\n", "", structstudent[i].masinhvien, "|",
               structstudent[i].name, "|", structstudent[i].phonenumber);
    }
}

void luudanhsachsinhvienrafile(Student structstudent[], int *p) {
    FILE *f = fopen("danhsachsinhvien.txt", "w+");
    fprintf(f, "%-10s%-20s%-10s%-20s%-10s%-20s\r\n", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int i = 0; i < *p; i++) {
        fprintf(f, "%-8s%-20s%-10s%-20s%-10s%-20s\n", "", structstudent[i].masinhvien, "|", structstudent[i].name, "|",
                structstudent[i].phonenumber);
    }
    fclose(f);
}

void docdanhsachsinvien() {
    FILE *f = fopen("danhsachsinhvien.txt", "r");
    printf("Đọc dữ liệu từ file\n");
    char buffer[255];
    while (fgets(buffer, 255, f) != NULL) {
        printf("%s", buffer);
    }
    fclose(f);
}

int main() {
    int *p;
    Student structstudent[10];
    int flag = 1;
    int count = 0;
    while (flag == 1) {
        printf("-----Bảng chọn-----\n");
        printf("1. Thêm mới sinh viên.\n");
        printf("2. Hiển thị danh sách sinh viên.\n");
        printf("3. Lưu danh sách sinh viên ra file.\n");
        printf("4. Đọc danh sách sinh viên từ file.\n");
        printf("5. Thoát chương trình.\n");
        printf("Vui lòng nhập lựa chon của bạn :\n");
        int luachon, n;
        scanf("%d", &luachon);
        switch (luachon) {
            case 1:
                if (*p == 10) {
                    printf("Danh sách sinh viên đã đầy!!!\n\n");
                    break;
                }
                count = themSinhVien(count, 10, structstudent);
                break;
            case 2:
                hienthidanhsachSV(count, structstudent);
                break;
            case 3:
                luudanhsachsinhvienrafile(count, structstudent);
                break;
            case 4:
                docdanhsachsinvien();
                break;
            case 5: {
                flag = 0;
                printf("Hẹn gặp lại lần sau");
                break;

            }
        }
    }
}

