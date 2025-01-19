//2. CRUD Operations in File using C Language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "users.txt"
typedef struct {
    int id;
    char name[50];
    int age;
} User;

// create a new user
void create_user() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        // If the file does not exist, create the user.
        file = fopen(FILE_NAME, "a");
        if (file == NULL) {
            printf("Error opening file.\n");
            return;
        }
    }

    int existing_id;
    User new_user, existing_user;

    printf("Enter User ID: ");
    scanf("%d", &existing_id);

    // Check for duplicate ID
    while (fscanf(file, "%d %s %d", &existing_user.id, existing_user.name, &existing_user.age) != EOF) {
        if (existing_user.id == existing_id) {
            printf("Error: User with ID %d already exists.\n", existing_id);
            fclose(file);
            return;
        }
    }
    fclose(file);
    // if no duplicate is found then reopen the file
    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    new_user.id = existing_id;
    while (getchar() != '\n');
    printf("Enter Name: ");
    fgets(new_user.name, sizeof(new_user.name), stdin);
    new_user.name[strcspn(new_user.name, "\n")] = 0; 
    printf("Enter Age: ");
    scanf("%d", &new_user.age);

    fprintf(file, "%d %s %d\n", new_user.id, new_user.name, new_user.age);
    fclose(file);

    printf("User added successfully.\n");
}

// read all users from the file
void read_users() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    User user;
    printf("ID\tName\tAge\n");
    printf("----------------------\n");

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }

    fclose(file);
}

// update a user's details based on ID
void update_user() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    User user;
    printf("Enter the User ID to update: ");
    scanf("%d", &id);
    //Since files in C cannot be changed directly, the altered content—aside from the deleted record—is temporarily stored in the "temp" file. By securely replacing the original file, it guarantees data integrity.
    FILE *tempFile = fopen("temp.txt", "w");

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("User updated successfully.\n");
    } else {
        printf("User with ID %d not found.\n", id);
    }
}

// delete a user by ID
void delete_user() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    User user;

    printf("Enter the User ID to delete: ");
    scanf("%d", &id);

    // Using a temporary file to store records except the one to delete
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
        } else {
            fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
        }
    }
    fclose(file);
    fclose(tempFile);

    // Replace the original file with the updated file
    if (remove(FILE_NAME) != 0 || rename("temp.txt", FILE_NAME) != 0) {
        printf("Error updating file.\n");
        return;
    }

    if (found) {
        printf("User deleted successfully.\n");
    } else {
        printf("User with ID %d not found.\n", id);
    }
}
//main function
int main() {
    int choice;
    while (1) {
        printf("\nCRUD Operations:\n");
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_user();
                break;
            case 2:
                read_users();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}