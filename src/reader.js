var fs = require("fs");


module.exports = {
    readfile: function (fileName, coding)
    {
        if (coding == null)
            coding = "utf-8";
        return fs.readFileSync(fileName, coding);
    }
}