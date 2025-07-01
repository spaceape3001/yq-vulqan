////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/gamepad.hpp>

namespace yq::tachyon {

    class Gamepad;
    
    /*! \brief Gamepad Information
    
        Information for joysticks.
    */
    class GamepadMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all joystick informations
        static const std::vector<const GamepadMeta*>&    all();
        
        //! Standard constructor for the camera information
        GamepadMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
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
    class Gamepad : public Tachyon {
        YQ_TACHYON_INFO(GamepadMeta);
        YQ_TACHYON_DATA(GamepadData)
        YQ_TACHYON_SNAP(GamepadSnap)
        YQ_TACHYON_DECLARE(Gamepad, Tachyon)
    public:    
    
        /*
            We *MIGHT* want to divide up the camera into position, 
            lens, etc... or that's a later development on a dedicated
            camera.  (class DynamicGamepad, StandardGamepad, etc???)
        */
    

        static void init_meta();

        GamepadID            id() const { return GamepadID(UniqueID::id()); }

    protected:
    
        void        snap(GamepadSnap&) const;

        //! Default constructor
        Gamepad(const Param&p = {});
        
        //! Default destructor
        ~Gamepad();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::GamepadID)
