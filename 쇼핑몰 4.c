#include <stdio.h>
#define maxProduct 100
//#define LOW_STOCK 2
#define MAX_NAME_LENGTH 30

int productSort;
int quantityReceiv[maxProduct];
int i;


void inputStock(int stock_in[]) { //전체상품 입고
    printf("전체 상품의 입고수량: ");
    for (i = 0; i < productSort; i++) {
        scanf("%d", &quantityReceiv[i]);
    }
}
void quantityRe(int stock_in[]) { //개별상품 입고
    int ID, amount;
    printf("상품 ID : ");
    scanf("%d", &ID);
    if (ID >= 0 && ID < productSort) {
        printf("입고수량: ");
        scanf("%d", &amount);
        stock_in += amount;
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }
}
void inputSales(int stock_out[]) { //전체 판매수량
    printf("전체 상품의 판매수량 입력: ");
    for (int i = 0; i < productSort; i++) {
        scanf("%d", &stock_out[i]);
    }
}

void quantitySales(int stock_out[]) { //개별 판매수량
    int product_id, amount;
    printf("상품 ID : ");
    scanf("%d", &product_id);
    if (product_id >= 0 && product_id < productSort) {
        printf("판매수량: ");
        scanf("%d", &amount);
        stock_out[product_id] += amount;
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }
}

void currentProduct(int stock_in[], int stock_out[], char product_names[][MAX_NAME_LENGTH]) { //상품명
    printf("상품 현황:\n");

    int totalSales = 0;
    int maxSales = -1, minSales = 1000; // 초기 값 설정
    int maxId = -1, minId = -1;
    int Id[maxProduct];
    

    for (int i = 0; i < productSort; i++) {
        int stockQuantity[maxProduct] = stock_in[i] - stock_out[i];
        printf("상품 ID %d: 재고수량 %d\n", i, stockQuantity[i]);
    
        totalSales += stock_out[i];

        // 최대, 최소 판매량 계산
        if (stock_out[i] > maxSales) {
            maxSales = stock_out[i];
            maxId = i;
        }
        if (stock_out[i] < minSales) {
            minSales = stock_out[i];
            minId = i;
        }

        // 재고 부족 확인
        for (i = 0; i < productSort; i++) {
        if (quantityReceiv[i] <= 2) {
            printf("경고: 상품 ID %d재고가 부족, 남은 수량: %d\n", Id[i], quantityReceiv[i]);
        }
      }
    }

    double saleRate = 0.0; //판매율
    int total_in = 0;
    for (int i = 0; i < productSort; i++) {
        total_in += stock_in[i];
    }

    if (total_in > 0) {
        saleRate = ((double)totalSales / total_in) * 100;
    }

    printf("총 판매량: %d\n", totalSales);
    printf("판매율: %.2f%%\n", saleRate);
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxId, maxSales);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minId, minSales);
}

void inputProductNames(char product_names[][MAX_NAME_LENGTH]) { //상품명
    for (int i = 0; i < productSort; i++) {
        printf("ID %d 상품명: ", i);
        scanf("%s", product_names[i]);
    }
}

int main() {
    int stock_in[maxProduct] = { 0 };  // 초기 입고 수량
    int stock_out[maxProduct] = { 0 }; // 초기 판매 수량
    char product_names[maxProduct][MAX_NAME_LENGTH]; // 상품명 저장
    int choice;

    while (1) {
        printf("원하는 메뉴를 선택하세요.\n");
        printf("1. 입고\n2. 판매\n3. 상품현황\n4. 상품명 입력\n5. 종료\n");
        printf("입력: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // 입고
            printf("1. 전체 상품 입고\n2. 개별 상품 입고\n");
            scanf("%d", &choice);
            if (choice == 1) {
                inputStock(stock_in);
            }
            else if (choice == 2) {
                quantityRe(stock_in);
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
            break;

        case 2: // 판매
            printf("1. 전체 상품 판매\n2. 개별 상품 판매\n");
            scanf("%d", &choice);
            if (choice == 1) {
                inputSales(stock_out);
            }
            else if (choice == 2) {
                quantitySales(stock_out);
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
            break;

        case 3: // 상품현황
            currentProduct(stock_in, stock_out,product_names);
            break;

        case 4:// 상품명 입력
            inputProductNames(product_names);
            break;

        case 5: // 종료
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }
}
