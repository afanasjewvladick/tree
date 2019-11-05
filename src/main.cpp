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
  // выводить текущую директорию
  cout << GetCurrentWorkingDir() << endl;
  // Открывает коталог
  DIR *dir = opendir(".");
    if(dir)
    {
        struct dirent *ent;
        while((ent = readdir(dir)) != NULL)
        {
          printf( "%s %s\n", "├── " ,ent->d_name );
        }
    }
    else
    {
        fprintf(stderr, "Error opening directory\n");
    }
  return 1;
}

