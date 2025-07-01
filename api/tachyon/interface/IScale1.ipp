////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IScale1.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PScale1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale¹)

namespace yq::tachyon {
    void    IScale¹::init_info()
    {
        auto w = writer<IScale¹>();
        w.description("1D Scale");
    }
}
