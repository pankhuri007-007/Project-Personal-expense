#include <stdio.h>

int main()
{
    float budget, amount;
    float food = 0, travel = 0, books = 0;
    float entertainment = 0, other = 0;
    float total, remaining, max, percent;

    int n, choice, i;

    /* Input budget */
    printf("Enter monthly budget: ");
    scanf("%f", &budget);

    printf("Enter number of expenses: ");
    scanf("%d", &n);

    /* Take expenses */
    for(i = 1; i <= n; i++)
    {
        printf("\n--- Expense %d ---\n", i);

        printf("1. Food\n");
        printf("2. Travel\n");
        printf("3. Books\n");
        printf("4. Entertainment\n");
        printf("5. Other\n");

        printf("Enter category: ");
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
                printf("Invalid category!\n");
        }
    }

    /* Calculate total */
    total = food + travel + books + entertainment + other;

    remaining = budget - total;

    percent = (total / budget) * 100;


    /* Expense Summary */
    printf("\n==============================");
    printf("\n       EXPENSE SUMMARY");
    printf("\n==============================");

    printf("\nFood          : Rs. %.2f", food);
    printf("\nTravel        : Rs. %.2f", travel);
    printf("\nBooks         : Rs. %.2f", books);
    printf("\nEntertainment : Rs. %.2f", entertainment);
    printf("\nOther         : Rs. %.2f", other);

    printf("\n------------------------------");

    printf("\nTotal Spending   : Rs. %.2f", total);
    printf("\nRemaining Budget : Rs. %.2f", remaining);
    printf("\nBudget Used      : %.2f%%", percent);


    /* Find highest expense */
    max = food;

    if(travel > max)
        max = travel;

    if(books > max)
        max = books;

    if(entertainment > max)
        max = entertainment;

    if(other > max)
        max = other;


    printf("\n\nHighest Spending Category: ");

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

    printf(" (Rs. %.2f)", max);


    /* Budget Analysis */
    printf("\n\n==============================");
    printf("\n       BUDGET ANALYSIS");
    printf("\n==============================");

    if(total > budget)
    {
        printf("\nStatus: BUDGET EXCEEDED!");
        printf("\nExceeded by Rs. %.2f", total - budget);
    }

    else if(percent >= 80)
    {
        printf("\nStatus: WARNING!");
        printf("\nYou have used more than 80%% of your budget.");
    }

    else if(percent >= 50)
    {
        printf("\nStatus: MODERATE SPENDING");
        printf("\nYou have used more than half of your budget.");
    }

    else
    {
        printf("\nStatus: GOOD");
        printf("\nYour spending is under control.");
    }


    /* Suggestions */
    printf("\n\n==============================");
    printf("\n          SUGGESTIONS");
    printf("\n==============================");

    if(max == food)
        printf("\nTry reducing unnecessary food orders.");

    else if(max == travel)
        printf("\nTry using cheaper transport options.");

    else if(max == books)
        printf("\nConsider borrowing or buying used books.");

    else if(max == entertainment)
        printf("\nTry reducing entertainment expenses.");

    else
        printf("\nCheck your other expenses for possible savings.");

    if(total > budget)
        printf("\nAvoid unnecessary spending until next month.");

    else
        printf("\nKeep tracking your expenses regularly.");

    printf("\n");

    return 0;
}