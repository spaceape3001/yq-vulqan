////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition4D.hpp"

#include <yq/tachyon/engine.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition4D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴D)

namespace yq::tachyon {
    Centimeter4D        IPosition⁴D::position(centimeter_k) const
    {
        return engine::to_centimeter(position());
    }
    
    Foot4D              IPosition⁴D::position(foot_k) const
    {
        return engine::to_foot(position());
    }
    
    Inch4D              IPosition⁴D::position(inch_k) const
    {
        return engine::to_inch(position());
    }
    
    Kilometer4D         IPosition⁴D::position(kilometer_k) const
    {
        return engine::to_kilometer(position());
    }
    
    Meter4D             IPosition⁴D::position(meter_k) const
    {
        return engine::to_meter(position());
    }

    void    IPosition⁴D::init_meta()
    {
        auto w = writer<IPosition⁴D>();
        w.description("4D Position (doubles)");
    }
}
