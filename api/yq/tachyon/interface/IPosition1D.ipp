////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition1D.hpp>

#include <yq/tachyon/screen.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition1D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹D)

namespace yq::tachyon {
    Centimeter1D        IPosition¹D::position(centimeter_k) const
    {
        return engine::to_centimeter(position());
    }
    
    Foot1D              IPosition¹D::position(foot_k) const
    {
        return engine::to_foot(position());
    }
    
    Inch1D              IPosition¹D::position(inch_k) const
    {
        return engine::to_inch(position());
    }
    
    Kilometer1D         IPosition¹D::position(kilometer_k) const
    {
        return engine::to_kilometer(position());
    }

    Meter1D             IPosition¹D::position(meter_k) const
    {
        return engine::to_meter(position());
    }

    void    IPosition¹D::init_meta()
    {
        auto w = writer<IPosition¹D>();
        w.description("1D Position");
    }
}
