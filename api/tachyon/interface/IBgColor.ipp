////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IBgColor.hpp"
#include <tachyon/proxy/PBgColor.hpp>
#include <tachyon/api/InterfaceMetaWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IBgColor)

namespace yq::tachyon {
    IBgColor::IBgColor() = default;
    IBgColor::~IBgColor() = default;

    void IBgColor::init_meta()
    {
        auto w = writer<IBgColor>();
        w.description("Background/Secondary Color (RGBA-float) Interface");
    }
}
