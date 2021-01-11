#include <map>
#include <set>
#include "NDArray.cpp"
#include "reader.cpp"

namespace nda
{
    using namespace std;

    class NASProcessor
    {
        struct nasClass
        {
        };

        map<string, int> globalVariable;  // global variable 全局变量
        map<string, int> constantTable;   // constant table 常量表
        map<string, int> functionTable;   // function table 函数表
        map<string, int> structureTable;  // Structure table 结构体表
        map<string, nasClass> classTable; // Class table 类表
        map<string, int> localVariable;   // Local variable 局部变量
        map<string, int> localMacro;      // Local macro 局部宏
        int aConstantCount;               // Anonymous constant count 匿名常量计数
        int aFunctionCount;               // Anonymous function count 匿名函数计数
        map<string, int> ReferenceTable;  // File reference table 文件引用表
    public:
        NASProcessor()
        {
            globalVariable = map<string, int>();
            constantTable = map<string, int>();
            functionTable = map<string, int>();
            localVariable = map<string, int>();
            aConstantCount = 0;
            aFunctionCount = 0;
            ReferenceTable = map<string, int>();
        }

        void pSSent() // Processing single sentences 处理单句语句
        {
            while (0)
            {
            }
        }

        void loadReader(NASReader src)
        {
            while (src.nFinishReading())
            {
                int x = pChar();
                if (x == 0 || x == 2) // 执行语句
                {
                }
                else if (x == 1) // 宏定义
                {
                }
            }
        }
    };
} // namespace nda