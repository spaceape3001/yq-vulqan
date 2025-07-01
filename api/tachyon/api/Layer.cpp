////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Layer.hpp>
#include <tachyon/api/LayerData.hpp>
#include <tachyon/api/LayerMetaWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Layer);
YQ_TYPE_IMPLEMENT(yq::tachyon::LayerID)

namespace yq::tachyon {

    LayerMeta::LayerMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(name, base, sl)
    {
        set(Type::Layer);
    }
    
    LayerMeta::~LayerMeta()
    {
    }
    

    Layer::Layer(const Param&p) : Tachyon(p)
    {
    }
    
    Layer::~Layer()
    {
    }

    void Layer::snap(LayerSnap&sn) const
    {
        Tachyon::snap(sn);
        sn.order    = m_order;
    }

    void Layer::set_order(int v)
    {
        m_order = v;
    }
    
    void Layer::finalize(LayerData&data) const
    {
        Tachyon::finalize(data);
    }

    void Layer::init_info()
    {
        auto w = writer<Layer>();
        w.description("Layer");
        w.property("order", &Layer::m_order);

        auto wt = writer<LayerID>();
        wt.description("Layer Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Layer>);
        wt.casts<TachyonID>();
    }

}


