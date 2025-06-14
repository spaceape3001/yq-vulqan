////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Controller.hpp>
#include <yq/tensor/Tensor33.hpp>

namespace yq::tachyon {
    
    class KeyPressEvent;
    class KeyRepeatEvent;
    class KeyReleaseEvent;
    class GamepadAxisEvent;
    class GamepadPressEvent;
    class GamepadZeroEvent;
    class SetTargetCommand;

    /*! \brief Primitive 3D space controller
    
        This allows for a camera (or object) to be moved in 3D space 
        using the keyboard & gamepad.  (Well, these are what are supposed to be 
        going on, some flukes in the first cut)
        
        Key | Role
        ----+------
        W/S | Forward/Backward (relative)
        A/D | Left/Right (relative)
        Q/E | Up/Down (relative)
        U/O | +- Z
        J/L | +- Y
        I/K | += X
        
        num pad
        
        2/8 | Pitch
        4/6 | Yaw
        7/9 | Roll
        
        Gamepad
        -------
        
        Left Joystick -- translation
        Right Joystick -- orientation
        Tap Joystick buttons to zero-stop all motion
        Left button (high) -- change translation mode (ie axises)
        Right button (high) -- change orientation mode (ie HPR)
        
        \note This is intended as a fast implementation thing, to give an initial control.
        Recommendation is to transition to a better controller.
    */
    class Space³Controller : public Controller {
        YQ_TACHYON_DECLARE(Space³Controller, Controller);
    public:
    
        struct AxisData {
            double  input;
            double  gain;
        };
        
        struct KeyData {
            double  press;
            double  repeat;
        };
    
        struct Param : public Controller::Param {
            bool        keyboard    = true;
            bool        gamepad     = true;
            
            double      sangle      = 5.00; // amount to step angles
            double      slinear     = 1.00; // amount to step distances
            
            double      rangle      = 0.50; // fraction of steps to repeated angle keypresses
            double      rlinear     = 0.50; // fraction of steps to repeated linear keypresses

            double      gangle      = 0.10; // angle gains on gamepad
            double      glinear     = 0.01; // linear gains on gamepad

            Param(){}
        };
    
        Space³Controller(const Param&p={});
        Space³Controller(TypedID tgt, const Param&p={});
        ~Space³Controller();
    
        void    set_target(TypedID);
    
        static void init_info();
        
        TypedID target() const { return m_target; }
        
    protected:

        void    on_key_press(const KeyPressEvent&);
        void    on_key_repeat(const KeyRepeatEvent&);
        void    on_gamepad_axis(const GamepadAxisEvent&);
        void    on_gamepad_press(const GamepadPressEvent&);
        void    on_gamepad_zero(const GamepadZeroEvent&);
        void    on_set_target_command(const SetTargetCommand&);
        
        Execution   tick(const Context&);
        
    private:
    
        enum class Mode {
            HP,
            PR,
            RH,
            
            UV,
            VW,
            WU
        };
    
        //  ROLL is φ
        //  PITCH is θ
        //  YAW is λ (trying to avoid confusion in code that already has greek in it)
    
        //  These go into "move by" commands
        KeyData         m_uP;
        KeyData         m_uN;
        KeyData         m_wP;
        KeyData         m_wN;
        KeyData         m_vP;
        KeyData         m_vN;
    
        //  Go into add-shift position commands
        KeyData         m_xP;
        KeyData         m_xN;
        KeyData         m_yP;
        KeyData         m_yN;
        KeyData         m_zP;
        KeyData         m_zN;
        
        //  Go into rotate commands
        KeyData         m_φP;    // ROLL
        KeyData         m_φN;
        KeyData         m_θP;    // PITCH
        KeyData         m_θN;
        KeyData         m_λP;    // YAW
        KeyData         m_λN;
        
        AxisData        m_θ;     // joystick/pitch (gain is negative to get the axis/direction to match)
        AxisData        m_λ;
        AxisData        m_φ;
        AxisData        m_u;
        AxisData        m_v;
        AxisData        m_w;
        
        Mode            m_modeLeft      = Mode::UV;
        Mode            m_modeRight     = Mode::HP;
        
        TypedID         m_target;
        bool            m_joyLockout        = false;
        bool            m_keyboardEnable    = true;
        bool            m_gamepadEnable     = true;
    };
}


