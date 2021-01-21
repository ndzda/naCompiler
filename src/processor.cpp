#include <map>
#include <set>
#include <vector>
#include "util.cpp"
#include "reader.cpp"

namespace nda
{
    using namespace std;

    class NASProcessor
    {
        struct symbol
        {
            string s; // Symbol string 符号字符串
            int sp;   // special(Keyword type, operator type) 特殊(关键字种类,运算符种类)
            enum t    // Type 类型
            {
                Operator,    // Operator 运算符
                Keyword,     // Keyword 关键字
                Delimiter,   // Separator(semicolon) 分隔符(分号)
                CurlyBraces, // curly braces 大括号
                Quotes,      // Double quotes or single quotes 双引号或单引号
            } type;
        };

        struct mOrder // Intermediate order 中间指令
        {
            vector<string> id; // identifier 标识符
            enum t             // Type 类型
            {
                Assignment,        // =  Assignment 赋值
                Rounding,          // =l Rounding 取整
                BitwiseAssignment, // = Bitwise assignment 按位赋值
                BitwiseNegation,   // =~ Bitwise negation 按位取反
                Negate,            // Negate 取反
                AddUp,             // Add up 相加
                Subtract,          // Subtract 相减
                Multiply,          // Multiply 相乘
                Divide,            // Divide 相除
                remainder,         // remainder 余数
                BitShiftLeft,      // Bit shift left 按位左移
                BitShiftRight,     // Bit shift right 按位右移
                BitwiseAnd,        // Bitwise and 按位与
                BitwiseOr,         // Bitwise or 按位或
                BitwiseXOR,        // Bitwise XOR 按位异或
                equal,             // equal 等于
                notEqualTo,        // not equal to 不等于
                moreThanThe,       // more than the 大于
                LessThan,          // Less than 小于
                greaterOrEqualTo,  // greater or equal to 大于等于
                LessThanOrEqualTo, // Less than or equal to 小于等于
            } type;
        };

        struct nasClass
        {
        };
        struct nasVariable
        {
        };
        struct nasFunction
        {
            vector<symbol> l = vector<symbol>();
            vector<symbol> l = vector<symbol>();
        };

        map<string, nasVariable> globalVariable; // global variable 全局变量
        map<string, int> constantTable;          // constant table 常量表
        map<string, nasFunction> functionTable;  // function table 函数表
        map<string, int> structureTable;         // Structure table 结构体表
        map<string, nasClass> classTable;        // Class table 类表
        map<string, int> localMacro;             // Local macro 局部宏
        int aConstantCount;                      // Anonymous constant count 匿名常量计数
        int aFunctionCount;                      // Anonymous function count 匿名函数计数
        map<string, int> ReferenceTable;         // File reference table 文件引用表

        // Current state 当前状态
        bool inFunction;                // Inside the function 在函数内
        string functionName;            // Function name 函数名
        string className;               // Class name 类名
        map<string, int> localVariable; // Local variable 局部变量

    public:
        NASProcessor()
        {
            globalVariable = map<string, nasVariable>();
            constantTable = map<string, int>();
            functionTable = map<string, nasFunction>();
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