////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Joystick.hpp>
#include <tachyon/os/HatState.hpp>

namespace yq::tachyon {

    class JoystickZeroCommand;
    
    class JoystickGLFW : public Joystick {
        YQ_TACHYON_DECLARE(JoystickGLFW, Joystick)
    public:
        JoystickGLFW(int, const Param&p = Param());
        ~JoystickGLFW();
        
        static void init_info();
        
        int glfw() const { return m_joystick; }
        
        virtual Execution setup(const Context&);
        virtual Execution tick(const Context&);
        virtual Execution teardown(const Context&);
        
    protected:
        void        snap(JoystickSnap&) const;
        
        void        on_zero_command(const JoystickZeroCommand&);

    private:
        const int                       m_joystick;
        bool                            m_init  = false;
        std::string                     m_name, m_guid;

        struct Axis {
            float   raw     = 0.;   //!< As read in
            float   zero    = 0.;   //!< Our resting "zero" point
            float   value   = 0.;   //!< Computed value
            
            float   operator()(float x) const;
        };

        std::vector<Axis>       m_axes;
        std::vector<bool>       m_buttons;
        std::vector<HatState>   m_hats;
        bool                    m_rezero    = false;
    };

}
