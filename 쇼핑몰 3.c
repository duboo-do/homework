/*#include <stdio.h>
#define maxProduct 100

int main() {
    int ID[maxProduct]; //��ǰ ID
    int stockQuantity[maxProduct]; //���� ���
    int productSort; //��ǰ ����
    int quantityReceiv[maxProduct]; //�԰����
    int quantitySale[maxProduct]; //�Ǹż���
    int totalQuantity = 0;
    int i;
    int totalReceiv = 0; //��ü �԰����
    int totalSales = 0; //��ü �Ǹż���
    double salesRate;
    int maxSale = 0; //�ִ� �Ǹŷ���
    int minSale = 0; //�ּ� �Ǹŷ���
    int maxID = -1; //�ִ� �Ǹ�ID
    int minID = -1; //�ּ� �Ǹ�ID

    printf("��ǰ ���� �Է�: ");
    scanf_s("%d", &productSort);

    printf("��ǰ �� �԰���� �Է�: ");
    for (i = 0; i < productSort; i++) {
        scanf_s("%d", &quantityReceiv[i]);
        totalReceiv += quantityReceiv[i];
    }

    printf("��ǰ �� �Ǹż��� �Է�: ");
    for (i = 0; i < productSort; i++) {
        scanf_s("%d", &quantitySale[i]);
        totalSales += quantitySale[i];
    }

    printf("ID�Է�: ");
    scanf_s("%d", &ID[i]);

    for (i = 0; i < productSort; i++) {
        stockQuantity[i] = quantityReceiv[i] - quantitySale[i];
        totalQuantity += quantitySale[i];

        if (quantitySale[i] > maxSale) {
            maxSale = quantitySale[i];
            maxID = ID[i];
        }
        if (minID == -1 || quantitySale[i] < minSale) {
            minSale = quantitySale[i];
            minID = ID[i];
        }
    }

    printf("������: ");
    for (i = 0; i < productSort; i++) {
        printf("%d", stockQuantity[i]);
    }


    for (i = 0; i < productSort; i++) {
        printf("%d", stockQuantity[i]);
    }

    salesRate = ((double)totalSales / totalReceiv) * 100;


    printf("�� �Ǹŷ�: %d\n", totalQuantity);
    printf("�Ǹ��� %.2f%%\n", salesRate);



    printf("���� ���� �Ǹŵ� ��ǰ ID: %d, �Ǹŷ�: %d", maxID, maxSale);
    printf("���� ���� �Ǹŵ� ��ǰ ID: %d, �Ǹŷ�: %d", minID, minSale);

    for (i = 0; i < productSort; i++) {
        if (quantityReceiv[i] <= 2) {
            printf("���: ��ǰ ID %d��� ����, ���� ����: %d\n", ID[i], quantityReceiv[i]);
        }
    }
    return 0;
}*/

#include <stdio.h>
#define max_product 5
#define LOW_STOCK 2
#define MAX_NAME_LENGTH 30


void inputStock(int stock_in[]) {
    printf("��ü ��ǰ�� �԰����: ");
    for (int i = 0; i < max_product; i++) {
        scanf_s("%d", &stock_in[i]);
    }
}
void quantityReceiv(int stock_in[]) {
    int product_id, amount;
    printf("��ǰ ID (0-%d): ", max_product - 1);
    scanf_s("%d", &product_id);
    if (product_id >= 0 && product_id < max_product) {
        printf("�԰����: ");
        scanf_s("%d", &amount);
        stock_in[product_id] += amount;
    }
    else {
        printf("�߸��� ��ǰ ID�Դϴ�.\n");
    }
}
void inputSales(int stock_out[]) {
    printf("��ü ��ǰ�� �Ǹż��� �Է�: ");
    for (int i = 0; i < max_product; i++) {
        scanf_s("%d", &stock_out[i]);
    }
}

void quantitySales(int stock_out[]) {
    int product_id, amount;
    printf("��ǰ ID : ", max_product - 1);
    scanf_s("%d", &product_id);
    if (product_id >= 0 && product_id < max_product) {
        printf("�Ǹż���: ");
        scanf_s("%d", &amount);
        stock_out[product_id] += amount;
    }
    else {
        printf("�߸��� ��ǰ ID�Դϴ�.\n");
    }
}

void inputProductNames(char product_names[][MAX_NAME_LENGTH]) {
    for (int i = 1; i < max_product+1; i++) {
        printf("ID %d ��ǰ��: ", i);
        scanf("%s", product_names[i]);
    }
}

void currentProduct(int stock_in[], int stock_out[], char product_names[][MAX_NAME_LENGTH]) {
    printf("��ǰ ��Ȳ:\n");

    int total_sales = 0;
    int max_sales = -1, min_sales = 1000; // �ʱ� �� ����
    int max_id = -1, min_id = -1;

    for (int i = 0; i < max_product; i++) {
        int current_stock = stock_in[i] - stock_out[i];
        printf("��ǰ ID %d: ������ %d\n", i, current_stock);

        total_sales += stock_out[i];

        // �ִ�, �ּ� �Ǹŷ� ���
        if (stock_out[i] > max_sales) {
            max_sales = stock_out[i];
            max_id = i;
        }
        if (stock_out[i] < min_sales) {
            min_sales = stock_out[i];
            min_id = i;
        }

        // ��� ���� Ȯ��
        if (current_stock <= LOW_STOCK) {
            printf("��ǰ ID %d: ������(%d)\n", i, current_stock);
        }
    }

    float sales_rate = 0.0;
    int total_in = 0;
    for (int i = 0; i < max_product; i++) {
        total_in += stock_in[i];
    }

    if (total_in > 0) {
        sales_rate = ((float)total_sales / total_in) * 100;
    }

    printf("�� �Ǹŷ�: %d\n", total_sales);
    printf("�Ǹ���: %.2f%%\n", sales_rate);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", max_id, max_sales);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", min_id, min_sales);
}

int main() {
    /*int ID;
    int stock_in[max_product] =;
    int stock_out[max_product] =;
    int current_stock[max_product] =;
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
    }


    printf("ID �Է�: ");
    scanf_s("%d", &ID);

    if (ID >= 0 && ID < num_product) {
        printf("%d ID�� �ش��ϴ� ��ǰ�� ��� ����: %d\n", ID, current_stock[ID]);
    }
    else {
        printf("�߸��� ID�Դϴ�\n");
    }

    for (i = 0; i < num_product; i++) {
        printf("%d", current_stock[i]);
    }

    printf("�� �Ǹŷ�: %d\n", total_stock);

    if (total_in > 0) {
        total_per = ((float)total_out / total_in) * 100;
        printf("��ü �Ǹ���:%.2f%%\n", total_per);
    }

    printf("�ִ� �Ǹŷ� ��ǰ: ID %d, �Ǹŷ� %d\n", max_id + 1, max);
    printf("�ּ� �Ǹŷ� ��ǰ: ID %d, �Ǹŷ� %d\n", min_id + 1, min);
    for (i = 0; i < num_product; i++) {
        if (current_stock[i] <= 2) {
            printf("��ǰ ID %d: ������(%d)\n", i + 1, current_stock[i]);
        }
    }*/

    int stock_in[max_product] = { 0 };  // �ʱ� �԰� ����
    int stock_out[max_product] = { 0 }; // �ʱ� �Ǹ� ����
    char product_names[max_product][MAX_NAME_LENGTH]; // ��ǰ�� ����
    int choice;

    while (1) {
        printf("���ϴ� �޴��� �����ϼ���.\n");
        printf("1. �԰�\n2. �Ǹ�\n3. ��ǰ��Ȳ\n4. ��ǰ�� �Է�\n5. ����\n");
        printf("�Է�: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: // �԰�
            printf("1. ��ü ��ǰ �԰�\n2. ���� ��ǰ �԰�\n");
            scanf_s("%d", &choice);
            if (choice == 1) {
                inputStock(stock_in);
            }
            else if (choice == 2) {
                quantityReceiv(stock_in);
            }
            else {
                printf("�߸��� �����Դϴ�.\n");
            }
            break;

        case 2: // �Ǹ�
            printf("1. ��ü ��ǰ �Ǹ�\n2. ���� ��ǰ �Ǹ�\n");
            scanf_s("%d", &choice);
            if (choice == 1) {
                inputSales(stock_out);
            }
            else if (choice == 2) {
                quantitySales(stock_out);
            }
            else {
                printf("�߸��� �����Դϴ�.\n");
            }
            break;

        case 3: // ��ǰ��Ȳ
            currentProduct(stock_in, stock_out,product_names);
            break;

        case 4:// ��ǰ�� �Է�
            inputProductNames(product_names);
            break;

        case 5: // ����
            printf("���α׷��� �����մϴ�.\n");
            return 0;

        default:
            printf("�߸��� �����Դϴ�.\n");
            break;
        }
    }
}
