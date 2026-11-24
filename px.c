#include <stdio.h>

int main()
{
    float budget, amount;
    float food = 0, travel = 0, books = 0, entertainment = 0;
    float total, remaining;
    int n, category, i;

    printf("Enter monthly budget: ");
    scanf("%f", &budget);

    printf("Enter number of expenses: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("\nExpense %d\n", i);

        printf("Choose category:\n");
        printf("1. Food\n");
        printf("2. Travel\n");
        printf("3. Books\n");
        printf("4. Entertainment\n");

        printf("Enter category: ");
        scanf("%d", &category);

        printf("Enter amount: ");
        scanf("%f", &amount);

        switch(category)
        {
            case 1:
                food += amount;
                break;

            case 2:
                travel += amount;
                break;

            case 3:
                books += amount;
                break;

            case 4:
                entertainment += amount;
                break;

            default:
                printf("Invalid category!\n");
                i--;
        }
    }

    total = food + travel + books + entertainment;
    remaining = budget - total;

    printf("\n----- EXPENSE SUMMARY -----\n");

    printf("Food: %.2f\n", food);
    printf("Travel: %.2f\n", travel);
    printf("Books: %.2f\n", books);
    printf("Entertainment: %.2f\n", entertainment);

    printf("\nTotal Spending: %.2f\n", total);
    printf("Remaining Budget: %.2f\n", remaining);

    printf("\nHighest Spending Category: ");

    if(food >= travel && food >= books && food >= entertainment)
        printf("Food\n");
    else if(travel >= food && travel >= books && travel >= entertainment)
        printf("Travel\n");
    else if(books >= food && books >= travel && books >= entertainment)
        printf("Books\n");
    else
        printf("Entertainment\n");

    if(total > budget)
        printf("\nWARNING: Budget Exceeded!\n");
    else
        printf("\nBudget is under control.\n");

    return 0;
}