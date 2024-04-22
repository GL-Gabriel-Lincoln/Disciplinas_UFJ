#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char firstName[50];
    char lastName[50];
    float gradePointAverage;
} Student;

typedef struct
{
    char firstName[50];
    char lastName[50];
    float salary;
} Employee;

Student *getStudentByName(char *firstName, char *lastName, Student *students, int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i].firstName, firstName) == 0 && strcmp(students[i].lastName, lastName) == 0)
        {
            return &students[i];
        }
    }
    return NULL;
}

Employee *getEmployeeByName(char *firstName, char *lastName, Employee *employees, int numEmployees)
{
    for (int i = 0; i < numEmployees; i++)
    {
        if (strcmp(employees[i].firstName, firstName) == 0 && strcmp(employees[i].lastName, lastName) == 0)
        {
            return &employees[i];
        }
    }
    return NULL;
}

void giveRaiseToEmployeesWithHighGPA(Student *students, Employee *employees, int numStudents, int numEmployees)
{
    for (int i = 0; i < numEmployees; i++)
    {
        Employee *employee = &employees[i];
        printf("Processando o funcionário %s %s...\n", employee->firstName, employee->lastName);

        Student *student = getStudentByName(employee->firstName, employee->lastName, students, numStudents);

        if (student != NULL)
        {
            printf("Encontrado um registro de estudante correspondente para %s %s com GPA %.2f.\n", student->firstName, student->lastName, student->gradePointAverage);
            if (student->gradePointAverage > 3.0)
            {
                employee->salary *= 1.10;
                printf("O funcionário %s %s recebeu um aumento de 10%%. Novo salário: %.2f\n", employee->firstName, employee->lastName, employee->salary);
            }
        }
        else
        {
            printf("Nenhum registro de estudante correspondente encontrado para o funcionário %s %s.\n", employee->firstName, employee->lastName);
        }
    }
}

int main()
{
    Student students[] = {
        {"Igor", "Silva", 3.5},
        {"Carla", "Oliveira", 2.8},
    };
    int numStudents = sizeof(students) / sizeof(students[0]);

    Employee employees[] = {
        {"Igor", "Silva", 2000.0},
        {"Carla", "Costa", 2500.0},
    };
    int numEmployees = sizeof(employees) / sizeof(employees[0]);

    giveRaiseToEmployeesWithHighGPA(students, employees, numStudents, numEmployees);

    return 0;
}