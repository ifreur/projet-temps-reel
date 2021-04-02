
typedef struct Process
{
    int C;
    int D;
    int T;
}Process;

int* fp_compute(Process* myProcess,int lenProcess,int timeMax);
void read_file(char* filePath,Process** myProcess,int * lenProcess);
int* edf_compute(Process* myProcess,int lenProcess, int timeMax);