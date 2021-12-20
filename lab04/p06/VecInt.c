#include "VecInt.h"
#include <stdlib.h>

void VecInt_createEmpty(struct VecInt *self)
{
    self->data = NULL;
    self->sz = 0;
    self->cp = 0;
}

void VecInt_pushBack(struct VecInt *self, int x)
{
    if (self->sz == self->cp)
    {
        self->cp = (self->cp == 0) ? 1 : 2 * self->cp;
        int *newData = (int *)malloc((sizeof(int) * self->cp));
        for (size_t i = 0; i < self->sz; ++i)
        {
            newData[i] = self->data[i];
        }
        free(self->data);
        self->data = newData;
    }
    self->data[self->sz++] = x;
}

void VecInt_destroy(struct VecInt *self)
{
    free(self->data);
    self->sz = 0;
    self->cp = 0;
}