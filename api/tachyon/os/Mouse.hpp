////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/mouse.hpp>

namespace yq::tachyon {

    class Mouse;
    
    /*! \brief Mouse Information
    
        Information for mouses.
    */
    class MouseInfo : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all mouse informations
        static const std::vector<const MouseInfo*>&    all();
        
        //! Standard constructor for the camera information
        MouseInfo(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
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
        YQ_TACHYON_INFO(MouseInfo);
        YQ_TACHYON_DATA(MouseData)
        YQ_TACHYON_SNAP(MouseSnap)
        YQ_TACHYON_DECLARE(Mouse, Tachyon)
    public:    
    
        static void init_info();

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
