////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Rendered3.hpp>
#include <tachyon/api/Rendered3MetaWriter.hpp>
#include <tachyon/command/SpatialCommand.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/tensor/Tensor44.hxx>
#include <tachyon/api/3DWriter.hxx>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    Rendered³Snap::Rendered³Snap() = default;
    Rendered³Snap::~Rendered³Snap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Rendered³Meta::Rendered³Meta(std::string_view name, RenderedMeta& base, const std::source_location& sl) : 
        RenderedMeta(name, base, sl)
    {
        set(Flag::RENDER3D);
        set(Type::Rendered³);
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Rendered³::Rendered³(const Param&p) : Rendered(p), m_camera(p.camera)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            make_simple_spatial(p.position, p.orientation, p.scale);
        }
    }
    
    Rendered³::~Rendered³()   = default;

    PostAdvice  Rendered³::advise(const Post& pp) const 
    {
        PostAdvice pa = Rendered::advise(pp);
        if(!unspecified(pa))
            return pa;
        if(dynamic_cast<const SpatialCommand*>(&pp))
            return MG::Spatial;
        return {};
    }

    void    Rendered³::finalize(Rendered³Data& d) const
    {
        ③::finalize(d);
        Rendered::finalize(d);
    }

    void    Rendered³::set_bounds(bounds³_t b)
    {
        m_bounds = b;
        mark();
    }
 
    void    Rendered³::snap(Rendered³Snap&sn) const
    {
        ③::snap(sn);
        Rendered::snap(sn);
        sn.bounds       = m_bounds;
        sn.camera       = m_camera;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Rendered³::init_meta()
    {
        auto w   = writer<Rendered³>();
        ③::init_meta(w);
        w.description("Rendered in 3D");
        w.abstract();

        auto wt = writer<Rendered³ID>();
        wt.description("3D Rendered Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Rendered³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Rendered³ID)
