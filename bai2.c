#include <stdio.h>

struct UserAccount {
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
    int fee;
};

int main() {
    struct UserAccount user[100];
    int n, i, downgraded = 0, total = 0;

    do {
        printf("Nhap so tai khoan: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    for (i = 0; i < n; i++) {
        printf("\nTai khoan %d\n", i + 1);

        printf("Ma TK: ");
        scanf("%d", &user[i].user_id);

        printf("Ten TK: ");
        scanf("%49s", user[i].username);

        do {
            printf("Ma goi (1-Free, 2-Personal, 3-Family): ");
            scanf("%d", &user[i].plan_type);
        } while (user[i].plan_type < 1 || user[i].plan_type > 3);

        do {
            printf("So ngay no: ");
            scanf("%d", &user[i].days_overdue);
        } while (user[i].days_overdue < 0);

        do {
            printf("So thiet bi: ");
            scanf("%d", &user[i].active_devices);
        } while (user[i].active_devices < 0);

        if (user[i].days_overdue >= 3) {
            user[i].plan_type = 1;
            user[i].fee = 0;
            downgraded++;
        } else {
            if (user[i].plan_type == 1)
                user[i].fee = 0;
            else if (user[i].plan_type == 2)
                user[i].fee = 120000;
            else
                user[i].fee = 250000;

            if (user[i].plan_type == 2 && user[i].active_devices > 1)
                user[i].fee += (user[i].active_devices - 1) * 30000;
        }

        total += user[i].fee;
    }

    printf("\n%-8s %-15s %-8s %-10s %-10s %-15s\n",
           "Ma TK", "Ten TK", "Ma Goi", "Thiet Bi", "No Ngay", "Phi Thuc Thu");

    for (i = 0; i < n; i++) {
        printf("%-8d %-15s %-8d %-10d %-10d %-15d\n",
               user[i].user_id,
               user[i].username,
               user[i].plan_type,
               user[i].active_devices,
               user[i].days_overdue,
               user[i].fee);
    }

    printf("\nTong doanh thu: %d VND\n", total);
    printf("So tai khoan bi ha cap: %d\n", downgraded);

    return 0;
}