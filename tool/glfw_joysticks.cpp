////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <GLFW/glfw3.h>
#include <iostream>

void    errorFunction(int error_code, const char* description)
{
    std::cerr << "GLFW(" << error_code << "): " << description << "\n";
}

int main(int argc, char* argv[])
{
    glfwSetErrorCallback(errorFunction);
    if(!glfwInit())
        return false;

    int count   = 0;
    for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
        if(glfwJoystickPresent(jid))
            ++count;
    }
    
    std::cout << "Found " << count << " joystick(s)\n\n";
    for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
        if(!glfwJoystickPresent(jid))
            continue;
    
        std::cout << "Joystick #" << jid << " ("; 
        if(const char* z = glfwGetJoystickName(jid)){
            std::cout << z;
        }
        std::cout << " or GUID=";
        if(const char* z = glfwGetJoystickGUID(jid)){
            std::cout << z;
        }
        std::cout << ")";
        if(glfwJoystickIsGamepad(jid))
            std::cout << " GAMEPAD!";
        std::cout  << "\n  axes:";

        int axesCount   = 0;
        const float* axes = glfwGetJoystickAxes(jid, &axesCount);
        if(axes){
            for(int i=0;i<axesCount; ++i)
                std::cout << " " << axes[i];
        }
        std::cout << "\n  buttons:";
        int btnCount = 0;
        const unsigned char* buttons = glfwGetJoystickButtons(jid, &btnCount);
        if(buttons){
            for(int i=0;i<btnCount;++i)
                std::cout << ' ' << (int) buttons[i];
        }
        int hatCount    = 0;
        const unsigned char* hats = glfwGetJoystickHats(jid, &hatCount);
        if(hats){
            for(int i=0;i<hatCount;++i)
                std::cout << ' ' << (int) hats[i];
        }
        std::cout << '\n';
    }
    
    glfwTerminate();
    return 0;
}
