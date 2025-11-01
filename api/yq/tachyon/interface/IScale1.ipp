////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IScale1.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale¹)

namespace yq::tachyon {
    void    IScale¹::init_meta()
    {
        auto w = writer<IScale¹>();
        w.description("1D Scale");
    }
}
