#include "pch.h"

record* read_base(FILE* f) {
    record* tmp = new record();
    fread((record*)tmp, sizeof(record), 1, f);
    return tmp;
}