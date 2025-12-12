////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount2.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount²)

namespace yq::tachyon {
    void    ICount²::init_meta()
    {
        auto w = writer<ICount²>();
        w.description("2D Count");
    }
}
