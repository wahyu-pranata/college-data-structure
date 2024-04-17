#include <stdio.h>
#include <string.h>

typedef struct
{
  int number;
  char name[99];
  float practical_score;
  float theoretical_score;
  float avg_score;
} participant_t;

char confirmation_menu()
{
  char confirmation_choice;
  int first_attempt = 1;
  do
  {
    getchar();
    if (!first_attempt)
    {
      printf("Pilihan salah...");
    }
    printf("Mau lagi? (Y/T)\n");
    scanf("%c", &confirmation_choice);
    getchar();
    first_attempt = 0;

  } while (!(confirmation_choice == 'Y' || confirmation_choice == 'T'));
  return confirmation_choice;
}

int main()
{
  participant_t participant;
  char choice;

  do
  {
    printf("Ketik Data Peserta Kompetisi\n");

    printf("No. Peserta: ");
    scanf("%d", &participant.number);
    getchar();

    printf("Nama: ");
    fgets(participant.name, sizeof(participant.name), stdin);

    printf("Nilai Teori: ");
    scanf("%f", &participant.theoretical_score);

    printf("Nilai Praktek: ");
    scanf("%f", &participant.practical_score);

    float score_sum = participant.theoretical_score + participant.practical_score;
    printf("\nTotal Nilai: %.2f\n", score_sum);

    participant.avg_score = score_sum / 2.0;
    printf("Rata-rata Nilai: %.2f\n", participant.avg_score);

    if (score_sum / 2 >= 60)
    {
      printf("Status = Lulus!!\n");
    }
    else
    {
      printf("Status = Gagal!!\n");
    }
    choice = confirmation_menu();
  } while (choice == 'Y');
  return 0;
}