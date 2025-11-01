////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IOrientation3.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/POrientation3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOrientation³)

namespace yq::tachyon {
    void    IOrientation³::init_meta()
    {
        auto w = writer<IOrientation³>();
        w.description("3D Orientation");
    }
}
