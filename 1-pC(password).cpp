#include <cstring>
#include <iostream>
const int N = 2e5 + 3;
const int M = N * 8;
using namespace std;
char a[N] = {}, b[N] = {}, c[N] = {};
int m0[N] = {0}, s0[N] = {0}, change[N] = {0}, k[N] = {0}, sc[N] = {0}, alter[N] = {0};
int bim[M] = {0}, cim[M] = {0}, flag[N] = {0};
int main()
{

    cin.getline(a, N);
    cin.getline(b, N);
    cin.getline(c, N);
    int na = strlen(a), nb = strlen(b), nc = strlen(c);
    int moddd = 0;
    if (na % 4 != 0 || nc % 4 != 0)
    {
        return 0;
    }
    for (int i = 0; i < na; ++i)
    {
        if (a[i] == '=')
        {
            break;
        }
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            s0[i] = a[i] - 65;
        }
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            s0[i] = a[i] - 71;
        }
        if (a[i] >= '0' && a[i] <= '9')
        {
            s0[i] = a[i] + 4;
        }
        if (a[i] == '+')
        {
            s0[i] = 62;
        }
        if (a[i] == '/')
        {
            s0[i] = 63;
        }
        moddd += 1;
    }
    int countt = moddd * 3 / 4;
    int cnt = 0;
    for (int i = 0; i < na; ++i)
    {
        cnt = 0;
        while (cnt <= 5)
        {
            bim[i * 6 + cnt] = ((s0[i] >> (5 - cnt)) & 1);
            cnt++;
        }
    }
    int ans = 0;
    for (int i = 0; i < nb; ++i)
    {
        ans = 0;
        for (int j = 0; j < 8; ++j)
        {
            ans = (ans << 1) + bim[8 * i + j];
        }
        change[i] = ans;
    }
    for (int i = 0; i < countt; ++i)
    {
        m0[i] = b[i];
        if (change[i] < m0[i])
        {
            k[i] = change[i] + 256 - m0[i];
        }
        else
        {
            k[i] = change[i] - m0[i];
        }
    }
    int count = 0, modd = 0;
    for (int i = 0; i < nc; ++i)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
        {
            sc[i] = c[i] - 65;
        }
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            sc[i] = c[i] - 71;
        }
        if (c[i] >= '0' && c[i] <= '9')
        {
            sc[i] = c[i] + 4;
        }
        if (c[i] == '+')
        {
            sc[i] = 62;
        }
        if (c[i] == '/')
        {
            sc[i] = 63;
        }
        if (c[i] == '=')
        {
            break;
        }
        modd++;
    }
    for (int i = 0; i < nc; ++i)
    {
        cnt = 0;
        while (cnt <= 5)
        {
            cim[i * 6 + cnt] = ((sc[i] >> (5 - cnt)) & 1);
            cnt++;
        }
    }
    count = modd * 3 / 4;
    for (int i = 0; i < count; ++i)
    {
        ans = 0;

        for (int j = 0; j < 8; ++j)
        {
            ans = (ans << 1) + cim[8 * i + j];
        }
        if (ans - k[i % nb] < 0)
        {
            alter[i] = ans - k[i % countt] + 256;
        }
        else
        {
            alter[i] = ans - k[i % countt];
        }
    }

    for (int i = 0; i < count; ++i)
    {
        printf("%c", (alter[i] % 256));
    }
    return 0;
}