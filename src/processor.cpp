#include <map>
#include <set>
#include "util.cpp"
#include "reader.cpp"

namespace nda
{
    using namespace std;

    class NASProcessor
    {
        struct nasClass
        {
        };
        struct nasVariable
        {
        };
        struct nasFunction
        {
        };

        map<string, nasVariable> globalVariable;  // global variable 全局变量
        map<string, int> constantTable;   // constant table 常量表
        map<string, int> functionTable;   // function table 函数表
        map<string, int> structureTable;  // Structure table 结构体表
        map<string, nasClass> classTable; // Class table 类表
        map<string, int> localMacro;      // Local macro 局部宏
        int aConstantCount;               // Anonymous constant count 匿名常量计数
        int aFunctionCount;               // Anonymous function count 匿名函数计数
        map<string, int> ReferenceTable;  // File reference table 文件引用表

        // Current state 当前状态
        bool inFunction; // Inside the function 在函数内
        string functionName;// Function name 函数名
        string className;// Class name 类名
        map<string, int> localVariable;   // Local variable 局部变量
        
    public:
        NASProcessor()
        {
            globalVariable = map<string, nasVariable>();
            constantTable = map<string, int>();
            functionTable = map<string, int>();
            structureTable = map<string, int>();
            classTable = map<string, nasClass>();
            localVariable = map<string, int>();
            aConstantCount = 0;
            aFunctionCount = 0;
            ReferenceTable = map<string, int>();
        }

        void pExpression(string s) // Processing expression 处理表达式
        {
        }

        void pSSent(NASReader *src) // Processing single sentences 处理单句语句
        {
            while (0)
            {
            }
        }

        char loadReader(NASReader *src)
        {
            while (src->nFinishReading())
            {
                int x = src->pChar();
                if (x == 0 || x == 2) // 执行语句
                {
                    pSSent(src);
                }
                else if (x == 1) // 宏定义
                {
                    Macro mw = src->GetMacroW();
                    if (mw == nam) // 不是宏关键字
                    {
                        infoL("Wrong macro definition.");
                        return 1;
                    }
                }
                else // 非法语句
                {
                    infoL("Wrong macro definition.");
                    return -1;
                }
            }
            return 0;
        }
    };
} // namespace nda