#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STRING_THERE_ARE_DUPLICATE_SNOWFLAKES "Twin snowflakes found.\n"
#define STRING_SNOWFLAKES_ARE_UNIQUE "No two snowflakes are alike.\n"
#define LEN_SNOWFLAKE 6
#define LARGEST_POSSIBLE_SUM 6000

int get_num_snowflakes_from_stdin(void)
{
    int num_snowflakes; // this is allocated on the stack
    scanf("%d", &num_snowflakes);
    return num_snowflakes;
}

bool they_are_equal_right(int sf1[LEN_SNOWFLAKE], int sf2[LEN_SNOWFLAKE], int sf2_offset)
{
    int sf1_tip, sf2_tip, sf2_index;
    for (int i = 0; i < LEN_SNOWFLAKE; i++)
    {
        sf1_tip = sf1[i];

        sf2_index = (i + sf2_offset) % LEN_SNOWFLAKE;
        sf2_tip = sf2[sf2_index];

        if (sf1_tip != sf2_tip)
            return false;
    }
    return true;
}

bool they_are_equal_left(int sf1[LEN_SNOWFLAKE], int sf2[LEN_SNOWFLAKE], int sf2_offset)
{
    int sf1_tip, sf2_tip, sf2_index;
    for (int i = 0; i < LEN_SNOWFLAKE; i++)
    {
        sf1_tip = sf1[i];

        sf2_index = sf2_offset - i;
        if (sf2_index < 0)
            sf2_index = sf2_index + LEN_SNOWFLAKE;
        sf2_tip = sf2[sf2_index];

        if (sf1_tip != sf2_tip)
            return false;
    }
    return true;
}

bool they_are_equal(int sf1[LEN_SNOWFLAKE], int sf2[LEN_SNOWFLAKE])
{
    for (int o = 0; o < LEN_SNOWFLAKE; o++)
    {
        if (they_are_equal_right(sf1, sf2, o))
            return true;
        if (they_are_equal_left(sf1, sf2, o))
            return true;
    }
    return false;
}

int get_hash(int snowflake[LEN_SNOWFLAKE])
{
    int sum;
    for (int i = 0; i < LEN_SNOWFLAKE; i++)
    {
        sum += snowflake[i];
    }
    return sum;
}

typedef struct Entry {
    int snowflake[LEN_SNOWFLAKE];
    struct Entry * next;
} Entry;

void populate_snowflakes_from_stdin(Entry * snowflakes[LARGEST_POSSIBLE_SUM], int num_snowflakes)
{
    int hash;
    Entry * snowflake;
    for (int _ = 0; _ < num_snowflakes; _++)
    {
        snowflake = malloc(sizeof(Entry));
        for (int j = 0; j < LEN_SNOWFLAKE; j++)
        {
            scanf("%d", &snowflake->snowflake[j]);
        }
        hash = get_hash(snowflake->snowflake);
        snowflake->next = snowflakes[hash];
        snowflakes[hash] = snowflake;
    }
}

int main(void)
{
    // TODO: refactor to only compare similar snowflakes:
    //   - the tips add up to the same amount
    //   - try to skip any array (hash map) slots with one or fewer elements stored
    int num_snowflakes = get_num_snowflakes_from_stdin();
    Entry * snowflakes[LARGEST_POSSIBLE_SUM]; // 48MB of memory, 6 million slots 
    populate_snowflakes_from_stdin(snowflakes, num_snowflakes);

    // for (int i = 0; i < num_snowflakes; i++)
    //     for (int j = i + 1; j < num_snowflakes; j++)
    //         if (they_are_equal(snowflakes[i], snowflakes[j]))
    //         {
    //             printf(STRING_THERE_ARE_DUPLICATE_SNOWFLAKES);
    //             return 0;
    //         }

    // printf(STRING_SNOWFLAKES_ARE_UNIQUE);
    return 0;
}
