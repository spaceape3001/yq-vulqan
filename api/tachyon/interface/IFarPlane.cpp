////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IFarPlane.hpp"
#include <tachyon/proxy/PFarPlane.hpp>
#include <tachyon/api/InterfaceInfoWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IFarPlane)

namespace yq::tachyon {
    IFarPlane::IFarPlane() = default;
    IFarPlane::~IFarPlane() = default;

    void IFarPlane::init_info()
    {
        auto w = writer<IFarPlane>();
        w.description("Far Plane Interface");
    }
}
