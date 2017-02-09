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
    /*  Windows API ͬʱ�ṩ��ANSI�汾 �� Unicode�汾��Ĭ����Unicode��
         ��ΪWindows��������һ����ANSI���룬��˴˰汾ʹ��ANSI����汾
         ��ʹ��Unicode��ʽʱ���ַ���������Ҫ����ת����Ĭ����ANSI���뷽ʽ��
    */
    if (argc < 3)
    {
        MessageBoxA(NULL, ("Run your program background \nUsage: XXX  yourProgram  yourParameters��"),("Tips"), 0);
        //MessageBox(NULL, TEXT("Usage: XXX  yourProgram  yourParameters��"), TEXT("Tips"), 0);  //Unicode��ʽ
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
    //ShellExecute(NULL, TEXT("open"), LPCWSTR(argv[1]), LPCWSTR(argv[2]), NULL, SW_HIDE);  //Unicode��ʽ

    //ShellExecute��ʵ�Ǽ򵥵��� cmd /c "===yourProgram====yourParameters====" �����е��ã�
}
