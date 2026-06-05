////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition2D.hpp"

#include <yq/tachyon/engine.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition2D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition²D)

namespace yq::tachyon {
    Centimeter2D        IPosition²D::position(centimeter_k) const
    {
        return engine::to_centimeter(position());
    }
    
    Foot2D              IPosition²D::position(foot_k) const
    {
        return engine::to_foot(position());
    }
    
    Inch2D              IPosition²D::position(inch_k) const
    {
        return engine::to_inch(position());
    }
    
    Kilometer2D         IPosition²D::position(kilometer_k) const
    {
        return engine::to_kilometer(position());
    }

    Meter2D             IPosition²D::position(meter_k) const
    {
        return engine::to_meter(position());
    }
    
    void    IPosition²D::init_meta()
    {
        auto w = writer<IPosition²D>();
        w.description("2D Position (double)");
    }
}
