#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#define GetCurrentDir getcwd
#endif

using namespace std;
 
string GetCurrentWorkingDir(void) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  string current_working_dir(buff);
  return current_working_dir;
}
 
int main(){
  // Выводит текущую директорию
  cout << GetCurrentWorkingDir() << endl;

  DIR *dir;
  struct dirent *ent;
  
  // Открывает коталог
  dir = opendir(".");
    if(dir)
    {
        while((ent = readdir(dir)) != NULL)
        {
          switch (ent->d_type) {
            case DT_REG:
              // Файл
              printf( "%s %s\n","Regular " ,ent->d_name );
                break;
            case DT_DIR:
              // Папка
              printf( "%s %s\n","Directory " ,ent->d_name );
                break;
            default:
              printf( "%s %s\n", "├── " ,ent->d_name );
          }
        }
    }
    else
    {
        fprintf(stderr, "Error opening directory\n");
    }
  return 1;
}

