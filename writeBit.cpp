#include <iostream>

using namespace std;

static int state = 0x1C;//0001 1100
int writeBit(bool mode, int offset)
{
    if (mode)
    {
        state = (mode << offset) | state;
    }
    else
    {
        state = ~(1 << offset) & state;
    }
    
    return state;
}

int main()
{
    printf("%s\n", "Turning off bits:");
    for (int i = 0; i < 16; i++)
	{
		int hexo = writeBit(false, i);
		printf("%X\n", hexo);
    }
	printf("%s\n", "Turning on bits:");
    for (int i = 0; i < 16; i++)
	{
		int hexo = writeBit(true, i);
		printf("%X\n", hexo);
    }
    return 0;
}