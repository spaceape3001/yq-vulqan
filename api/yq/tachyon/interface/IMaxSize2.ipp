////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IMaxSize2.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize²)

namespace yq::tachyon {
    void    IMaxSize²::init_meta()
    {
        auto w = writer<IMaxSize²>();
        w.description("2D Size");
    }
}
