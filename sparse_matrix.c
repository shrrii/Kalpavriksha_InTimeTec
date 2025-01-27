#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void printSparseMatrix(int rows, int cols, Node* head) {
    Node* current = head;
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0; 
        }
    }
    while (current != NULL) {
        matrix[current->row][current->col] = current->value;
        current = current->next;
    }
    printf("[");
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
            if(j==0)
                printf("%d", matrix[i][j]);
            else
                printf(" %d", matrix[i][j]);
        }
        printf("]");
    }
    printf("]");
}
int isValidInteger(const char *str) {
    while (*str == ' ') str++;
    if (*str == '-') str++;
    if (*str == '\0') return 0;
    while (*str) { 
        if((*str)<'0' || (*str)>'9')  return 0;
        str++;
    }

    return 1; 
}
int readInput(int row, int col) {
    char buffer[100];
    int value = 0;

    printf("Enter value for element (%d, %d): ", row, col);
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n') {
            value = 0; 
        } else {
            buffer[strcspn(buffer, "\n")] = '\0';
            if (isValidInteger(buffer)) {
               value = atoi(buffer); 
            } else {
                value = 0; 
            }
        }
    }

    return value;
}
Node* parseInput(int rows, int cols) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = readInput(i, j);
            if (value != 0) {
                Node* newNode = createNode(i, j, value);
                if (head == NULL) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
    }

    return head;
}
int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    while (getchar() != '\n');
    if (rows <= 0 || cols <= 0) {
        printf("Rows and columns must be greater than zero.\n");
        return 1;
    }
    Node* head = parseInput(rows, cols);
    printf("\nSparse matrix:\n");
    printSparseMatrix(rows, cols, head);
    return 0;
}
