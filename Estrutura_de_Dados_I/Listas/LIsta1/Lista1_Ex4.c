#include <stdio.h>

typedef struct
{
    char name[81];
    char registration[8];
    char class;
    float test[3];
} Student;

void lerAluno(Student *student) {
    printf("Digite o nome do aluno: ");
    fgets(student->name, 81, stdin);

    printf("Digite a matricula do aluno: ");
    fgets(student->registration, 8, stdin);

    printf("Digite a turma do aluno: ");
    scanf(" %c", &student->class);

    for (int i = 0; i < 3; i++) {
        printf("Digite a nota da prova %d: ", i+1);
        scanf("%f", &student->test[i]);
    }
}

float calcularMedia(Student student) {
    return (student.test[0] + student.test[1] + student.test[2]) / 3;
}

void imprimirCadastro(Student student) {
    printf("Nome: %s", student.name);
    printf("Matricula: %s", student.registration);
    printf("Turma: %c\n", student.class);
    printf("Notas: %.2f %.2f %.2f\n", student.test[0], student.test[1], student.test[2]);
    printf("Media: %.2f\n", calcularMedia(student));
}

float calculateClassAverage(Student students[], int num_students, char class) {
    float total = 0;
    int count = 0;
    for (int i = 0; i < num_students; i++) {
        if (students[i].class == class) {
            total += calcularMedia(students[i]);
            count++;
        }
    }
    return count > 0 ? total / count : 0;
}

int main() {
    Student students[2];
    int num_students = 2;

    for (int i = 0; i < num_students; i++) {
        printf("Digite os dados do aluno %d:\n", i+1);
        lerAluno(&students[i]);
        getchar();
    }

    float class_average = calculateClassAverage(students, num_students, 'A');
    printf("A média final da turma A é: %.2f\n", class_average);

    return 0;
}
