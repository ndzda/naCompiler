#include <map>
#include <set>
#include "NDArray.cpp"

namespace nda
{
    using namespace std;

    class NASProcessor
    {
        map<string, int> globalVariable; // global variable 全局变量
        map<string, int> constantTable;  // constant table 常量表
        map<string, int> functionTable;  // function table 函数表
        map<string, int> localVariable;  // Local variable 局部变量
        int aConstantCount;              // Anonymous constant count 匿名常量计数
        int aFunctionCount;              // Anonymous function count 匿名函数计数
        map<string, int> ReferenceTable; // File reference table 文件引用表
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
    };
} // namespace nda