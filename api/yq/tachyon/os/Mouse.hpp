////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/mouse.hpp>

namespace yq::tachyon {

    class Mouse;
    
    /*! \brief Mouse Information
    
        Information for mouses.
    */
    class MouseMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all mouse informations
        static const std::vector<const MouseMeta*>&    all();
        
        //! Standard constructor for the camera information
        MouseMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the mouse is assumed to be simple....
    */

    /*! \brief A mouse or similar tracking device (trackball, etc)
    
        A mouse, presumably, controls a cursor (or other thing)
    */
    class Mouse : public Tachyon {
        YQ_TACHYON_META(MouseMeta);
        YQ_TACHYON_DATA(MouseData)
        YQ_TACHYON_SNAP(MouseSnap)
        YQ_TACHYON_DECLARE(Mouse, Tachyon)
    public:    
    
        static void init_meta();

        MouseID            id() const { return MouseID(UniqueID::id()); }

    protected:
    
        void        snap(MouseSnap&) const;

        //! Default constructor
        Mouse(const Param&p = {});
        
        //! Default destructor
        ~Mouse();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::MouseID)
