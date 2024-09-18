#include <stdio.h>
#define max_product 100

int main() {
    int ID;
    int stock_in[max_product];
    int stock_out[max_product];
    int current_stock[max_product];
    int num_product;
    int i;
    int total_stock = 0;//��ü��� ���� 
    int total_in = 0;//��ü �԰� ����
    int total_out = 0;//��ü �Ǹ� ����
    float total_per;//��ü �Ǹ��� 
    int max_id = -1;//�ִ� �Ǹŷ� ID
    int min_id = -1;//�ּ� �Ǹŷ� ID
    int max = -1;//�ִ� �Ǹŷ�
    int min = 1000;//�ּ� �Ǹŷ�

    printf("��ǰ�� ���� �Է�: ");
    scanf_s("%d", &num_product);

    if (num_product > max_product || num_product <= 0) {//��ȿ�� �˻�
        printf("��ǰ�Է� �Ұ���\n");
        return 1;//���� �߻��� ����
    }
    printf("��ǰ �� �԰���� �Է�: ");
    for (i = 0; i < num_product; i++) {
        scanf_s("%d", &stock_in[i]);
        total_in += stock_in[i];//��ü �԰� ���� ����
    }

     printf("��ǰ �� �Ǹż��� �Է�: ");
     for (i = 0; i < num_product; i++) {
         scanf_s("%d", &stock_out[i]);
         total_out += stock_out[i];//��ü �Ǹ� ���� ����
     }
     for (i = 0; i < num_product; i++) {
            current_stock[i] = stock_in[i] - stock_out[i];
            total_stock += stock_out[i];
     

        if (stock_out[i] > max) {
            max = stock_out[i];
            max_id = i;
        }
        if (stock_out[i] < min) {
            min = stock_out[i];
            min_id = i;
        }
        if (current_stock[i] <= 2) {
            printf("��ǰ ID %d: ������(%d)\n", i+1, current_stock[i]);
        }
     }
   
  
    printf("ID �Է�: ");
    scanf_s("%d", &ID);

    if (ID >= 0 && ID < num_product) {
        printf("%d ID�� �ش��ϴ� ��ǰ�� ��� ����: %d\n", ID, current_stock[ID]);
    }
    else {
        printf("�߸��� ID�Դϴ�\n");
    }

    printf("�� �Ǹŷ�: %d\n", total_stock);

    if (total_in > 0) {
       /* if (total_out > total_in) {
            total_out = total_in;
        }*/
        total_per = ((float)total_out / total_in) * 100;
        printf("��ü �Ǹ���:%.2f%%\n", total_per);
    }

    printf("�ִ� �Ǹŷ� ��ǰ: ID %d, �Ǹŷ� %d\n", max_id+1, max);
    printf("�ּ� �Ǹŷ� ��ǰ: ID %d, �Ǹŷ� %d\n", min_id+1, min);

    return 0;
}