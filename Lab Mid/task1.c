// Program written by: Iftekhar Turja

#include <stdio.h>

// function to find volume of cylinder
float volume(float r, float h)
{
    float v;
    float pi = 3.1416;
    v = pi * r * r * h;
    return v;
}

// main function
int main()
{
    float r, h, v;
    printf("Enter radius cylinder: ");
    scanf("%f", &r);
    printf("Enter height cylinder: ");
    scanf("%f", &h);
    v = volume(r, h);
    printf("Volume of cylinder is: %.3f", v);
    return 0;
}
