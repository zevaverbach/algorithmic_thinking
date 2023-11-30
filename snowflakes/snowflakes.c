#include <stdio.h>
#include <stdbool.h>

#define STRING_THERE_ARE_DUPLICATE_SNOWFLAKES "Twin snowflakes found.\n"
#define STRING_SNOWFLAKES_ARE_UNIQUE "No two snowflakes are alike.\n"
#define LEN_SNOWFLAKE 6

int get_num_snowflakes_from_stdin(void)
{
    int num_snowflakes;
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

void populate_snowflakes_from_stdin(int snowflakes[][LEN_SNOWFLAKE], int num_snowflakes)
{
    for (int i = 0; i < num_snowflakes; i++)
        for (int j = 0; j < LEN_SNOWFLAKE; j++)
            scanf("%d", &snowflakes[i][j]);
}

int main(void)
{
    // TODO: refactor to only compare similar snowflakes:
    //   - the tips add up to the same amount
    //   - try to skip any array (hash map) slots with one or fewer elements stored
    int num_snowflakes = get_num_snowflakes_from_stdin();
    int snowflakes[num_snowflakes][LEN_SNOWFLAKE];
    populate_snowflakes_from_stdin(snowflakes, num_snowflakes);

    for (int i = 0; i < num_snowflakes; i++)
        for (int j = i + 1; j < num_snowflakes; j++)
            if (they_are_equal(snowflakes[i], snowflakes[j]))
            {
                printf(STRING_THERE_ARE_DUPLICATE_SNOWFLAKES);
                return 0;
            }

    printf(STRING_SNOWFLAKES_ARE_UNIQUE);
    return 0;
}
