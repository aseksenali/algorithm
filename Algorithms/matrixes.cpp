#include <iostream>
#include <cmath>
#include <cstdlib>

static int NN;
static int SIZE;
static int *m_addr=NULL;
static int lin(int,int);
static char ch_coord(int, int);
int L2_RESULT;

int create_matr(int N) 
{
    NN = N;
    SIZE = pow(N, 2) - N * ((N - 1) / 2);
    if((m_addr=(int *)malloc(SIZE*sizeof(int))) == NULL)
        return L2_RESULT = -1;
    else
        return L2_RESULT = 0;
}

int close_matr(void)
{ 
    if (m_addr!=NULL)
    {
        delete(m_addr);
        m_addr = NULL;
        return L2_RESULT = 0;
    }
    else return L2_RESULT = -1;
}

int is_zero(int x, int y) 
{
    if (x < y && y % 2 == 0) 
    {
        return 1;
    } 
    else if (x > y && y % 2 == 1) 
    {
        return 1;
    }

    return 0;
}

int read_matr(int x, int y) 
{
    if (ch_coord(x, y)) return 0;
    if (x == y) return 1;
    return is_zero(x, y) ? 0 : m_addr[lin(x, y)];
}

int write_matr(int x, int y, int value) 
{
    if (ch_coord(x, y)) return 0;
    if (is_zero(x, y)) return 0;
    else return m_addr[lin(x, y)] = value;
}

static int lin(int x, int y) 
{
    if (x == 0 && y == 0) return 0;
    if (x < y) return (y + 1) / 2 + ((NN + 1) / 2 + 1) * x;
    else if (x > y) return y / 2 + ((NN + 1) / 2 + 1) * x;
    else return 0;
}

static char ch_coord(int x, int y) 
{
    if((m_addr == NULL) || (x > SIZE) || (y > SIZE) || (x < 0) || (y < 0))
    return L2_RESULT = -1;
    return L2_RESULT = 0;
}

int main() {
    int R,i,j,m;
    int op;
    std::cout << ("Enter matrix dimension>");
    std::cin >> R;
    /* Создание матрицы*/
    if (create_matr(R))
    { 
        std::cout << ("Matrix creation error \n");
        exit(0);
    }
    /* Заполнение матрицы*/
    for(m=j=0; j<R; j++)
        for(i=0; i<R; i++)
            write_matr(i,j,++m);
    while(1)
    /* Вывод матрицы на экран*/
    { 
        for(j=0; j<R; j++)
        { 
            for(i=0; i<R; i++)
            std::cout << read_matr(i,j) << "\t";
            std::cout << "\n";
        }
    
        std::cout << "0 - exit \n1 - read \n2 - write\n>";
        std::cin >> op;
        switch (op)
        { 
            case 0:
                if(close_matr()) std::cout<<"Deleting error\n";
                else std::cout << ("Matrix have been destroyed \n");
                exit (0);
            case 1: 
            case 2:
                std::cout << ("Enter row number>");
                std::cin >> i;
                std::cout << ("Enter column number>");
                std::cin >> j;
                if (op==2)
                {
                    std::cout << ("Enter value>");
                    std::cin >> m;
                    write_matr(j,i,m);
                    if(L2_RESULT<0) std::cout << ("Write error\n");
                }
                else
                { 
                    m=read_matr(j,i);
                    if(L2_RESULT<0) std::cout << ("Write error\n");
                    else printf("Read: %d\n",m);
                }
                std::cout << ("Press key\n");
                break;
        }
    }
}