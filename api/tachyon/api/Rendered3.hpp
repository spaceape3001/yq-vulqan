////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <yq/math/SimpleSpace.hpp>
#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <tachyon/api/Rendered.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>
#include <tachyon/api/3D.hpp>
#include <tachyon/typedef/bounds3.hpp>
#include <tachyon/typedef/camera3.hpp>
#include <tachyon/typedef/rendered3.hpp>
#include <tachyon/typedef/spatial3.hpp>

namespace yq::tachyon {
        
    /*! \brief Information for the render3D object
    */
    class Rendered³Info : public RenderedInfo {
    public:
        template <typename C> struct Writer;

        Rendered³Info(std::string_view, RenderedInfo&, const std::source_location& sl = std::source_location::current());
    };

    /*! \brief Something that's rendered with a defined position, size, etc
    
    
        \note ONCE it's here, it's considered "fixed" into abstract graphical units.
    */
    class Rendered³ : public Rendered, public ③ {
        YQ_TACHYON_INFO(Rendered³Info);
        YQ_TACHYON_DATA(Rendered³Data);
        YQ_TACHYON_SNAP(Rendered³Snap);
        YQ_TACHYON_DECLARE(Rendered³, Rendered)
    public:    
    
        struct Param : public Rendered::Param {
            
            // setting *ANY* of these creates a simple spatial (3D)
        
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
            Camera³ID       camera;
        };
        
        void    set_bounds(bounds³_t);
    
        using Rendered::mark;

        static void init_info();

        Rendered³ID id() const { return Rendered³ID(UniqueID::id()); }
        
    protected:
        
        Rendered³(const Param&);
        virtual ~Rendered³();
        
        void    snap(Rendered³Snap&) const;
        void    finalize(Rendered³Data&) const;
        virtual PostAdvice  advise(const Post&) const override;
        
        using Tachyon::mail;
        using Tachyon::send;

    private:
        
        //! Bounds of the item (in render coordinate)
        bounds³_t       m_bounds;
        Camera³ID       m_camera;
    };

}
YQ_TYPE_DECLARE(yq::tachyon::Rendered³ID)
