#include <stdio.h>
#define max_product 100

int main() {
    int ID;
    int stock_in[max_product];
    int stock_out[max_product];
    int current_stock[max_product];
    int num_product;
    int i;

    printf("��ǰ�� ���� �Է�: ");
    scanf_s("%d", &num_product);
    if (num_product >= max_product) {
        printf("��ǰ�Է� �Ұ���");
    }
    printf("��ǰ �� �԰���� �Է�: ");
    for (i = 0; i < num_product; i++) {
        scanf_s("%d", &stock_in[i]);
    }
    printf("��ǰ �� �Ǹż��� �Է�: ");
    for (i = 0; i < num_product; i++) {
        scanf_s("%d", &stock_out[i]);
    }
    for (i = 0; i < num_product; i++) {
        current_stock[i] = stock_in[i] - stock_out[i];
    }
    printf("ID �Է�: ");
    scanf_s("%d", &ID);
    if (ID >= 0 && ID < num_product) {
    printf("%d ID�� �ش��ϴ� ��ǰ�� ��� ����: %d\n",ID, current_stock[ID]);
    }
    else {
        printf("�߸��� ID�Դϴ�\n");
    }
    for(i=0;i<num_product;i++){
    printf("%d",current_stock[i]);
    }

    return 0;
}


