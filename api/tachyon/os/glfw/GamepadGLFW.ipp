////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/glfw/GamepadGLFW.hpp>
#include <tachyon/os/GamepadInfoWriter.hpp>
#include <tachyon/command/gamepad/GamepadZeroCommand.hpp>
#include <tachyon/os/glfw/glfw.hpp>
#include <tachyon/event/gamepad/GamepadAxisEvent.hpp>
#include <tachyon/event/gamepad/GamepadHatEvent.hpp>
#include <tachyon/event/gamepad/GamepadPressEvent.hpp>
#include <tachyon/event/gamepad/GamepadReleaseEvent.hpp>
#include <tachyon/event/gamepad/GamepadZeroEvent.hpp>
#include <tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::GamepadGLFW)

namespace yq::tachyon {
    GamepadGLFW::GamepadGLFW(int jid, const Param&p) : Gamepad(p), m_joystick(jid)
    {
    }
    
    GamepadGLFW::~GamepadGLFW()
    {
    }

    void      GamepadGLFW::on_zero_command(const GamepadZeroCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        m_rezero    = true;
    }

    Execution GamepadGLFW::setup(const Context&ctx)
    {
        if(!m_init){
            glfwSetJoystickUserPointer(m_joystick, this);
            if(const char* z = glfwGetJoystickName(m_joystick)){
                m_name = z;
            }
            if(const char* z = glfwGetJoystickGUID(m_joystick)){
                m_guid = z;
            }
            int count   = 0;
            if(const float* f = glfwGetJoystickAxes(m_joystick, &count); f && count){
                m_axes.resize(count);
                for(int n=0;n<count;++n){
                    m_axes[n].zero  = m_axes[n].raw = f[n];
                }
            }
            if(const unsigned char* p = glfwGetJoystickButtons(m_joystick, &count); p && count){
                m_buttons.reserve(count);
                for(int n=0;n<count;++n){
                    m_buttons.push_back(p[n] == GLFW_PRESS);
                }
            }
            if(const unsigned char* p = glfwGetJoystickHats(m_joystick, &count); p && count){
                m_hats.reserve(count);
                for(int n=0;n<count;++n){
                    m_hats.push_back((HatState) p[n]);
                }
            }
            
            m_init = true;
        }
        return Gamepad::setup(ctx);
    }

    void      GamepadGLFW::snap(GamepadSnap&sn) const
    {
        Gamepad::snap(sn);
        sn.name = m_name;
        sn.guid = m_guid;
        sn.axes.reserve(m_axes.size());
        for(const Axis& a : m_axes)
            sn.axes.push_back(a.value);
        sn.buttons  = m_buttons;
        sn.hats     = m_hats;
    }
    
    Execution GamepadGLFW::teardown(const Context&ctx)
    {
        if(m_init){
            glfwSetJoystickUserPointer(m_joystick, nullptr);
            m_init  = false;
        }
        return Gamepad::teardown(ctx);
    }

    float   GamepadGLFW::Axis::operator()(float x) const
    {
        if(x >= zero){
            return (x-zero) / (1.0 - zero);
        } else {
            return (x-zero) / (zero + 1.0);
        }
    }

    Execution GamepadGLFW::tick(const Context&ctx) 
    {
        int count   = 0;
        if(const float* axes = glfwGetJoystickAxes(m_joystick, &count); axes && (count == (int) m_axes.size())){
            if(m_rezero){
                for(size_t n=0;n<(size_t) count; ++n){
                    Axis&   a   = m_axes[n];
                    a.zero  = a.raw = axes[n];
                    a.value = 0.;
                    send(new GamepadAxisEvent({.source=*this}, n, 0., 0.));
                }
                send(new GamepadZeroEvent({.source=*this}));
                mark();
                m_rezero    = false;
            } else {
                for(size_t n=0;n<(size_t) count; ++n){
                    Axis&   a   = m_axes[n];
                    float f   = axes[n];
                    if(f != a.raw){
                        float  x   = a(f);
                        float del  = x - a.value;
                        a.value = x;
                        a.raw   = f;
                        send(new GamepadAxisEvent({.source=*this}, n, x, del));
                        mark();
                    }
                }
            }
        }
        
        if(const unsigned char* p = glfwGetJoystickButtons(m_joystick, &count); p && (count == (int) m_buttons.size())){
            for(size_t n=0;n<(size_t) count; ++n){
                bool    st  = p[n] == GLFW_PRESS;
                if(st != m_buttons[n]){
                    m_buttons[n] = st;
                    if(st){
                        send(new GamepadPressEvent({.source=*this}, n));
                    } else {
                        send(new GamepadReleaseEvent({.source=*this}, n));
                    }
                    mark();
                }
            }
        }
        
        if(const unsigned char* p = glfwGetJoystickHats(m_joystick, &count); p && (count == (int) m_hats.size())){
            for(size_t n=0;n<(size_t) count; ++n){
                HatState    st  = (HatState) p[n];
                if(st != m_hats[n]){
                    m_hats[n]   = st;
                    send(new GamepadHatEvent({.source=this}, n, st));
                    mark();
                }
            }
        }
    
        return {};
    }
    
    void GamepadGLFW::init_info()
    {
        auto w = writer<GamepadGLFW>();
        w.description("GLFW Gamepad");
        w.slot(&GamepadGLFW::on_zero_command);
    }
}
