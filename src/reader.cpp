#ifndef NASRd
#define NASRd

#include <iostream>
#include "NDArray.cpp"
#include "processor.cpp"

namespace nda
{
    using namespace std;
    bool inline isBlankChar(char c)
    {
        return (c == '\0' || c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f');
    }
    bool inline isSeparator(char c)
    {
        return (isBlankChar(c) || c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '!' || c == '&' || c == '|' || c == '^' || c == '~' || c == '?' || c == ':' || c == ';' || c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']' || c == '#' || c == '<' || c == '>' || c == '\'' || c == '\"' || c == '\\' || c == ',' || c == '.' || c == '`' || c == '@');
    }
    enum Keywords
    {
        // Not a keyword 不是关键字
        nkw,
        // Value type 类型
        BYTE,
        SHORT,
        INT,
        LONG,
        FLOAT,
        DOUBLE,
        VOID,
        // 引用
        THIS,
        // File association 文件关联
        IMPORT,
        PACKAGE,
        // 类
        CLASS,
        PRIVATE,
        PROTECTED,
        PUBLIC,
        // 结构
        STRUCT,
        ENUM,
        // 变量修饰
        CONST,
        // 跳转
        RETURN,
        GOTO,
        // 条件
        IF,
        ELSE,
        SWITCH,
        CASE,
        BREAK,
        DEFAULT,
        // 循环
        FOR,
        DO,
        WHILE,
        CONTINUE,
        // Coroutines and threads 协程与线程
        COROUTINE,
        THREAD,
        SLEEP,
    };
    enum Macro
    {
        // Not a macro 不是宏
        nam,
        // Macro 宏
        INCLUDE,
        DEFINE,
        IFDEF,
        IFNDEF,
        IFComEnv,
        ENDIF,
        // Use bytecode or code directly 直接使用字节码或代码
        DCODE,
    };
    /*
        Auxiliary class for reading nas source code
        用于读取nas源码的辅助类
    */
    class NASReader
    {
        long p;
        long siz;
        const char *a;

    public:
        NASReader(const unsigned char *ss, unsigned long len)
        {
            a = (const char *)ss;
            p = 0;
            siz = len;
        }

        bool nFinishReading() { return p < siz; } // Not finished reading 没有读完

        int pChar() // Determine whether a character is a macro or identifier
        {
            while (isBlankChar(a[p]))
                p++;
            if (a[p] == '#')
            {
                p++;
                return 1;
            }
            else if (a[p] == '(')
                return 2;
            else if (a[p] == ')')
                return 3;
            else if (a[p] == '{')
                return 4;
            else if (a[p] == '}')
                return 5;
            else if (a[p] == '[')
                return 6;
            else if (a[p] == ']')
                return 7;
            else if (a[p] == '.')
                return 8;
            else
                return 0;
        }

        string GetIdentifier()
        {
            string s = "";
            bool flag = false;
            for (int i = p; i < siz; i++)
            {
                if (flag || (flag = !isBlankChar(a[i])))
                {
                    if (isSeparator(a[i]))
                        break;
                    s += a[i];
                }
                else
                    p++;
            }
            return s;
        }

        Keywords GetKeywords() // 获取关键字
        {
            string s = GetIdentifier();
            if (s == "byte")
                return BYTE;
            else if (s == "short")
                return SHORT;
            else if (s == "int")
                return INT;
            else if (s == "long")
                return LONG;
            else if (s == "float")
                return FLOAT;
            else if (s == "double")
                return DOUBLE;
            else if (s == "void")
                return VOID;
            else if (s == "this")
                return THIS;
            else if (s == "import")
                return IMPORT;
            else if (s == "package")
                return PACKAGE;
            else if (s == "class")
                return CLASS;
            else if (s == "private")
                return PRIVATE;
            else if (s == "protected")
                return PROTECTED;
            else if (s == "public")
                return PUBLIC;
            else if (s == "struct")
                return STRUCT;
            else if (s == "enum")
                return ENUM;
            else if (s == "const")
                return CONST;
            else if (s == "return")
                return RETURN;
            else if (s == "goto")
                return GOTO;
            else if (s == "if")
                return IF;
            else if (s == "else")
                return ELSE;
            else if (s == "switch")
                return SWITCH;
            else if (s == "case")
                return CASE;
            else if (s == "break")
                return BREAK;
            else if (s == "default")
                return DEFAULT;
            else if (s == "for")
                return FOR;
            else if (s == "do")
                return DO;
            else if (s == "while")
                return WHILE;
            else if (s == "continue")
                return CONTINUE;
            else if (s == "coroutine")
                return COROUTINE;
            else if (s == "thread")
                return THREAD;
            else if (s == "sleep")
                return SLEEP;
            else
                return nkw;
        }

        Macro GetMacroW() // 获取宏关键字
        {
            string s = GetIdentifier();
            if (s == "include")
                return INCLUDE;
            else if (s == "define")
                return DEFINE;
            else if (s == "ifdef")
                return IFDEF;
            else if (s == "ifndef")
                return IFNDEF;
            else if (s == "ifcomenv")
                return IFComEnv;
            else if (s == "endif")
                return ENDIF;
            else if (s == "dcode")
                return DCODE;
            else
                return nam;
        }
    };
} // namespace nda

#endif