#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    float salary;
    int age;
    int gender;
} Record;

void setSalary(Record *record, float salary)
{
    record->salary = salary;
}

int main()
{
    Record record;
    strcpy(record.name, "Gabriel Lincoln");
    record.age = 19;
    record.gender = 1; // 1 representa "Masculino"

    setSalary(&record, 86);

    printf("Nome: %s, Salário: %.2f, Idade: %d, Sexo: %s\n", record.name, record.salary, record.age, record.gender ? "Masculino" : "Feminino");

    return 0;
}
