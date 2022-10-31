#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
} Date;

typedef struct
{
    int year;
    int month;
    int day;

    int hours;
    int minutes;
    int seconds;
} DateTime;

typedef struct
{
    int hours;
    int minutes;
    int seconds;
} Time;

typedef struct
{
    Date date;
    Time time;
    float temperature;
} Measurement;

int is_date_valid(Date date);
int earlier(Date date1, Date date2);
Measurement load_measurement();

int main()
{

    Date date = {2021, 10, 20};
    Date date2 = {2021, 10, 20};

    printf("%d\n", is_date_valid(date));

    printf("porovnani datumu: %d\n", earlier(date, date2));

    Measurement m[5];

    for (int i = 0; i < 5; i++)
    {
        m[i] = load_measurement();
    }

    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += m[i].temperature;
    }

    printf("avg temperature: %f \n", sum / 5);
    return 0;
}

int is_date_valid(Date date)
{
    if (date.day < 1 || date.day > 31)
    {
        return 0;
    }

    if (date.month < 1 || date.month > 12)
    {
        return 0;
    }

    /*
    if (date.year < 1 || date.year > 9999)
    {
        return 0;
    }
     */

    return 1;
}

// -1 first earlier, 0 same, 1 second earlier
int earlier(Date date1, Date date2)
{
    if (date1.year < date2.year)
        return -1;

    if (date1.year > date2.year)
        return 1;

    if (date1.month < date2.month)
        return -1;

    if (date1.month > date2.month)
        return 1;

    if (date1.day < date2.day)
        return -1;

    if (date1.day > date2.day)
        return 1;

    return 0;
}

Measurement load_measurement()
{
    Measurement m;

    printf("Input data in format yyyy mm dd hh mm ss temperature\n");
    scanf("%d %d %d %d %d %d %f", &m.date.year, &m.date.month, &m.date.day, &m.time.hours, &m.time.minutes, &m.time.seconds, &m.temperature);

    return m;
}
