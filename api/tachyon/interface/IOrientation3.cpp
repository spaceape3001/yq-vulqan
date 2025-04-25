////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IOrientation3.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/POrientation3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOrientation³)

namespace yq::tachyon {
    void    IOrientation³::init_info()
    {
        auto w = writer<IOrientation³>();
        w.description("3D Orientation");
    }
}
