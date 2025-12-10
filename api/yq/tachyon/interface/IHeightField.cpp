////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IHeightField.hpp"
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PHeightField.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IHeightField)

namespace yq::tachyon {
    void IHeightField::init_meta()
    {
        auto w = writer<IHeightField>();
        w.description("Height Field");
    }
}
