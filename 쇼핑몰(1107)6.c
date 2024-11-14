#include <stdio.h>
#include <string.h>

#define max_product 5
#define MAX_NAME_LENGTH 30
#define FILENAME "products.txt"  // 상품 정보 저장 파일

// 상품 정보를 저장할 구조체 정의
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int price;
    int stock_in;  // 입고량
    int stock_out; // 판매량
    int total_sales; // 총 판매 금액
} Product;

Product products[max_product];  // 상품 배열
int productCount = 0;

// 파일에서 상품 정보 읽기
void readFile() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("저장된 상품 정보가 없습니다.\n");
        return;
    }

    while (fscanf(file, "%d %s %d %d %d %d\n", 
                    &products[productCount].id, 
                    products[productCount].name, 
                    &products[productCount].price, 
                    &products[productCount].stock_in, 
                    &products[productCount].stock_out, 
                    &products[productCount].total_sales) ==6) {
        productCount++;
        if (productCount >= max_product) break;  // 최대 상품 개수 제한
    }
    fclose(file);
}

// 파일에 상품 저장
void saveFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", 
                products[i].id, 
                products[i].name, 
                products[i].price, 
                products[i].stock_in, 
                products[i].stock_out, 
                products[i].total_sales);
    }

    fclose(file);
}


void inputStock() {
    int id, stock, price;
    char name[MAX_NAME_LENGTH];

    printf("상품 ID : ");
    scanf("%d", &id);
    getchar();  

 
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("상품이 이미 존재합니다. 상품 정보를 업데이트합니다.\n");
            printf("입고량 : ");
            scanf("%d", &stock);
            products[i].stock_in += stock; 
            printf("판매가격 : ");
            scanf("%d", &price);
            products[i].price = price;  // 가격 업데이트
            saveFile();  // 변경 저장
            return;
        }
    }

    // 배열 5 이상 추가 안됐을시 상품 추가 
    if (productCount < max_product) {
        // 새 상품 추가
        products[productCount].id = id;
        printf("상품명 : ");
        fgets(products[productCount].name, MAX_NAME_LENGTH, stdin);
        
        size_t len = strlen(products[productCount].name);
        if (len > 0 && products[productCount].name[len - 1] == '\n') {
            products[productCount].name[len - 1] = '\0'; 
        }
        
        printf("입고량 : ");
        scanf("%d", &stock);
        printf("판매가격 : ");
        scanf("%d", &price);
        
        products[productCount].stock_in = stock;
        products[productCount].price = price;
        products[productCount].stock_out = 0;
        products[productCount].total_sales = 0;

        productCount++;  // 상품 수 증가
        saveFile();  // 변경 정보 저장
    } else {
        printf("상품 갯수가 최대치인 5개를 초과할 수 없습니다.\n");
    }
}


void inputSales() {
    int id, quantity;
    
    printf("상품 ID : ");
    scanf("%d", &id);
    
    // 상품이 있는지 확인
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("판매량 : ");
            scanf("%d", &quantity);
            
            
            if (quantity > products[i].stock_in - products[i].stock_out) {
                printf("판매량이 재고를 초과합니다. 다시 입력해주세요.\n");
            } else {
                products[i].stock_out += quantity;
                products[i].total_sales += products[i].price * quantity;
                printf("상품 판매가 완료되었습니다.\n");
                saveFile();
            }
            break;
        }
    }
    if (!found) {
        printf("상품 ID가 존재하지 않습니다.\n");
    }
}


void indiviProduct() {
    int id;
    printf("상품 ID : ");
    scanf("%d", &id);

    // 상품이 있는지 확인
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("상품명: %s\n", products[i].name);
            printf("판매가격: %d\n", products[i].price);
            printf("입고량: %d\n", products[i].stock_in);
            printf("판매량: %d\n", products[i].stock_out);
            printf("총판매금액: %d\n", products[i].total_sales);
            break;
        }
    }

    if (!found) {
        printf("상품 ID가 존재하지 않습니다.\n");
    }
}

// 전체 상품 정보 출력
void allProduct() {
    if (productCount == 0) {
        printf("등록된 상품이 없습니다.\n");
        return;
    }

    int totalProduct = 0; //전체 입고량
    int totalSales = 0; //전체 총 판매금액
    int totalSold = 0; //전체 판매량
    int minSales = 1000000; //최소 판매량
    int maxSales = -1;         //최대 판매량
    int minId = -1, maxId = -1; //최소,최대 판매량 상품 ID
    char minName[MAX_NAME_LENGTH], maxName[MAX_NAME_LENGTH]; //최소,최대 판매량 상품명
    int shortageStock = 0; //재고 부족 상품 개수


    for (int i = 0; i < productCount; i++) {
        // 전체 입고량, 판매량 누적
        totalProduct += products[i].stock_in;
        totalSales += products[i].total_sales;
        totalSold += products[i].stock_out;

        // 판매량이 최소,최대 확인
        if (products[i].stock_out > maxSales) {
            maxSales = products[i].stock_out;
            maxId = products[i].id;
            strcpy(maxName, products[i].name);
        }
        if (products[i].stock_out < minSales) {
            minSales = products[i].stock_out;
            minId = products[i].id;
            strcpy(minName, products[i].name);
        }

        int currentStock = products[i].stock_in - products[i].stock_out;
        if (currentStock <= 2 && currentStock >= 0) {
            shortageStock++;
        }
    }

    
    double saleRate = 0.0;
    if (totalProduct > 0) {
        saleRate = ((double)totalSold / totalProduct) * 100;
    }

    
    printf("총 판매량 : %d (판매율 %.2lf%%)\n", totalSold, saleRate);

    
    printf("가장 많이 판매된 상품 : ID %d, 상품명: %s, 판매량 %d\n", maxId, maxName, maxSales);
    printf("가장 적게 판매된 상품 : ID %d, 상품명: %s, 판매량 %d\n", minId, minName, minSales);

    // 재고 부족 상품 출력
    if (shortageStock > 0) {
        for (int i = 0; i < productCount; i++) {
            int currentStock = products[i].stock_in - products[i].stock_out;
            if (currentStock <= 2 && currentStock >= 0) {
                printf("상품 ID %d : 재고부족(%d)\n", products[i].id, currentStock);
            }
        }
    }
}

int main() {
    int choice;

    // 파일에서 데이터 읽기
    readFile();

    while (1) {
        printf("원하는 메뉴를 선택하세요.\n");
        printf("1. 입고\n2. 판매\n3. 개별현황\n4. 전체현황\n5. 종료\n");
        printf("입력: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
        case 1: 
            inputStock();
            break;
        case 2:  
            inputSales();
            break;
        case 3: 
            indiviProduct();
            break;
        case 4: 
            allProduct();
            break;
        case 5:  
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }

    return 0;
}
