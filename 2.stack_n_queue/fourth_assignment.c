#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char title[99];
  int pages;
  char publisher[99];
} book_t;

void push_stack(book_t book_stack[], int max_height, int *current_height)
{
  if (*current_height == max_height)
  {
    printf("Tumpukan penuh!\n");
    return;
  }

  printf("Ketik Judul Buku: ");
  fgets(book_stack[*current_height].title, sizeof(book_stack[*current_height].title), stdin);
  book_stack[*current_height].title[strcspn(book_stack[*current_height].title, "\n")] = 0;

  printf("Jumlah Halaman: ");
  scanf("%d", &book_stack[*current_height].pages);
  getchar();

  printf("Penerbit: ");
  fgets(book_stack[*current_height].publisher, sizeof(book_stack[*current_height].publisher), stdin);
  book_stack[*current_height].publisher[strcspn(book_stack[*current_height].publisher, "\n")] = 0;

  printf("Buku berhasil ditambah!\n");
  *current_height += 1;
}

void pop_stack(book_t book_stack[], int *current_height)
{
  if (*current_height == 0)
  {
    printf("Tidak ada buku...\n");
    return;
  }
  book_t top_book = book_stack[*current_height - 1];
  printf("Buku dengan judul %s sudah diambil\n", top_book.title);
  *current_height -= 1;
}

char confirmation_menu()
{
  char confirmation_choice;
  int first_attempt = 1;
  do
  {
    if (!first_attempt)
    {
      printf("Coba lagi...");
    }
    printf("Apakah anda yakin? (Y/T)\n");
    scanf("%c", &confirmation_choice);
    getchar();
    first_attempt = 0;

  } while (!(confirmation_choice == 'Y' || confirmation_choice == 'T'));
  return confirmation_choice;
}

int main()
{
  int choice;
  int max_height;
  int current_height;
  char menu_choice;

  printf("Program tumpukan buku : \n");
  printf("Ketik jumlah maksimum tumpukan buku : \n");
  scanf("%d", &max_height);
  getchar();

  book_t book_stack[max_height];
  do
  {
    printf("\nMenu: \n");
    printf("1. Tambah Buku\n");
    printf("2. Ambil Buku\n");
    printf("3. Keluar program\n");
    printf("Pilihan: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
      push_stack(book_stack, max_height, &current_height);
      break;
    case 2:
      if (confirmation_menu() == 'Y')
      {
        pop_stack(book_stack, &current_height);
      }
      break;
    case 3:
      if (confirmation_menu() == 'Y')
      {
        printf("Terima Kasih\n");
        break;
      }
    }

  } while (choice != 3);
}