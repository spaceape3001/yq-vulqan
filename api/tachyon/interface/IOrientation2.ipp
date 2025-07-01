////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IOrientation3.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/POrientation2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOrientation²)

namespace yq::tachyon {
    void    IOrientation²::init_info()
    {
        auto w = writer<IOrientation²>();
        w.description("2D Orientation");
    }
}
