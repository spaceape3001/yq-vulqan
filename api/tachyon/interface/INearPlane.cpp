////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "INearPlane.hpp"
#include <tachyon/proxy/PNearPlane.hpp>
#include <tachyon/api/InterfaceMetaWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::INearPlane)

namespace yq::tachyon {
    INearPlane::INearPlane() = default;
    INearPlane::~INearPlane() = default;

    void INearPlane::init_info()
    {
        auto w = writer<INearPlane>();
        w.description("Near Plane Interface");
    }
}
