//Dominik Muc, 345952, Lista 7 zadanie 1

typedef struct Cezar *CezarObject;

CezarObject new_cezar(const char* message);
void destroy_cezar(CezarObject self);

int get_shift(const CezarObject self);
void set_shift(CezarObject self, const int shift);
void print_shifted(const CezarObject self);
CezarObject clone_shifted(const CezarObject base);
int set_message(CezarObject self, const char* message);