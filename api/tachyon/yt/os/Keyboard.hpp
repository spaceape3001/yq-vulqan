////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/typedef/keyboard.hpp>

namespace yq::tachyon {

    class Keyboard;
    
    /*! \brief Keyboard Information
    
        Information for keyboards.
    */
    class KeyboardInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all keyboard informations
        static const std::vector<const KeyboardInfo*>&    all();
        
        //! Standard constructor for the camera information
        KeyboardInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the keyboard is assumed to be simple....
    */

    /*! \brief A keyboard
    */
    class Keyboard : public Tachyon {
        YQ_TACHYON_INFO(KeyboardInfo);
        YQ_TACHYON_DATA(KeyboardData)
        YQ_TACHYON_SNAP(KeyboardSnap)
        YQ_TACHYON_DECLARE(Keyboard, Tachyon)
    public:    
    
        static void init_info();

        KeyboardID            id() const { return KeyboardID(UniqueID::id()); }

    protected:
    
        void        snap(KeyboardSnap&) const;

        //! Default constructor
        Keyboard(const Param&p = {});
        
        //! Default destructor
        ~Keyboard();
        
    };

}
YQ_TYPE_DECLARE(yq::tachyon::KeyboardID)
