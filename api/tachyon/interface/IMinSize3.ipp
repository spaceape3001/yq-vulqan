////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMinSize3.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PMinSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize³)

namespace yq::tachyon {
    void    IMinSize³::init_info()
    {
        auto w = writer<IMinSize³>();
        w.description("3D Size");
    }
}
