#include <core/logger.h>
#include <core/asserts.h>

// TODO: test
#include <platform/platform.h>

int main(){
    KFATAL("teste %f", 1.2);
    KERROR("teste %f", 1.3);
    KWARN("teste %f", 1.4);
    KINFO("teste %f", 1.5);
    KTRACE("teste %f", 1.6);
    platform_state state;
    if(platform_startup(&state, "My Engine Test", 100, 100, 1280, 720)){
        while(TRUE){
           platform_pump_messages(&state);
       }
    }
    platform_shutdown(&state);
    return 0;
}
