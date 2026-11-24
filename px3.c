#include <stdio.h>

int main()
{
    float budget, amount;
    float food = 0, travel = 0, books = 0;
    float entertainment = 0, other = 0;
    float total, remaining, max;
    int n, choice, i;

    printf("Enter monthly budget: ");
    scanf("%f", &budget);

    printf("Enter number of expenses: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("\n1. Food");
        printf("\n2. Travel");
        printf("\n3. Books");
        printf("\n4. Entertainment");
        printf("\n5. Other");

        printf("\nEnter category: ");
        scanf("%d", &choice);

        printf("Enter amount: ");
        scanf("%f", &amount);

        switch(choice)
        {
            case 1:
                food = food + amount;
                break;

            case 2:
                travel = travel + amount;
                break;

            case 3:
                books = books + amount;
                break;

            case 4:
                entertainment = entertainment + amount;
                break;

            case 5:
                other = other + amount;
                break;

            default:
                printf("Invalid category");
        }
    }

    total = food + travel + books + entertainment + other;
    remaining = budget - total;

    printf("\n--- EXPENSE SUMMARY ---");
    printf("\nFood = %.2f", food);
    printf("\nTravel = %.2f", travel);
    printf("\nBooks = %.2f", books);
    printf("\nEntertainment = %.2f", entertainment);
    printf("\nOther = %.2f", other);

    printf("\nTotal Spending = %.2f", total);
    printf("\nRemaining Budget = %.2f", remaining);

    max = food;

    if(travel > max)
        max = travel;
    if(books > max)
        max = books;
    if(entertainment > max)
        max = entertainment;
    if(other > max)
        max = other;

    printf("\nHighest Expenditure = ");

    if(max == food)
        printf("Food");
    else if(max == travel)
        printf("Travel");
    else if(max == books)
        printf("Books");
    else if(max == entertainment)
        printf("Entertainment");
    else
        printf("Other");

    if(total > budget)
        printf("\nWARNING: Budget Exceeded!");
    else
        printf("\nBudget is under control.");

    return 0;
}