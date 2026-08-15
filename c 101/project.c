#include <stdio.h>
#include <string.h>

struct Child {
    char firstName[50];
    char lastName[50];
    char dateOfBirth[20];
    char gender[10];
};

struct Parent {
    char firstName[50];
    char lastName[50];
    char relationship[50];
    char phone[20];
    char email[100];
    char address[100];
};

struct Payment {
    float feeDue;
    float amountPaid;
    float balance;
    char receiptNumber[30];
};

int main() {
    struct Child child;
    struct Parent parent;
    struct Payment payment;
    int receiptSerial = 1;
    int choice;

    do {
        printf("\n=== BLOOMING BUDS NURSERY ENROLLMENT ===\n");

        printf("\n--- CHILD BIO DATA ---\n");
        printf("First Name: ");
        scanf("%49s", child.firstName);
        printf("Last Name: ");
        scanf("%49s", child.lastName);
        printf("Date of Birth (DD/MM/YYYY): ");
        scanf("%19s", child.dateOfBirth);
        printf("Gender: ");
        scanf("%9s", child.gender);

        printf("\n--- PARENT / GUARDIAN DETAILS ---\n");
        printf("First Name: ");
        scanf("%49s", parent.firstName);
        printf("Last Name: ");
        scanf("%49s", parent.lastName);
        printf("Relationship: ");
        scanf("%49s", parent.relationship);
        printf("Phone: ");
        scanf("%19s", parent.phone);
        printf("Email: ");
        scanf("%99s", parent.email);
        printf("Address: ");
        scanf("%99s", parent.address);

        printf("\n--- FEE PAYMENT ---\n");
        printf("Total Fees Due: ");
        scanf("%f", &payment.feeDue);
        printf("Amount Paid: ");
        scanf("%f", &payment.amountPaid);
        payment.balance = payment.feeDue - payment.amountPaid;

        sprintf(payment.receiptNumber, "NR/2025/%03d", receiptSerial);

        printf("\n========== PAYMENT RECEIPT ==========\n");
        printf("Receipt No.: %s\n", payment.receiptNumber);
        printf("Child: %s %s\n", child.firstName, child.lastName);
        printf("DOB: %s | Gender: %s\n", child.dateOfBirth, child.gender);
        printf("Parent/Guardian: %s %s (%s)\n", parent.firstName, parent.lastName, parent.relationship);
        printf("Contact: %s | Email: %s\n", parent.phone, parent.email);
        printf("Address: %s\n", parent.address);
        printf("-------------------------------------\n");
        printf("Fees Due   : %.2f\n", payment.feeDue);
        printf("Amount Paid: %.2f\n", payment.amountPaid);
        if (payment.balance >= 0) {
            printf("Balance    : %.2f\n", payment.balance);
        } else {
            printf("Balance    : 0.00 (Overpayment %.2f credited)\n", -payment.balance);
        }
        printf("Thank you for trusting Blooming Buds Nursery!\n");
        printf("=====================================\n");

        receiptSerial++;

        printf("\nOptions:\n1. Record another child\n2. Exit\nChoose 1 or 2: ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\nThank you for using the nursery system!\n");
    return 0;
}
