////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IColor.hpp"
#include <tachyon/proxy/PColor.hpp>
#include <tachyon/api/InterfaceMetaWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IColor)

namespace yq::tachyon {
    IColor::IColor() = default;
    IColor::~IColor() = default;

    void IColor::init_info()
    {
        auto w = writer<IColor>();
        w.description("Color (RGBA-float) Interface");
    }
}
