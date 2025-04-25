////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IScale2.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PScale2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale²)

namespace yq::tachyon {
    void    IScale²::init_info()
    {
        auto w = writer<IScale²>();
        w.description("2D Scale");
    }
}
