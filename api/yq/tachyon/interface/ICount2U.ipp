////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount2U.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount2U.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount²U)

namespace yq::tachyon {
    void    ICount²U::init_meta()
    {
        auto w = writer<ICount²U>();
        w.description("2D Count");
    }
}
