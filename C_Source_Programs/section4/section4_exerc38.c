#include <stdio.h>

int main()
{

    int day, month, year, qtyDays;

    printf("Enter a year, please:\n");
    scanf("%d", &year);

    if (year <= 0)
    {
        printf("The year informed is not valid! The year needs to be greater than zero.\n");
        return 1;
    }
    else {
        printf("Enter a month, please:\n");
        scanf("%d", &month);
        
        if (month < 1 || month > 12) {
            printf("The month informed is not valid! The year needs to be between 1 and 12.\n");
            return 1;
        } else {
            printf("Enter a day, please:\n");
            scanf("%d", &day);
        }
    }

    if (month == 1)
    {

        qtyDays = 31;

        if (day >= 1 && day <= 31)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 31\n");
        }
    }
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) && month == 2)
        {

            qtyDays = 29;

            if (day >= 1 && day <= 29)
            {
                printf("This is a valid day.\n");
            }
            else
            {
                printf("This is not a valid day. The day needs to be between 1 and 29\n");
            }
        }
        else
        {

            qtyDays = 28;

            if (day >= 1 && day <= 28)
            {
                printf("This is a valid day.\n");
            }
            else
            {
                printf("This is not a valid day. The day needs to be between 1 and 28\n");
            }
        }
    }
    else if (month == 3)
    {

        qtyDays = 31;

        if (day >= 1 && day <= 31)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 31\n");
        }
    }
    else if (month == 4)
    {

        qtyDays = 30;

        if (day >= 1 && day <= 30)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 30\n");
        }
    }
    else if (month == 5)
    {

        qtyDays = 31;

        if (day >= 1 && day <= 31)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 31\n");
        }
    }
    else if (month == 6)
    {

        qtyDays = 30;

        if (day >= 1 && day <= 30)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 30\n");
        }
    }
    else if (month == 7)
    {

        qtyDays = 31;

        if (day >= 1 && day <= 31)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 31\n");
        }
    }
    else if (month == 8)
    {

        qtyDays = 31;

        if (day >= 1 && day <= 31)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 31\n");
        }
    }
    else if (month == 9)
    {

        qtyDays = 30;

        if (day >= 1 && day <= 30)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 30\n");
        }
    }
    else if (month == 10)
    {

        qtyDays = 31;

        if (day >= 1 && day <= 31)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 31\n");
        }
    }
    else if (month == 11)
    {

        qtyDays = 30;

        if (day >= 1 && day <= 30)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 30\n");
        }
    }
    else if (month == 12)
    {

        qtyDays = 31;

        if (day >= 1 && day <= 31)
        {
            printf("This is a valid day.\n");
        }
        else
        {
            printf("This is not a valid day. The day needs to be between 1 and 31\n");
        }
    }

    return 0;

}