#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  struct node *prev;
  struct node *next;
  char name[99];
  char nim[11];
  int ukt_level;
  int ukt_amount;
} node_t;

int main()
{
  int choice;
  node_t *head = NULL, *tail = NULL, *temp;

  do
  {
    printf("\nProgram Antrian Pembayaran UKT\n");
    printf("Menu:\n1. Tambah Antrian\n2. Proses Pembayaran\n3. Lihat Antrian\n4. Keluar\nPilihan: ");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
      node_t *new = (node_t *)malloc(sizeof(node_t));

      printf("\nInput data mahasiswa\n");
      printf("Nama: ");
      fgets(new->name, sizeof(new->name), stdin);
      new->name[strcspn(new->name, "\n")] = 0;

      printf("NIM: ");
      fgets(new->nim, sizeof(new->nim), stdin);
      new->nim[strcspn(new->nim, "\n")] = 0;
      getchar();

      printf("UKT: ");
      scanf("%d", &new->ukt_level);
      getchar();

      printf("Nominal: ");
      scanf("%d", &new->ukt_amount);
      getchar();

      if (tail == NULL)
      {
        head = tail = new;
      }
      else
      {
        head->prev = new;
        new->prev = tail;
        tail->next = new;
        tail = new;
        tail->next = head;
      }

      break;
    case 2:
      int amount;
      printf("\nProses pembayaran\n");
      printf("Nama: %s\n", head->name);
      printf("NIM: %s\n", head->nim);
      printf("UKT: %d\n", head->ukt_level);
      printf("Jumlah: %d\n", head->ukt_amount);
      printf("Masukkan jumlah bayar: ");
      scanf("%d", &amount);
      printf("%d - %d = %d", amount, head->ukt_amount, amount - head->ukt_amount);

      if (head == NULL)
      {
        printf("Data Kosong\n");
        break;
      }
      if (head == tail)
      {
        head = NULL;
        tail = NULL;
      }
      else
      {
        temp = head;
        node_t *temp2 = head->next;

        tail->next = temp2;
        temp2->prev = tail;
        head = temp2;

        temp = NULL;
      }

      break;
    case 3:
      printf("\nLihat antrian\n");
      temp = head;
      printf("Nama\t\t\tNIM\t\t\tUKT\t\t\tNominal\n");

      if (head == NULL)
      {
        printf("Data Kosong\n");
      }
      else if (head == tail)
      {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%d\n", temp->name, temp->nim, temp->ukt_level, temp->ukt_amount);
      }
      else
      {
        do
        {
          printf("%s\t\t\t%s\t\t\t%d\t\t\t%d\n", temp->name, temp->nim, temp->ukt_level, temp->ukt_amount);
          temp = temp->next;
        } while (temp != head);
      }
      break;
    case 4:
      printf("Keluar\n");
      break;
    default:
      printf("Pilihan salah\n");
    }
  } while (choice != 4);
}