////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMaterial.hpp"
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaterial.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaterial)

namespace yq::tachyon {
    void IMaterial::init_meta()
    {
        auto w = writer<IMaterial>();
        w.description("Material");
    }
}
