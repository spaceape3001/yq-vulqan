////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Controller.hpp>
#include <yq/tensor/Tensor33.hpp>

namespace yq::tachyon {
    
    class KeyPressEvent;
    class KeyRepeatEvent;
    class KeyReleaseEvent;
    class GamepadAxisEvent;
    class GamepadPressEvent;
    class GamepadZeroEvent;

    /*! \brief Primitive 3D space controller
    
        This allows for a camera (or object) to be moved in 3D space 
        using the keyboard.  (Well, these are what are supposed to be 
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
    */
    class Space³Controller : public Controller {
        YQ_TACHYON_DECLARE(Space³Controller, Controller);
    public:
    
        Space³Controller(TypedID);
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
        
        Execution   tick(const Context&);
        
    private:
    
    
        struct KeyData {
            double press;
            double repeat;
        };
        
        struct AxisData {
            double  input   = 0;
            double  gain    = 0.;
        };
    
        //  ROLL is φ
        //  PITCH is θ
        //  YAW is λ (trying to avoid confusion in code that already has greek in it)
    
        //  These go into "move by" commands
        KeyData         m_uP    = {  1.,  0.5 };
        KeyData         m_uN    = { -1., -0.5 };
        KeyData         m_wP    = {  1.,  0.5 };
        KeyData         m_wN    = { -1., -0.5 };
        KeyData         m_vP    = {  1.,  0.5 };
        KeyData         m_vN    = { -1., -0.5 };
    
        //  Go into add-shift position commands
        KeyData         m_xP    = {  1.,  0.5 };
        KeyData         m_xN    = { -1., -0.5 };
        KeyData         m_yP    = {  1.,  0.5 };
        KeyData         m_yN    = { -1., -0.5 };
        KeyData         m_zP    = {  1.,  0.5 };
        KeyData         m_zN    = { -1., -0.5 };
        
        //  Go into rotate commands
        KeyData         m_φP    = {  5.,  2.5 };    // ROLL
        KeyData         m_φN    = { -5., -2.5 };
        KeyData         m_θP    = {  5.,  2.5 };    // PITCH
        KeyData         m_θN    = { -5., -2.5 };
        KeyData         m_λP    = {  5.,  2.5 };    // YAW
        KeyData         m_λN    = { -5., -2.5 };
        
        AxisData        m_θ     = { 0., 0.1 };
        AxisData        m_λ     = { 0., 0.1 };
        
        TypedID         m_target;
        bool            m_joyLockout = false;
    };
}


