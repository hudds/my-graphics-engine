#include <core/logger.h>
#include <core/asserts.h>


int main(){
    KFATAL("teste %f", 1.2);
    KERROR("teste %f", 1.3);
    KWARN("teste %f", 1.4);
    KINFO("teste %f", 1.5);
    KTRACE("teste %f", 1.6);
    KASSERT(1 == 1);
    return 0;
}
