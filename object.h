#ifndef _object_h
#define _object_h

typedef enum{
    NORTH,SOUTH,EAST,WEST
}Direction;

typedef  struct{
    char *description;
    int (*init)(void *self);
    void(*describe)(void *self);
    void(*destroy)(void *self);
    void *(*move)(void *self,Direction direction);
    int (*attack)(void *self,int damage);
}Object;

int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self,Direction direction);
int Object_attack(void *self,int damage);
void *Object_new(int size,Object proto,char *description);''


#define NEW(T,N) object_new(sizeof(T),T##Proto,N)
#define _(N) proto.N
#endif