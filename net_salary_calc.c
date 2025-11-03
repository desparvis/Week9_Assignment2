#include <stdio.h>

// Function to compute income tax based on pay brackets
void getTax(double *salary, double *taxAmount) {
    if (*salary <= 100) {
        *taxAmount = 0.0;
    } else if (*salary <= 300) {
        *taxAmount = *salary * 0.2;
    } else {
        *taxAmount = *salary * 0.28;
    }
}

// Function to compute health insurance deduction (5%)
void getHealth(double *salary, double *healthDeduct) {
    *healthDeduct = *salary * 0.05;
}

// Function to compute maternity contribution (0.3%)
void getMaternity(double *salary, double *maternityDeduct) {
    *maternityDeduct = *salary * 0.003;
}

// Function to compute social fund deduction (3%)
void getSocialFund(double *salary, double *fundDeduct) {
    *fundDeduct = *salary * 0.03;
}

// Function to combine all deductions and compute net pay
void getNetPay(double *salary, double *netPay) {
    double tax, health, maternity, fund;

    getTax(salary, &tax);
    getHealth(salary, &health);
    getMaternity(salary, &maternity);
    getSocialFund(salary, &fund);

    *netPay = *salary - (tax + health + maternity + fund);
}

int main() {
    double basicPay, takeHome;

    printf("Enter your gross income: ");
    scanf("%lf", &basicPay);

    getNetPay(&basicPay, &takeHome);

    printf("\nSalary Summary \n");
    printf("Gross Income: $%.2f\n", basicPay);
    printf("Net Income  : $%.2f \n", takeHome);

    return 0;
}