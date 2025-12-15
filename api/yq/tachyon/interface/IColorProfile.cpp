////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IColorProfile.hpp"
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PColorProfile.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IColorProfile)

namespace yq::tachyon {
    void IColorProfile::init_meta()
    {
        auto w = writer<IColorProfile>();
        w.description("Color Profile");
    }
}
