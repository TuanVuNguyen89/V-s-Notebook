inline int ReadInt() /// đọc số nhanh
{
    bool Neg = false;
    char c;
    while (c = getchar(), c < '0' || c > '9')
        if (c == '-')
            Neg = !Neg;
    int x = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return Neg ? -x : x;
}

inline void WriteInt(int x) ///viết số nhanh
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    n = ReadInt();
    for (int i = 0; i < n; ++i)
    {
        p[i].x = ReadInt();
        p[i].y = ReadInt();
    }
}
