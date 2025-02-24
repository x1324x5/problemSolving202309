#include <cstdio>
#include <cstring>
using namespace std;
int trans[256];
int aft[65540];
int n;
unsigned char ba[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
void change(unsigned char a[])
{
    n = strlen((char *)a);
    int check = 0, cnt = 0;
    if (a[n - 1] == '=')
    {
        check++;
    }
    if (a[n - 2] == '=')
    {
        check++;
    }
    for (int i = 0; i < n - check; i += 4)
    {
        if (i == n - 4 && check > 0)
        {
            if (check == 1)
            {
                cnt = i / 4 * 3;
                aft[cnt] = (trans[a[i]] << 2 | (trans[a[i + 1]] >> 4)) % 256;
            }
            else
            {
                cnt = i / 4 * 3;
                aft[cnt] = (trans[a[i]] << 2 | (trans[a[i + 1]] >> 4)) % 256;
                aft[cnt + 1] = (trans[(a[i + 1] << 4) & 255]) % 256;
            }
        }
        else
        {
            cnt = i / 4 * 3;
            aft[cnt] = (trans[a[i]] << 2 | (trans[a[i + 1]] >> 4)) % 256;
            aft[cnt + 1] = ((trans[a[i + 1]] << 4) | (trans[a[i + 2]] >> 2)) % 256;
            aft[cnt + 2] = ((trans[a[i + 2]] << 6) | trans[a[i + 3]]) % 256;
        }
    }
    n = n / 4 * 3 - check;
}
unsigned char a[(int)2e7];
int p[140] = {};
int main()
{
    scanf("%s", a);
    for (int i = 0; i < 64; ++i)
    {
        trans[ba[i]] = i;
    }
    change(a);
    for (int i = 0; i < 128; ++i)
    {
        scanf("%d", &p[i]);
    }
    for (int ik = 1; ik <= 512; ik = ik * 2)
    {
        int temp = n / ik;
        int check[ik][260] = {};
        int index[ik][260] = {};
        for (int i = 0; i < n; ++i)
        {
            check[i % ik][aft[i]]++;
        }
        int hugeflag = 0;
        for (int i = 0; i < ik; ++i)
        {
            int bigflag = 0;
            for (int j = 0; j < 256; ++j)
            {
                if (check[i][j] == 0)
                {
                    continue;
                }
                int flag = 0;
                for (int k = 0; k < 128; ++k)
                {
                    if (p[k] * temp == check[i][j] * 128)
                    {
                        flag = 1;
                        index[i][j] = k;
                        break;
                    }
                }
                if (flag == 0)
                {
                    bigflag = 1;
                    break;
                }
            }
            if (bigflag == 1)
            {
                hugeflag = 1;
                break;
            }
        }
        if (hugeflag == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                printf("%c", (char)index[i % ik][aft[i]]);
            }
            return 0;
        }
    }
    return 0;
}