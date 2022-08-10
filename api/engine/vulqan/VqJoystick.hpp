////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <span>
#include <string_view>
#include <vector>

namespace yq {
    namespace engine {

        /*! \brief Convience wrapper around GLFW Joysticks
        */
        struct VqJoystick {
            const uint8_t  id = 0;
          
            //! Vector of all gamepads
            static std::vector<VqJoystick>      gamepads();
            
            //! Vector of all joysticks
            static std::vector<VqJoystick>      joysticks();
            
            //! State of the joystick/gamepad axes
            std::span<const float>          axes() const;
            
            //! Number of axes
            unsigned int                    axes_count() const;

            //! Number of buttons
            unsigned int                    button_count() const;

            //! State of the joystick/gamepad buttons
            std::span<const unsigned char>  buttons() const;

            //! Unique combo of manufacturer/model
            std::string_view                guid() const;

            //! State of the joystick/gamepad hats (axis summaries?)
            std::span<const unsigned char>  hats() const;
            
            //! TRUE if this is a gamepad
            bool                            is_gamepad() const;
            
            //! TRUE if this joystick is present
            bool                            is_present() const;
            
            /*! \brief Name of the device
            
                \note COPY this result into a std::string if you need to retain 
                it for any length of time.
            */
            std::string_view                name() const;
            
            //! Sets user data for joystick (it's global)
            void                            set_user_data(void*);
            
            //! Gets user data for joystick (it's global)
            void*                           user_data() const;
        };

    }
}

