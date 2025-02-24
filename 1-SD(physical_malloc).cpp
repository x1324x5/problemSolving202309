#include <cstdio>
using namespace std;
int T, n, opt, wsize, wid, cnt = 0, loc[5005], len[5005], iffree[5005];
struct node
{
    int l, r;
    node *next = NULL;
};
node *start;
int main()
{
    scanf("%d%d", &T, &n);
    start = new node;
    start->l = 0;
    start->r = n;
    while (T--)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d", &wsize);
            cnt++;
            node *temp = start;
            node *prev = NULL;
            bool allo = 0;
            int pos = 0;
            while (temp != NULL)
            {
                if (temp->r - temp->l > wsize)
                {
                    pos = temp->l;
                    temp->l += wsize;
                    allo = 1;
                    break;
                }
                else if (temp->r - temp->l == wsize)
                {
                    if (prev == NULL)
                    {
                        if (temp->next == NULL)
                        {
                            start = NULL;
                        }
                        else
                        {
                            start = temp->next;
                        }
                        pos = temp->l;
                    }
                    else
                    {
                        if (temp->next == NULL)
                        {
                            prev->next = NULL;
                        }
                        else
                        {
                            prev->next = temp->next;
                        }
                        pos = temp->l;
                    }
                    allo = 1;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if (allo == 1)
            {
                printf("%d\n", pos);
                loc[cnt] = pos;
                len[cnt] = wsize;
            }
            else
            {
                printf("malloc fail\n");
                loc[cnt] = -1;
            }
        }
        else if (opt == 2)
        {
            scanf("%d", &wid);
            if (wid > cnt || loc[wid] == -1 || iffree[wid] == 1)
            {
                printf("free fail\n");
            }
            else
            {
                node *temp = start;
                node *prev = NULL;
                if (start == NULL)
                {
                    node *newNode;
                    newNode = new node;
                    newNode->l = loc[wid];
                    newNode->r = loc[wid] + len[wid];
                    start = newNode;
                }
                else
                {
                    while (temp->l < loc[wid] && temp != NULL)
                    {
                        prev = temp;
                        temp = temp->next;
                        if (temp == NULL)
                        {
                            break;
                        }
                    }
                    if (temp == NULL)
                    {
                        if (prev->r < loc[wid])
                        {
                            node *newNode;
                            newNode = new node;
                            newNode->l = loc[wid];
                            newNode->r = loc[wid] + len[wid];
                            prev->next = newNode;
                        }
                        else
                        {
                            prev->r = loc[wid] + len[wid];
                        }
                    }
                    else if (prev == NULL)
                    {
                        if (temp->l > loc[wid] + len[wid])
                        {
                            node *newNode;
                            newNode = new node;
                            start = newNode;
                            newNode->l = loc[wid];
                            newNode->r = loc[wid] + len[wid];
                            newNode->next = temp;
                        }
                        else
                        {
                            temp->l = loc[wid];
                        }
                    }
                    else
                    {
                        if (prev->r < loc[wid] && temp->l > loc[wid] + len[wid])
                        {
                            node *newNode;
                            newNode = new node;
                            prev->next = newNode;
                            newNode->next = temp;
                            newNode->l = loc[wid];
                            newNode->r = loc[wid] + len[wid];
                        }
                        else if (prev->r == loc[wid] && temp->l > loc[wid] + len[wid])
                        {
                            prev->r = loc[wid] + len[wid];
                        }
                        else if (prev->r < loc[wid] && temp->l == loc[wid] + len[wid])
                        {
                            temp->l = loc[wid];
                        }
                        else
                        {
                            prev->r = temp->r;
                            prev->next = temp->next;
                        }
                    }
                }
                iffree[wid] = 1;
                printf("free success\n");
            }
        }
        else
        {
            node *temp = start;
            if (temp == NULL)
            {
                printf("NULL\n");
            }
            else
            {
                while (temp->next != NULL)
                {
                    printf("[%d,%d) ", temp->l, temp->r);
                    temp = temp->next;
                }
                printf("[%d,%d)\n", temp->l, temp->r);
            }
        }
    }
    return 0;
}