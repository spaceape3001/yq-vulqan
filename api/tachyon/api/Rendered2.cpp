////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Rendered2.hpp>
#include <tachyon/api/Rendered2InfoWriter.hpp>
#include <tachyon/command/SpatialCommand.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <tachyon/api/2DWriter.hxx>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    Rendered²Snap::Rendered²Snap() = default;
    Rendered²Snap::~Rendered²Snap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Rendered²Info::Rendered²Info(std::string_view name, RenderedMeta& base, const std::source_location& sl) : 
        RenderedMeta(name, base, sl)
    {
        //set(Flag::RENDER2D);
        set(Type::Rendered²);
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Rendered²::Rendered²(const Param&p) : Rendered(p)
    {
    #if 0
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            make_simple_spatial(p.position, p.orientation, p.scale);
        }
    #endif
    }
    
    Rendered²::~Rendered²()   = default;

    PostAdvice  Rendered²::advise(const Post& pp) const 
    {
        PostAdvice pa = Rendered::advise(pp);
        if(!unspecified(pa))
            return pa;
        if(dynamic_cast<const SpatialCommand*>(&pp))
            return MG::Spatial;
        return {};
    }

    void    Rendered²::finalize(Rendered²Data& d) const
    {
        ②::finalize(d);
        Rendered::finalize(d);
    }

    void    Rendered²::set_bounds(bounds²_t b)
    {
        m_bounds = b;
        mark();
    }
 
    void    Rendered²::snap(Rendered²Snap&sn) const
    {
        ②::snap(sn);
        Rendered::snap(sn);
        sn.bounds       = m_bounds;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Rendered²::init_info()
    {
        auto w   = writer<Rendered²>();
        ②::init_info(w);
        w.description("Rendered in 2D");
        w.abstract();

        auto wt = writer<Rendered²ID>();
        wt.description("2D Rendered Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Rendered²)
YQ_TYPE_IMPLEMENT(yq::tachyon::Rendered²ID)
