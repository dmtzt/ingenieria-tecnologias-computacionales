int divisibles(int inf, int sup)
{
    int count = 0;
    
    for (int i = inf; i <= sup; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            count++;
    }

    return count;
}