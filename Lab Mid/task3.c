// Program writte by: Iftekhar Turja

#include <stdio.h>

// struct to store information of a student
struct student
{
    char name[20];
    int id;
    float cgpa;
};

// function to print information of a student
void print_student(struct student s)
{
    printf("Name: %s\n", s.name);
    printf("Id: %d\n", s.id);
    printf("CGPA: %.2f\n\n", s.cgpa);
}

// main function
int main()
{
    int n, i;
    n = 3;
    struct student s[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("\nEnter id of student %d: ", i + 1);
        scanf("%d", &s[i].id);
        printf("\nEnter cgpa of student %d: ", i + 1);
        scanf("%f", &s[i].cgpa);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Student %d Info:\n", i + 1);
        print_student(s[i]);
    }
    float max = s[0].cgpa;
    int index = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i].cgpa > max)
        {
            max = s[i].cgpa;
            index = i;
        }
    }
    printf("%s got the highest cgpa.\n", s[index].name);
    return 0;
}
