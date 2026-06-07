////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Rendered2.hpp"
#include "Rendered2Data.hpp"
#include "Rendered2MetaWriter.hpp"
#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <yq/tachyon/api/dim/2DWriter.hxx>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    Rendered²Data::Rendered²Data() = default;
    Rendered²Data::~Rendered²Data() = default;

    void Rendered²Data::init_meta()
    {
        auto w = writer<Rendered²Data>();
        w.description("Rendered² Frame Data");
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Rendered²Snap::Rendered²Snap() = default;
    Rendered²Snap::~Rendered²Snap() = default;

    void Rendered²Snap::init_meta()
    {
        auto w = writer<Rendered²Snap>();
        w.description("Rendered² Snapshot");
    }

    /////////////////////////////////////////////////////////////////////////////

    Rendered²Meta::Rendered²Meta(std::string_view name, RenderedMeta& base, const std::source_location& sl) : 
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
    
    void    Rendered²::init_meta()
    {
        auto w   = writer<Rendered²>();
        ②::init_meta(w);
        w.description("Rendered in 2D");
        w.abstract();
        w.alias("Rendered2");

        auto wt = writer<Rendered²ID>();
        wt.description("2D Rendered Identifier");
        wt.set(Meta::Flag::ID);
        wt.alias("Rendered2ID");
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Rendered²)
YQ_TYPE_IMPLEMENT(yq::tachyon::Rendered²ID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Rendered²Data)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Rendered²Snap)
