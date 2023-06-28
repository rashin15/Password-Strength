#include <stdio.h>
#include <string.h>

// Function to check password strength
int checkPasswordStrength(char password[]) {
    int length = strlen(password);

    // Check length
    if (length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letters, lowercase letters, and digits
    int hasUppercase = 0, hasLowercase = 0, hasDigit = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z')
            hasUppercase = 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            hasLowercase = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;
    }

    // Check if all criteria are met
    if (hasUppercase && hasLowercase && hasDigit) {
        printf("Strong password! Good job!\n");
        return 1;
    }

    // Provide feedback on missing criteria
    if (!hasUppercase)
        printf("Password should contain at least one uppercase letter.\n");
    if (!hasLowercase)
        printf("Password should contain at least one lowercase letter.\n");
    if (!hasDigit)
        printf("Password should contain at least one digit.\n");

    return 0;
}

int main() {
    char password[100];
    int isStrong = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    while (!isStrong) {
        isStrong = checkPasswordStrength(password);
        if (!isStrong) {
            printf("Please enter a valid password: ");
            scanf("%s", password);
        }
    }
    return 0;
}
