////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMinSize2.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PMinSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize²)

namespace yq::tachyon {
    void    IMinSize²::init_meta()
    {
        auto w = writer<IMinSize²>();
        w.description("2D Size");
    }
}
