#include <stdio.h>
void searchStudent() {
    FILE *fp;
    char line[200];
    int searchRoll, found = 0;

    fp = fopen("marksheet.txt", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &searchRoll);

    while (fgets(line, sizeof(line), fp)) {

        if (scanf(line, "Roll Number: %d", &searchRoll) == 1) {
            printf("\nStudent Record Found!\n");
            found = 1;
        }

        if (found == 1) {
            printf("%s", line);
        }
    }

    if (found == 0) {
        printf("Student not found!\n");
    }

    fclose(fp);
}
void generateMarksheet() {
    char name[50];
    int roll;
    float maths, physics, chemistry, english, computer;
    float total, percentage;
    char grade;
    int pass = 1;

    printf("\nEnter Student Name: ");
    scanf("%49s", name);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("\nEnter Marks:\n");

    printf("Maths: ");
    scanf("%f", &maths);

    printf("Physics: ");
    scanf("%f", &physics);

    printf("Chemistry: ");
    scanf("%f", &chemistry);

    printf("English: ");
    scanf("%f", &english);

    printf("Computer: ");
    scanf("%f", &computer);

    if (maths < 0 || maths > 100 ||
        physics < 0 || physics > 100 ||
        chemistry < 0 || chemistry > 100 ||
        english < 0 || english > 100 ||
        computer < 0 || computer > 100) {

        printf("Invalid Marks!\n");
        return;
    }

    total = maths + physics + chemistry + english + computer;
    percentage = total / 5;

    if (maths < 33 || physics < 33 ||
        chemistry < 33 || english < 33 ||
        computer < 33) {
        pass = 0;
    }

    if (pass == 0)
        grade = 'F';
    else if (percentage >= 90)
        grade = 'A';
    else if (percentage >= 80)
        grade = 'B';
    else if (percentage >= 70)
        grade = 'C';
    else if (percentage >= 60)
        grade = 'D';
    else
        grade = 'E';

    printf("\n===== STUDENT MARKSHEET =====\n");
    printf("Name: %s\n", name);
    printf("Roll Number: %d\n", roll);
    printf("Total: %.2f/500\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);
    printf("Result: %s\n", pass ? "PASS" : "FAIL");

    FILE *fp = fopen("students.txt", "a");

    if (fp != NULL) {
        fprintf(fp, "%s %d %.2f %.2f %.2f %.2f %.2f\n",
                name, roll, maths, physics,
                chemistry, english, computer);

        fclose(fp);
        printf("\nRecord saved successfully!\n");
    }
    else {
        printf("File could not be opened!\n");
    }
}
void updateStudent() {
    FILE *fp, *temp;
    char name[50];
    int roll, searchRoll, found = 0;
    float maths, physics, chemistry, english, computer;
    float total, percentage;

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter roll number to update: ");
    scanf("%d", &searchRoll);

    while (fscanf(fp, "%49s %d %f %f %f %f %f",
                  name, &roll, &maths, &physics,
                  &chemistry, &english, &computer) == 7) {

        if (roll == searchRoll) {
            printf("Enter new marks:\n");

            printf("Maths: ");
            scanf("%f", &maths);

            printf("Physics: ");
            scanf("%f", &physics);

            printf("Chemistry: ");
            scanf("%f", &chemistry);

            printf("English: ");
            scanf("%f", &english);

            printf("Computer: ");
            scanf("%f", &computer);

            found = 1;
        }

        fprintf(temp, "%s %d %.2f %.2f %.2f %.2f %.2f\n",
                name, roll, maths, physics,
                chemistry, english, computer);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student marks updated!\n");
    else
        printf("Student not found!\n");
}
void deleteStudent() {
    FILE *fp, *temp;
    char name[50];
    int roll, searchRoll, found = 0;
    float maths, physics, chemistry, english, computer;

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &searchRoll);

    while (fscanf(fp, "%49s %d %f %f %f %f %f",
                  name, &roll, &maths, &physics,
                  &chemistry, &english, &computer) == 7) {

        if (roll == searchRoll) {
            found = 1;
            continue;
        }

        fprintf(temp, "%s %d %.2f %.2f %.2f %.2f %.2f\n",
                name, roll, maths, physics,
                chemistry, english, computer);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student record deleted successfully!\n");
    else
        printf("Student not found!\n");
}

int main() {

    char name[50];
    int roll;
    float maths, physics, chemistry, english, computer;
    char grade;
    int pass = 1;
    int n,i;

    printf("===== STUDENT MARKSHEET =====\n");
    printf("How many students? ");
    scanf("%d", &n);
    for (i=1;i<=n;i++) {
    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter roll number: ");
    scanf("%d", &roll);
    }
    printf("\nEnter marks out of 100:\n");

printf("Maths: ");
scanf("%f", &maths);

printf("Physics: ");
scanf("%f", &physics);

printf("Chemistry: ");
scanf("%f", &chemistry);

printf("English: ");
scanf("%f", &english);

printf("Computer: ");
scanf("%f", &computer);
float total, percentage;
total = maths + physics + chemistry + english + computer;

percentage = total / 5;

printf("\n===== RESULT =====\n");

printf("Total Marks: %.2f / 500\n", total);

printf("Percentage: %.2f%%\n", percentage);
if (maths < 33 || physics < 33 || chemistry < 33 || english < 33 || computer < 33) {
    pass = 0;
}

if (pass == 0) {
    grade = 'F';
}
else if (percentage >= 90) {
    grade = 'A';
}
else if (percentage >= 80) {
    grade = 'B';
}
else if (percentage >= 70) {
    grade = 'C';
}
else if (percentage >= 60) {
    grade = 'D';
}
else {
    grade = 'E';
}

printf("Grade: %c\n", grade);

if (pass == 1) {
    printf("Result: PASS\n");
}
else {
    printf("Result: FAIL\n");
}
printf("\n");
printf("====================================\n");
printf("          STUDENT MARKSHEET         \n");
printf("====================================\n");

printf("Student Name : %s\n", name);
printf("Roll Number  : %d\n", roll);

printf("------------------------------------\n");
printf("Subject              Marks\n");
printf("------------------------------------\n");

printf("Maths                %.2f\n", maths);
printf("Physics              %.2f\n", physics);
printf("Chemistry            %.2f\n", chemistry);
printf("English              %.2f\n", english);
printf("Computer             %.2f\n", computer);

printf("------------------------------------\n");
printf("Total Marks          %.2f/500\n", total);
printf("Percentage           %.2f%%\n", percentage);
printf("Grade                %c\n", grade);

printf("------------------------------------\n");

if (pass == 1)
    printf("Final Result: PASS\n");
else
    printf("Final Result: FAIL\n");

printf("====================================\n");
FILE *fp = fopen("marksheet.txt", "w");

if (fp == NULL) {
    printf("File could not be created!\n");
}
else {
    fprintf(fp, "===== STUDENT MARKSHEET =====\n");
    fprintf(fp, "Student Name: %s\n", name);
    fprintf(fp, "Roll Number: %d\n", roll);

    fprintf(fp, "Maths: %.2f\n", maths);
    fprintf(fp, "Physics: %.2f\n", physics);
    fprintf(fp, "Chemistry: %.2f\n", chemistry);
    fprintf(fp, "English: %.2f\n", english);
    fprintf(fp, "Computer: %.2f\n", computer);

    fprintf(fp, "Total: %.2f/500\n", total);
    fprintf(fp, "Percentage: %.2f%%\n", percentage);
    fprintf(fp, "Grade: %c\n", grade);

    if (pass == 1)
        fprintf(fp, "Result: PASS\n");
    else
        fprintf(fp, "Result: FAIL\n");

    fclose(fp);

    printf("\nMarksheet saved successfully!\n");
}
if (maths < 0 || maths > 100 ||
    physics < 0 || physics > 100 ||
    chemistry < 0 || chemistry > 100 ||
    english < 0 || english > 100 ||
    computer < 0 || computer > 100) {

    printf("Invalid marks! Enter marks between 0 and 100.\n");
    int choice;

printf("\n1. Generate Marksheet");
printf("\n2. Search Student");
printf("\nEnter your choice: ");
scanf("%d", &choice);

if (choice == 2) {
    searchStudent();
}
printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
printf("1. Generate Marksheet\n");
printf("2. Search Student\n");
printf("3. Update Marks\n");
printf("4. Delete Student\n");
printf("5. Exit\n");
}
int choice;

printf("\nEnter your choice: ");
scanf("%d", &choice);

switch (choice) {

    case 1:
       generateMarksheet();
        break;

    case 2:
        searchStudent();
        break;

    case 3:
        updateStudent();
        break;

    case 4:
        deleteStudent();
        break;

    case 5:
        printf("Thank you for using the system!\n");
        break;

    default:
        printf("Invalid choice!\n");
}

    return 0;
}