////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <yq/math/SimpleSpace.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/Circle2.hpp>
#include <tachyon/api/Rendered.hpp>
#include <yq/vector/Vector2.hpp>
#include <tachyon/api/2D.hpp>
#include <tachyon/typedef/bounds2.hpp>
#include <tachyon/typedef/rendered2.hpp>
#include <tachyon/typedef/spatial2.hpp>

namespace yq::tachyon {
        
    /*! \brief Information for the render2D object
    */
    class Rendered²Meta : public RenderedMeta {
    public:
        template <typename C> struct Writer;

        Rendered²Meta(std::string_view, RenderedMeta&, const std::source_location& sl = std::source_location::current());
    };

    /*! \brief Something that's rendered with a defined position, size, etc
    
    
        \note ONCE it's here, it's considered "fixed" into abstract graphical units.
    */
    class Rendered² : public Rendered, public ② {
        YQ_TACHYON_META(Rendered²Meta);
        YQ_TACHYON_DATA(Rendered²Data);
        YQ_TACHYON_SNAP(Rendered²Snap);
        YQ_TACHYON_DECLARE(Rendered², Rendered)
    public:    
    
        struct Param : public Rendered::Param {
            
            // setting *ANY* of these creates a simple spatial (2D)
        
            Vector2D        position        = NAN;
            Radian          orientation     = NAN;
            Vector2D        scale           = NAN;
        };
        
        void    set_bounds(bounds²_t);
    
        using Rendered::mark;

        static void init_meta();

        Rendered²ID id() const { return Rendered²ID(UniqueID::id()); }

    protected:
        
        Rendered²(const Param&);
        virtual ~Rendered²();
        
        void    snap(Rendered²Snap&) const;
        void    finalize(Rendered²Data&) const;
        virtual PostAdvice  advise(const Post&) const override;
        
        using Tachyon::mail;
        using Tachyon::send;

    private:
        
        //! Bounds of the item (in render coordinate)
        bounds²_t       m_bounds;
    };

}
YQ_TYPE_DECLARE(yq::tachyon::Rendered²ID)
