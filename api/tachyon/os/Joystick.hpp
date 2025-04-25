////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/joystick.hpp>

namespace yq::tachyon {

    class Joystick;
    
    /*! \brief Joystick Information
    
        Information for joysticks.
    */
    class JoystickInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all joystick informations
        static const std::vector<const JoystickInfo*>&    all();
        
        //! Standard constructor for the camera information
        JoystickInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the joystick is assumed to be simple....
    */

    /*! \brief A joystick
    */
    class Joystick : public Tachyon {
        YQ_TACHYON_INFO(JoystickInfo);
        YQ_TACHYON_DATA(JoystickData)
        YQ_TACHYON_SNAP(JoystickSnap)
        YQ_TACHYON_DECLARE(Joystick, Tachyon)
    public:    
    
        /*
            We *MIGHT* want to divide up the camera into position, 
            lens, etc... or that's a later development on a dedicated
            camera.  (class DynamicJoystick, StandardJoystick, etc???)
        */
    

        static void init_info();

        JoystickID            id() const { return JoystickID(UniqueID::id()); }

    protected:
    
        void        snap(JoystickSnap&) const;

        //! Default constructor
        Joystick(const Param&p = {});
        
        //! Default destructor
        ~Joystick();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::JoystickID)
