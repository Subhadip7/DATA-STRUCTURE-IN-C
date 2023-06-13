#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term with given coefficient and exponent
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void addTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Term* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            addTerm(&result, sum, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* temp = poly2;

    while (poly1 != NULL) {
        while (temp != NULL) {
            int coefficient = poly1->coefficient * temp->coefficient;
            int exponent = poly1->exponent + temp->exponent;
            addTerm(&result, coefficient, exponent);
            temp = temp->next;
        }
        poly1 = poly1->next;
        temp = poly2;
    }

    return result;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    // Create polynomial 1: 2x^3 + 3x^2 + 4x^1
    addTerm(&poly1, 2, 3);
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 4, 1);

    // Create polynomial 2: 1x^2 + 2x^1 + 1x^0
    addTerm(&poly2, 1, 2);
    addTerm(&poly2, 2, 1);
    addTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);
    printf("Addition: ");
    displayPolynomial(result);

    result = multiplyPolynomials(poly1, poly2);
    printf("Multiplication: ");
    displayPolynomial(result);

    return 0;
}
