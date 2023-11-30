#include <stdio.h>

#define MAX_LINES 100

int main()
{
  int i, j, num_lines, num_new_people;
  int lines[MAX_LINES];
  scanf("%d%d", &num_lines, &num_new_people);
  for (i = 0; i < num_lines; i++)
  {
    scanf("%d", &lines[i]);
  }
  int smallest;
  int smallest_index = -1;
  for (i = 0; i < num_new_people; i++)
  {
    smallest = 101;
    for (j = 0; j < num_lines; j++) 
    {
      if (lines[j] < smallest) {
        smallest = lines[j];
        smallest_index = j;
      }
    }
    printf("%d\n", smallest);
    lines[smallest_index] += 1;
  }
  return 0;
}
