////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <math/vector/Vector2.hpp>

namespace yq {
    namespace tachyon {
        struct Input;
        using Command = Input;

        /*! \brief Input is precisely that, user input, a command
        */
        struct Input {
            //!  Data (interpretation by code)
            union {
                uint32_t    u32     = 0;
                int32_t     i32;
                float       f32;
                double      f64;
                Vector2F    v2;
                Vector3F    v3;
            };

            //!     op code
            uint16_t                code    = 0;
            
            union {
            
                //! Low parameter... usage defined by code
                uint16_t            low     = 0; 
                struct {
                    //!     Flags (usage defined by code)
                    uint8_t         flags;
                    
                    //!     Extra (usage defined by code)
                    uint8_t         extra;
                };
            };
            

            // Standard codes
            enum class Code : uint16_t {
                NULL                = 0,
                
                /*! Key pressed
                
                    flags   -- modifiers active
                    extra   -- keyboard (if known), 0xFF otherwise
                    u32     -- scan code
                */
                KEY_DOWN,

                /*! Key repeated
                
                    flags   -- modifiers active
                    extra   -- keyboard (if known), 0xFF otherwise
                    u32     -- scan code
                */
                KEY_CONT,

                /*! Key released
                
                    flags   -- modifiers active
                    extra   -- keyboard (if known), 0xFF otherwise
                    u32     -- scan code
                */
                KEY_UP,
                
                /*! \brief Mouse down
                
                    flags   -- modifiers active
                    extra   -- mouse ID (or 0xFF)
                    pos     -- mouse position
                */
                    
                MOUSE_DOWN,
                
                /*! \brief Mouse up
                
                    flags   -- modifiers active
                    extra   -- mouse ID (or 0xFF)
                    pos     -- mouse position
                */
                    
                MOUSE_UP,
                
                /*! \brief Mouse move
                
                    flags   -- modifiers active & buttons pressed
                    extra   -- mouse ID (or 0xFF),
                    delta   -- motion since last time
                */
                MOUSE_MOVE,
                
                /*! \brief Joystick axis
                
                    flags   -- axis ID
                    extra   -- joystick ID (or 0xFF)
                    f32     -- position
                */
                JOY_AXIS,
                
                /*! \brief Joystick button down
                
                    flags   -- button ID
                    extra   -- joystick ID (or 0xFF)
                */
                JOY_DOWN,
                
                /*! \brief Joystick button up
                
                    flags   -- button ID
                    extra   -- joystick ID (or 0xFF)
                */
                JOY_UP,
                
                /*! \brief Step
                
                    v2/v3   -- amount to move
                    extra   -- part/thing ID
                */
                STEP,
                
                /*! \brief Step in the x-direction
                
                    f32    -- amount to move
                    extra   -- part/thing ID
                */
                STEP_X,
                
                /*! \brief Step in the y-direction

                    f64    -- amount to move
                    extra   -- part/thing ID
                */
                STEP_Y,
                
                /*! \brief Step in the z-direction

                    f64     -- amount to move
                    extra   -- part/thing ID
                */
                STEP_Z,
                
                /*! \brief General velocity command

                    v2/v3   -- amount to speed
                    extra   -- part ID
                */
                VELOCITY,
                
                
                /*! \brief Velocity in the x-direction

                    f64     -- amount to speed
                    id      -- part ID
                */
                VEL_X,

                /*! \brief Velocity in the y-direction

                    f64     -- amount to speed
                    id      -- part ID
                */
                VEL_Y,

                /*! \brief Velocity in the z-direction

                    f64     -- amount to speed
                    id      -- part ID
                */
                VEL_Z,
                
                /*! \brief General Acceleration command
                    v2/v3   -- amount to accelerate
                    id      -- part ID
                */
                ACCELERATION,

                /*! \brief Acceleration in the x-direction
                    f64     -- amount to accelerate
                    id      -- part ID
                */
                ACCEL_X,
                
                /*! \brief Acceleration in the y-direction
                */
                ACCEL_Y,
                
                /*! \brief Acceleration in the z-direction
                */
                ACCEL_Z,
                
                /*! \brief Rotate (step) around the x-direction
                */
                ROTATE_X,
                
                /*! \brief Rotate (step) around the y-direction
                */
                ROTATE_Y,
                
                /*! \brief Rotate (step) around the z-direction
                */
                ROTATE_Z,
                
                /*! \brief Spin (step) around the x-axis 
                
                */
                SPIN_X,
                
                /*! \brief Spin (step) around the y-axis 
                
                */
                SPIN_Y,
                
                /*! \brief Spin (step) around the z-axis 
                
                */
                SPIN_Z,
                
                /*! \brief Refresh (whatever)
                */
                REFRESH,
                
                /*! \brief Help Request
                */
                HELP,
                
                /*! \brief Home
                */
                HOME,
                
                STOP,
                
                BRAKE,
                
                
                /*! \brief End of standard list, custom codes after this
                */
                USER_CODE
            
            };
        };
        
    }
}
