let reader = require("./reader.js");
let char = require("./char.js");

var tree = {};// 结构图

function ct(code,t)// 递归处理
{
    var idStart,inId;// identifier start 标识符开始位置
    for(var i=0,Li=code.length;i<Li;i++)
    {
        var c=code[i];
        if(inId)
        {
            if(char.isSeparator(code)||char.isBlankChar)
            {
                
            }
        }
        else
        {}
    }
}


ct(reader.readfile(process.argv[2]),tree);
