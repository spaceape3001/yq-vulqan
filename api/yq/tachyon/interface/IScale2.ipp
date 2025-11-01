////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IScale2.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale²)

namespace yq::tachyon {
    void    IScale²::init_meta()
    {
        auto w = writer<IScale²>();
        w.description("2D Scale");
    }
}
