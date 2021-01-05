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
        map<string, int> localVariable;  // Local variable 局部变量
    public:
        NASProcessor()
        {
        }
    };
} // namespace nda