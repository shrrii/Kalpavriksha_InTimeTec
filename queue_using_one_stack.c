//queue using one stack
#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

int pop() {
    if (top != -1) return stack[top--];
    return -1; 
}

void push(int data) {
    if (top < SIZE - 1) {
        stack[++top] = data;
    } else {
        printf("Stack Overflow\n");
    }
}

void enqueue(int data) {
    push(data);
}

int dequeue() {
    if (top == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    if (top == 0) {
        return pop();
    }
    
    int data = pop();
    int value = dequeue();  
    
    push(data);  
    
    return value;
}

int peek() {
    if (top == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int temp[SIZE];
    int tempTop = -1;
    while (top != -1) {
        temp[++tempTop] = pop();
    }
    int frontElement = temp[tempTop];
    while (tempTop != -1) {
        push(temp[tempTop--]);
    }

    return frontElement;
}

int isEmpty() {
    return top == -1;
}

int size() {
    return top + 1;
}

void display() {
    if (top == -1) {
        printf("Queue is empty!\n");
        return;
    }

    int temp[SIZE];
    int i = 0;
    
    while (top != -1) {
        temp[i++] = pop();
    }
    
    printf("Queue elements: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", temp[j]);
        push(temp[j]);  
    }
    printf("\n");
}

int main(void) {
    int choice, value;
      printf("\nQueue Operations Using Single Stack\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Get Queue Size\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                printf("%d enqueued.\n", value);
                break;
                
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;
                
            case 3:
                value = peek();
                if (value != -1)
                    printf("Front element is: %d\n", value);
                break;
                
            case 4:
                if (isEmpty())
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
                
            case 5:
                printf("Queue size: %d\n", size());
                break;
                
            case 6:
                display();
                break;
                
            case 7:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
