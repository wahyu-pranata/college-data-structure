#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[99];
  float weight;
  float height;
} patient_t;

int main()
{
  int amount;

  printf("Ketik jumlah pasien: ");
  scanf("%d", &amount);
  getchar();

  patient_t patients[amount];

  for (int i = 0; i < amount; i++)
  {
    if (i != 0)
    {
      printf("\n");
      // Consume new line that returned by previous fgets
      getchar();
    }
    printf("Data %d\n", i + 1);
    printf("Nama: ");
    fgets(patients[i].name, sizeof(patients[i].name), stdin);
    // Trim newline in name string
    patients[i].name[strcspn(patients[i].name, "\n")] = 0;

    printf("Berat badan: ");
    scanf("%f", &patients[i].weight);

    printf("Tinggi badan: ");
    scanf("%f", &patients[i].height);
  }

  for (int i = 0; i < amount; i++)
  {
    printf("Nama: %s\n", patients[i].name);
    printf("Berat: %.2f\n", patients[i].weight);
    printf("Tinggi: %f\n", patients[i].height);
    printf("\n");
  }

  patient_t lowest_weight = patients[0];
  patient_t lowest_height = patients[0];
  float weight_sum = 0;
  float height_sum = 0;

  for (int i = 0; i < amount; i++)
  {
    if (patients[i].weight < lowest_height.weight)
    {
      lowest_height = patients[i];
    }

    if (patients[i].height < lowest_height.height)
    {
      lowest_height = patients[i];
    }

    height_sum += patients[i].height;
    weight_sum += patients[i].weight;
  }

  printf("Berat terendah: %.2f (%s)\n", lowest_weight.weight, lowest_weight.name);
  printf("Rata-rata berat: %.2f\n", weight_sum / amount);
  printf("Tinggi terendah: %.2f (%s)\n", lowest_height.height, lowest_height.name);
  printf("Rata-rata tinggi: %.2f\n", height_sum / amount);

  return 0;
}