////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IColor.hpp"
#include <yq/tachyon/proxy/PColor.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IColor)

namespace yq::tachyon {
    IColor::IColor() = default;
    IColor::~IColor() = default;

    void IColor::init_meta()
    {
        auto w = writer<IColor>();
        w.description("Color (RGBA-float) Interface");
    }
}
