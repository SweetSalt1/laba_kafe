typedef struct {
    char name[100];
    float price;
    float weight;
    char description[100];
} Dish;

extern Dish dish[100];
extern int n;

int load_database(const char *filename, Dish dishArray[100], int *n);
int Save(const char *filename, Dish dishArray[100], int n);
void copyStr(char *suda, const char *otsuda);
void Init();
void Print();
int Add(char *name, float price, float weight, char *description);
int Edit(int index, char *name, float price, float weight, char *description);
int Remuve(int index);
void Search(float minPrice, float maxPrice, float minWeight, float maxWeight);
