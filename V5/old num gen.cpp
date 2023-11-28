    map<int, int> generateLottonumbers(int t_numCount, int t_numRange)
    {
        for (int i = 1; i <= t_numRange; i++)
        {
            m_number_amount[i] = 0;
        }
        for (int i = 1; i <= t_numCount; i++)
        {
            int number = rand() % t_numRange + 1;
            m_number_amount[number]++;
        }
        return m_number_amount;
    }
