#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable for number of students
int i = 0;

// Structure
struct sinfo
{
    char fname[50];
    char lname[50];
    long long roll;
    float cgpa;
    int cid[5];
} s[50];

// Add student
void addstudent()
{
    if (i > 50)
    {
        //The limit of maximum student entry limit is 50. 
        printf("Student entry limit reached. You can enter no more students.\n");
    }
    else
    {
     // Inputs
    printf("\nAdd Student Details\n");
    printf("-------------------\n");
    printf("Enter first name: ");
    scanf("%s", &s[i].fname);
    printf("Enter last name: ");
    scanf("%s", &s[i].lname);
    printf("Enter roll number: ");
    scanf("%lld", &s[i].roll);
    printf("Enter your CGPA: ");
    scanf("%f", &s[i].cgpa);
    printf("Enter the course ID of each course: ");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &s[i].cid[j]);
    }

    printf("\n");

    // Preview
    printf("The details of the student: \n");
    printf("Name: %s %s\n", s[i].fname, s[i].lname);
    printf("Roll: %lld\n", s[i].roll);
    printf("CGPA: %.2f\n", s[i].cgpa);
    printf("Course IDs: ");
    for (int j = 0; j < 5; j++)
    {
        printf("%d ", s[i].cid[j]);
    }

    editorsave();

    i++;
    }
    
   
}

// Update
void update()
{
    printf("Enter the roll number to update: ");
    long long x;
    scanf("%lld", &x);
    int found = 0;
    for (int j = 0; j < i; j++)
    {
        if (s[j].roll == x)
        {
            
            printf("Choose what you want to update: \n");
            printf("1. First name\n"
                   "2. Last name\n"
                   "3. Roll No.\n"
                   "4.CGPA\n"
                   "5.Courses\n");

            int z;
            scanf("%d", &z);
            switch (z)
            {
            case 1:
                printf("Enter new first name: ");
                scanf("%s", &s[j].fname);
                break;
            case 2:
                printf("Enter new last name: ");
                scanf("%s", &s[j].lname);
                break;
            case 3:
                printf("Enter new roll number: ");
                scanf("%lld", &s[j].roll);
                break;
            case 4:
                printf("Enter CGPA: ");
                scanf("%f", &s[j].cgpa);
                break;
            case 5:
                printf("Enter new courses: ");
                for (int k = 0; k < 5; k++)
                {
                    scanf("%d", &s[j].cid[k]);
                }
                break;
            default:
                printf("Invalid Choice!\n");
                break;
            }

            // Preview
            printf("The details of the student: \n");
            printf("Name: %s %s\n", s[j].fname, s[j].lname);
            printf("Roll: %lld\n", s[j].roll);
            printf("CGPA: %.2f\n", s[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", s[j].cid[k]);
            }
            printf("\n");

            found = 1;
            editorsave();
            break;
        }
       
    }
    if (!found)
    {
        printf("Student not found.\n");
    }
}

//Edit
void edit(){
    if (i == 0)
        {
            
            printf("Choose what you want to update: \n");
            printf("1. First name\n"
                   "2. Last name\n"
                   "3. Roll No.\n"
                   "4.CGPA\n"
                   "5.Courses\n");

            int z;
            scanf("%d", &z);
            switch (z)
            {
            case 1:
                printf("Enter new first name: ");
                scanf("%s", &s[i].fname);
                break;
            case 2:
                printf("Enter new last name: ");
                scanf("%s", &s[i].lname);
                break;
            case 3:
                printf("Enter new roll number: ");
                scanf("%lld", &s[i].roll);
                break;
            case 4:
                printf("Enter CGPA: ");
                scanf("%f", &s[i].cgpa);
                break;
            case 5:
                printf("Enter new courses: ");
                for (int k = 0; k < 5; k++)
                {
                    scanf("%d", &s[i].cid[k]);
                }
                break;
            default:
                printf("Invalid Choice!\n");
                break;
            }

            // Preview
            printf("The details of the student: \n");
            printf("Name: %s %s\n", s[i].fname, s[i].lname);
            printf("Roll: %lld\n", s[i].roll);
            printf("CGPA: %.2f\n", s[i].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", s[i].cid[k]);
            }
            printf("\n");

            //found = 1;
            editorsave();
            
        }
}
// Update/Save?
void editorsave()
{
    int g;
    printf("\n\nEdit or save?\n");
    printf("1. Edit\n");
    printf("2. Save\n");
    scanf("%d", &g);
    if (g == 1)
    {
       if (i == 0)
       {
        edit();
       }
       else
        update();
    }
    else if (g == 2)
    {
        printf("Saved successfully.\n");
    }
}

//Number of student entries
void numofstudents(){
    if (i == 50)
    {
        printf("\nThe number of students is: %d\n", i);
        printf("50 students max.\n");
        printf("Student entry limit reached. You can enter no more students.\n");
    }
    else{
    printf("\nThe number of students is: %d\n", i);
    printf("50 students max.\n");
    printf("You can have %d more students.\n", 50 - i);
    }
}

//Find the students using roll
void fs_roll(){
    printf("Enter the roll number: ");
    long long x;
    int found = 0;
    scanf("%lld", &x);
    for (int j = 0; j < i; j++)
    {
        if (s[j].roll == x)
        {
            
            // Preview
            printf("The details of the student: \n");
            printf("Name: %s %s\n", s[j].fname, s[j].lname);
            printf("Roll: %lld\n", s[j].roll);
            printf("CGPA: %.2f\n", s[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", s[j].cid[k]);
            }

            printf("\n");
            found = 1;
            break;
        }
        if(!found)
        {
            printf("Student not found.\n");
        }
    }
}

//Find students using first name
void fs_fname(){
    char a[50];
    printf("Enter the first name: ");
    scanf("%s", a);
    int found = 0;

    printf("The details of the students: \n");
    for (int j = 0; j < i; j++)
    {
        if (!strcmp(s[j].fname, a))
        {
            printf("Name: %s %s\n", s[j].fname, s[j].lname);
            printf("Roll: %lld\n", s[j].roll);
            printf("CGPA: %.2f\n", s[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", s[j].cid[k]);
                
            }
            printf("\n\n");
            found = 1;   
        }
        if(!found)
        {
            printf("Student not found.\n");
        }  
        
    }
    

}

//Delete
void delete() {
    long long a;
    printf("Enter the roll number you want to delete: ");
    scanf("%lld", &a);
    int found = 0;
    for (int j = 0; j < i; j++) {
        if (a == s[j].roll) {
            for (int k = j; k < i - 1; k++) {
                s[k] = s[k + 1];
            }
            i--;
            found = 1;
            printf("Data removed successfully.\n");
            return;
        }
    }
    if (!found) {
        printf("Roll number not found.\n");
    }
}

// Function to find
// the students enrolled
// in a particular course
void fscrsid()
{
    int id;
    printf("Enter the course ID \n");
    scanf("%d", &id);
    int c = 0;
 
    printf("The details of the students:\n");
    for (int j = 0; j < i; j++) {
        for (int d = 0; d < 5; d++) {
            if (id == s[j].cid[d]) {

                
                printf("Name: %s %s\n", s[j].fname, s[j].lname);
                printf("Roll: %lld\n ", s[j].roll);
                printf("CGPA: %.2f\n", s[j].cgpa);

                c = 1;
 
                
                break;
            }
            
        }
        printf("\n");
    }
    if (c == 0)
    {
        printf("Student not found.\n");
    }
    
}

// Main
int main()
{
    
    int choice;
    while (1)
    {
        printf("\nStudent Record Database\n");
        printf("-----------------------\n");
        printf("1. Add Student Details.\n");
        printf("2. Find Student by Roll Number.\n");
        printf("3. Find Student by First Name.\n");
        printf("4. Find the Student Details by Course ID.\n");
        printf("5. Delete a Student.\n");
        printf("6. Update Student Data.\n");
        printf("7. Exit.\n");
        printf("Choose your task: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        addstudent();
        numofstudents();
            break;
            case 2:
            fs_roll();
            break;            
            case 3:
            fs_fname();
            break;
            case 4:
            fscrsid();
            break;
            case 5:
            delete();
            numofstudents();
            break;
            case 6:
            update();
            break;
            case 7:
            exit(0);
            break;

        default:
            break;
        }
       
        
    }   
    return 0;
}