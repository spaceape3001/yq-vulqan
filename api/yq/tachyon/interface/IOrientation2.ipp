////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IOrientation3.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/POrientation2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOrientation²)

namespace yq::tachyon {
    void    IOrientation²::init_meta()
    {
        auto w = writer<IOrientation²>();
        w.description("2D Orientation");
    }
}
