#include "runcmdbehide.h"
#include "windows.h"

void splitPath(const char *path, char *dir, char *name)
{
    int len = strlen(path);
    int i = len - 1;
    for (; i >= 0; i--)
    {
        if (path[i] == '\\' || path[i] == '/')
        {
            break;
        }
    }
    strncpy(dir, path, i+1);
    strncpy(name, path+i+1, len-i-1);
}

int main(int argc, char *argv[])
{
    /*  Windows API 同时提供了ANSI版本 和 Unicode版本（默认是Unicode）
         因为Windows命令行下一般是ANSI编码，因此此版本使用ANSI编码版本
         而使用Unicode方式时，字符串常量需要进行转换（默认是ANSI编码方式）
    */
    if (argc < 3)
    {
        MessageBoxA(NULL, ("Run your program background \nUsage: XXX  yourProgram  yourParameters！"),("Tips"), 0);
        //MessageBox(NULL, TEXT("Usage: XXX  yourProgram  yourParameters！"), TEXT("Tips"), 0);  //Unicode方式
        return 1;
    }

    char dir[256] = {0};
    char name[256] = {0};
    splitPath(argv[1], &dir[0], &name[0]);
    
    //MessageBoxA(NULL, LPCSTR(dir), NULL, 0);
    //MessageBoxA(NULL, LPCSTR(name), NULL, 0);
    //MessageBoxA(NULL, LPCSTR(), NULL, 0);
    //MessageBoxA(NULL, LPCSTR(), NULL, 0);

    ShellExecuteA(NULL, ("open"), LPCSTR(name), LPCSTR(argv[2]), LPCSTR(dir), SW_HIDE);
    //ShellExecute(NULL, TEXT("open"), LPCWSTR(argv[1]), LPCWSTR(argv[2]), NULL, SW_HIDE);  //Unicode方式

    //ShellExecute其实是简单调用 cmd /c "===yourProgram====yourParameters====" 来进行调用！
}
