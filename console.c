#include <stdio.h>
#include <windows.h>

void initconsole(void){
    FILE* bogus;
    (void) AllocConsole();
    freopen_s(&bogus, "CONOUT$", "w", stdout);
    freopen_s(&bogus, "CONOUT$", "w", stderr);
}
