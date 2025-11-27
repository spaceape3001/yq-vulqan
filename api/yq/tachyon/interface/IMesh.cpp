////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMesh.hpp"
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMesh.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMesh)

namespace yq::tachyon {
    void IMesh::init_meta()
    {
        auto w = writer<IMesh>();
        w.description("Mesh");
    }
}
