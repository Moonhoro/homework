int countStudents(int *students, int studentsSize, int *sandwiches, int sandwichesSize)
{
    int table[2] = {0};
    for (int i = 0; i < studentsSize; i++)
    {
        if (students[i] == 0)
            table[0]++;
        else
            table[1]++;
    }
    for (int i = 0; i < sandwichesSize; i++)
    {
        if (sandwiches[i] == 0)
            table[0]--;
        else
            table[1]--;
        if (table[0] < 0 || table[1] < 0)
        {
            table[0]++;
            break;
        }
    }
    return table[0] + table[1];
}