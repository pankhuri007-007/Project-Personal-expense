#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct
{
    char name[50];
    int category;
    float amount;
} Expense;

Expense expenses[MAX];
int count = 0;
float budget = 0;

/* ---------- FUNCTION DECLARATIONS ---------- */

void loadData();
void saveData();
void setBudget();
void addExpense();
void viewExpenses();
void analysis();
void suggestions();
void searchExpense();
void dashboard();
void progressBar(float percent);
const char *categoryName(int category);

/* ---------- MAIN ---------- */

int main()
{
    int choice;

    loadData();

    if (budget <= 0)
        setBudget();

    while (1)
    {
        dashboard();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addExpense();
            break;

        case 2:
            viewExpenses();
            break;

        case 3:
            analysis();
            break;

        case 4:
            suggestions();
            break;

        case 5:
            searchExpense();
            break;

        case 6:
            setBudget();
            saveData();
            break;

        case 7:
            saveData();
            printf("\nData saved successfully!\n");
            printf("Thank you for using SmartSpend.\n");
            return 0;

        default:
            printf("\nInvalid choice!\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

/* ---------- CATEGORY NAME ---------- */

const char *categoryName(int category)
{
    switch (category)
    {
    case 1:
        return "Food";

    case 2:
        return "Travel";

    case 3:
        return "Books";

    case 4:
        return "Entertainment";

    case 5:
        return "Other";

    default:
        return "Unknown";
    }
}

/* ---------- SET BUDGET ---------- */

void setBudget()
{
    printf("\n========================================\n");
    printf("           SET MONTHLY BUDGET\n");
    printf("========================================\n");

    printf("Enter monthly budget: Rs. ");
    scanf("%f", &budget);

    printf("\nBudget set to Rs. %.2f\n", budget);
}

/* ---------- DASHBOARD ---------- */

void dashboard()
{
    float total = 0;
    float remaining;
    float percent;
    int i;

    for (i = 0; i < count; i++)
        total += expenses[i].amount;

    remaining = budget - total;

    if (budget > 0)
        percent = (total / budget) * 100;
    else
        percent = 0;

    system("cls");

    printf("\n");
    printf("============================================\n");
    printf("       SMARTSPEND - STUDENT EXPENSE MANAGER\n");
    printf("============================================\n");

    printf("\nMonthly Budget : Rs. %.2f", budget);
    printf("\nTotal Spent    : Rs. %.2f", total);
    printf("\nRemaining      : Rs. %.2f", remaining);
    printf("\nBudget Used    : %.1f%%\n\n", percent);

    progressBar(percent);

    if (percent >= 100)
        printf("\nSTATUS: BUDGET EXCEEDED!\n");
    else if (percent >= 80)
        printf("\nSTATUS: WARNING - Budget almost exhausted!\n");
    else
        printf("\nSTATUS: Spending under control.\n");

    printf("\n--------------------------------------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expense History\n");
    printf("3. Expense Analysis\n");
    printf("4. Smart Suggestions\n");
    printf("5. Search Expense\n");
    printf("6. Change Monthly Budget\n");
    printf("7. Save & Exit\n");
    printf("--------------------------------------------\n");
}

/* ---------- PROGRESS BAR ---------- */

void progressBar(float percent)
{
    int bars;
    int i;

    if (percent > 100)
        percent = 100;

    bars = (int)(percent / 5);

    printf("Budget: [");

    for (i = 0; i < 20; i++)
    {
        if (i < bars)
            printf("#");
        else
            printf("-");
    }

    printf("] %.1f%%\n", percent);
}

/* ---------- ADD EXPENSE ---------- */

void addExpense()
{
    if (count >= MAX)
    {
        printf("\nExpense storage is full!\n");
        return;
    }

    printf("\n========================================\n");
    printf("              ADD EXPENSE\n");
    printf("========================================\n");

    printf("Expense name: ");
    scanf(" %49[^\n]", expenses[count].name);

    printf("\nSelect Category\n");
    printf("1. Food\n");
    printf("2. Travel\n");
    printf("3. Books\n");
    printf("4. Entertainment\n");
    printf("5. Other\n");

    printf("\nCategory: ");
    scanf("%d", &expenses[count].category);

    if (expenses[count].category < 1 ||
        expenses[count].category > 5)
    {
        printf("\nInvalid category!\n");
        return;
    }

    printf("Amount: Rs. ");
    scanf("%f", &expenses[count].amount);

    if (expenses[count].amount <= 0)
    {
        printf("\nInvalid amount!\n");
        return;
    }

    count++;

    saveData();

    printf("\nExpense added successfully!\n");
}

/* ---------- VIEW EXPENSES ---------- */

void viewExpenses()
{
    int i;

    printf("\n============================================================\n");
    printf("                    EXPENSE HISTORY\n");
    printf("============================================================\n");

    if (count == 0)
    {
        printf("\nNo expenses recorded.\n");
        return;
    }

    printf("%-5s %-20s %-18s %-10s\n",
           "No.", "Expense", "Category", "Amount");

    printf("------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-5d %-20s %-18s Rs. %-10.2f\n",
               i + 1,
               expenses[i].name,
               categoryName(expenses[i].category),
               expenses[i].amount);
    }
}

/* ---------- ANALYSIS ---------- */

void analysis()
{
    float categoryTotal[5] = {0};
    float total = 0;
    float remaining;
    float percent;
    float highest;
    int highestCategory = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        categoryTotal[expenses[i].category - 1] +=
            expenses[i].amount;

        total += expenses[i].amount;
    }

    printf("\n========================================\n");
    printf("            EXPENSE ANALYSIS\n");
    printf("========================================\n");

    for (i = 0; i < 5; i++)
    {
        if (total > 0)
            percent = (categoryTotal[i] / total) * 100;
        else
            percent = 0;

        printf("%-15s : Rs. %8.2f (%5.1f%%)\n",
               categoryName(i + 1),
               categoryTotal[i],
               percent);
    }

    highest = categoryTotal[0];

    for (i = 1; i < 5; i++)
    {
        if (categoryTotal[i] > highest)
        {
            highest = categoryTotal[i];
            highestCategory = i;
        }
    }

    remaining = budget - total;

    printf("\n----------------------------------------\n");
    printf("Total Spending   : Rs. %.2f\n", total);
    printf("Remaining Budget : Rs. %.2f\n", remaining);

    if (count > 0)
    {
        printf("Highest Spending : %s (Rs. %.2f)\n",
               categoryName(highestCategory + 1),
               highest);
    }

    printf("----------------------------------------\n");

    if (total > budget)
        printf("WARNING: You exceeded your budget by Rs. %.2f!\n",
               total - budget);
}

/* ---------- SMART SUGGESTIONS ---------- */

void suggestions()
{
    float categoryTotal[5] = {0};
    float total = 0;
    float percent;
    int highest = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        categoryTotal[expenses[i].category - 1] +=
            expenses[i].amount;

        total += expenses[i].amount;
    }

    printf("\n========================================\n");
    printf("           SMART MONEY INSIGHTS\n");
    printf("========================================\n");

    if (count == 0)
    {
        printf("Add some expenses first.\n");
        return;
    }

    for (i = 1; i < 5; i++)
    {
        if (categoryTotal[i] > categoryTotal[highest])
            highest = i;
    }

    if (budget > 0)
        percent = (total / budget) * 100;
    else
        percent = 0;

    printf("\nYour biggest spending category is %s.\n",
           categoryName(highest + 1));

    printf("You spent Rs. %.2f on it.\n",
           categoryTotal[highest]);

    if (percent >= 100)
    {
        printf("\nALERT:\n");
        printf("Your spending has crossed your monthly budget.\n");
        printf("Avoid unnecessary expenses until next month.\n");
    }
    else if (percent >= 80)
    {
        printf("\nTIP:\n");
        printf("You have already used %.1f%% of your budget.\n",
               percent);
        printf("Reduce spending in %s.\n",
               categoryName(highest + 1));
    }
    else if (percent >= 50)
    {
        printf("\nTIP:\n");
        printf("You are halfway through your budget.\n");
        printf("Keep monitoring your spending.\n");
    }
    else
    {
        printf("\nGOOD JOB:\n");
        printf("Your spending is currently under control.\n");
    }

    if (categoryTotal[3] > categoryTotal[2])
    {
        printf("\nSaving Idea:\n");
        printf("Entertainment spending is higher than Books.\n");
        printf("Consider reducing entertainment expenses.\n");
    }
}

/* ---------- SEARCH ---------- */

void searchExpense()
{
    char search[50];
    int found = 0;
    int i;

    printf("\n========================================\n");
    printf("             SEARCH EXPENSE\n");
    printf("========================================\n");

    printf("Enter expense name: ");
    scanf(" %49[^\n]", search);

    for (i = 0; i < count; i++)
    {
        if (strstr(expenses[i].name, search) != NULL)
        {
            printf("\nExpense  : %s", expenses[i].name);
            printf("\nCategory : %s",
                   categoryName(expenses[i].category));
            printf("\nAmount   : Rs. %.2f\n",
                   expenses[i].amount);

            found = 1;
        }
    }

    if (!found)
        printf("\nNo matching expense found.\n");
}

/* ---------- SAVE DATA ---------- */

void saveData()
{
    FILE *file;
    int i;

    file = fopen("expenses.txt", "w");

    if (file == NULL)
        return;

    fprintf(file, "%.2f\n", budget);
    fprintf(file, "%d\n", count);

    for (i = 0; i < count; i++)
    {
        fprintf(file, "%s\n", expenses[i].name);
        fprintf(file, "%d\n", expenses[i].category);
        fprintf(file, "%.2f\n", expenses[i].amount);
    }

    fclose(file);
}

/* ---------- LOAD DATA ---------- */

void loadData()
{
    FILE *file;
    int i;

    file = fopen("expenses.txt", "r");

    if (file == NULL)
        return;

    fscanf(file, "%f\n", &budget);
    fscanf(file, "%d\n", &count);

    if (count > MAX)
        count = MAX;

    for (i = 0; i < count; i++)
    {
        fgets(expenses[i].name,
              sizeof(expenses[i].name),
              file);

        expenses[i].name[
            strcspn(expenses[i].name, "\n")] = '\0';

        fscanf(file, "%d\n",
               &expenses[i].category);

        fscanf(file, "%f\n",
               &expenses[i].amount);
    }

    fclose(file);
}

