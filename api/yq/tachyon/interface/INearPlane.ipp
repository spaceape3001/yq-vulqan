////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "INearPlane.hpp"
#include <yq/tachyon/proxy/PNearPlane.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::INearPlane)

namespace yq::tachyon {
    INearPlane::INearPlane() = default;
    INearPlane::~INearPlane() = default;

    void INearPlane::init_meta()
    {
        auto w = writer<INearPlane>();
        w.description("Near Plane Interface");
    }
}
