//Dominik Muc, 345952, Lista 7 zadanie 1

typedef struct Cezar Cezar, *CezarObject;

Cezar* new_cezar(char* message);
void destroy_cezar(Cezar* self);

int get_shift(Cezar* self);
void set_shift(Cezar* self, int shift);
void print_shifted(Cezar* self);
Cezar* clone_shifted(Cezar* base);
void set_message(Cezar* self, char* message);