#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[99];
  int nim;
  int uts_score;
  int uas_score;
  int assignment_score;
  int quiz_score;
} student_t;

typedef struct
{
  float number;
  char letter;
} grade_t;

grade_t calculate_grade(student_t student)
{
  grade_t grade;

  grade.number = (student.uts_score * 3 / 10) + (student.uas_score * 3 / 10) + (student.assignment_score * 2 / 10) + (student.quiz_score * 2 / 10);

  if (grade.number >= 80 && grade.number < 100)
  {
    grade.letter = 'A';
  }
  else if (grade.number >= 65 && grade.number < 80)
  {
    grade.letter = 'B';
  }
  else if (grade.number >= 50 && grade.number < 65)
  {
    grade.letter = 'C';
  }
  else if (grade.number >= 30 && grade.number < 50)
  {
    grade.letter = 'D';
  }
  else if (grade.number >= 0 && grade.number < 30)
  {
    grade.letter = 'E';
  }
  else
  {
    grade.letter = 'F';
  }

  return grade;
}

int main()
{
  int student_amount;
  char buffer[99];

  printf("Ketik Jumlah Mahasiswa: ");
  scanf("%d", &student_amount);
  getchar();

  student_t students[student_amount];

  for (int i = 0; i < student_amount; i++)
  {
    if (i != 0)
    {
      getchar();
    }
    printf("Mhs-%d\n", i + 1);

    printf("Nama: ");
    fgets(students[i].name, sizeof(students[i].name), stdin);

    printf("NIM: ");
    scanf("%d", &students[i].nim);

    printf("Nilai UTS: ");
    scanf("%d", &students[i].uts_score);

    printf("Nilai UAS: ");
    scanf("%d", &students[i].uas_score);

    printf("Nilai Tugas: ");
    scanf("%d", &students[i].assignment_score);

    printf("Nilai Quiz: ");
    scanf("%d", &students[i].quiz_score);
  }

  for (int i = 0; i < student_amount; i++)
  {
    // Trim newline in name string
    students[i].name[strcspn(students[i].name, "\n")] = 0;

    grade_t student_grade = calculate_grade(students[i]);

    printf("\nNilai mutu %s: %.2f (%c)\n", students[i].name, student_grade.number, student_grade.letter);
  }

  return 0;
}