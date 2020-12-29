#include <cstring>

bool startOfLine = true; // 在行首

bool inline isBlankChar(unsigned char c)
{
    return (c == '\0' || c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f');
}

const int macroNum = 2, macroMaxLen = 10;
const unsigned char macroT[macroNum][macroMaxLen] = {
    "include", // Reference a file 引用一个文件
    "define"   // Definition identifier replacement 定义标识符替换
};
int processingMacro(const unsigned char *s, int &p)
{
    bool flag[macroNum];
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < macroMaxLen; i++)
    {
        for (int j = 0; j < macroNum; j++)
            if (!flag[j])
            {
                if (macroT[j][i] == 0)
                {
                    p+=i;
                    return j;
                }
                else if (s[i] != macroT[j][i])
                    flag[j] = true;
            }
    }
    return -1;
}

int pretreatment(const unsigned char *src, long len)
{
    for (int i = 0; i < len; i++)
    {
        if (startOfLine)
        {
            if (!isBlankChar(src[i]))
            {
                startOfLine = false;
                if (src[i] == '#')
                    switch (processingMacro(src + i, i))
                    {
                    case 0: // include
                        break;
                    case 1: // define
                        break;
                    }
            }
        }
        else if (src[i] == '\n')
            startOfLine = true;
    }
}