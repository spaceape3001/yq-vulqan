////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition3D.hpp"

#include <yq/tachyon/engine.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition3D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition³D)

namespace yq::tachyon {
    Centimeter3D        IPosition³D::position(centimeter_k) const
    {
        return engine::to_centimeter(position());
    }
    
    Foot3D              IPosition³D::position(foot_k) const
    {
        return engine::to_foot(position());
    }
    
    Inch3D              IPosition³D::position(inch_k) const
    {
        return engine::to_inch(position());
    }
    
    Kilometer3D         IPosition³D::position(kilometer_k) const
    {
        return engine::to_kilometer(position());
    }
    
    Meter3D             IPosition³D::position(meter_k) const
    {
        return engine::to_meter(position());
    }

    void    IPosition³D::init_meta()
    {
        auto w = writer<IPosition³D>();
        w.description("3D Position (double)");
    }
}
