#include <stdio.h>
#include <stdlib.h>

// Define a structure for a polynomial term
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function declarations
struct Term* create_term(int coefficient, int exponent);
struct Term* insert_term(struct Term* head, int coefficient, int exponent);
struct Term* add_polynomials(struct Term* poly1, struct Term* poly2);
void display_polynomial(struct Term* head);

int main() {
    int n, coeff, exp;
    struct Term *poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Get the first polynomial
    printf("Enter the total number of terms in the polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &exp);
        poly1 = insert_term(poly1, coeff, exp);
    }
    printf("First polynomial : ");
    display_polynomial(poly1);

    // Get the second polynomial
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &exp);
        poly2 = insert_term(poly2, coeff, exp);
    }
    printf("Second polynomial : ");
    display_polynomial(poly2);

    // Add the two polynomials
    result = add_polynomials(poly1, poly2);

    // Display the result
    printf("Resultant polynomial after addition : ");
    display_polynomial(result);

    return 0;
}

// Function to create a new term
struct Term* create_term(int coefficient, int exponent) {
    struct Term* new_term = (struct Term*)malloc(sizeof(struct Term));
    new_term->coefficient = coefficient;
    new_term->exponent = exponent;
    new_term->next = NULL;
    return new_term;
}

// Function to insert a term in descending order of exponents
struct Term* insert_term(struct Term* head, int coefficient, int exponent) {
    struct Term* new_term = create_term(coefficient, exponent);
    if (head == NULL || head->exponent < exponent) {
        new_term->next = head;
        head = new_term;
    } else {
        struct Term* current = head;
        while (current->next != NULL && current->next->exponent >= exponent) {
            current = current->next;
        }
        new_term->next = current->next;
        current->next = new_term;
    }
    return head;
}

// Function to add two polynomials
struct Term* add_polynomials(struct Term* poly1, struct Term* poly2) {
    struct Term *result = NULL, *tail = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            result = insert_term(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            result = insert_term(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0) {
                result = insert_term(result, sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        result = insert_term(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insert_term(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void display_polynomial(struct Term* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    while (head != NULL) {
        if (head->coefficient > 0 && head != head->next) {
            printf("+");
        }
        if (head->exponent == 0) {
            printf("%d", head->coefficient);
        } else {
            printf("%d(x^%d)", head->coefficient, head->exponent);
        }
        head = head->next;
        if (head != NULL && head->coefficient > 0) {
            printf("+");
        }
    }
    printf("\n");
}