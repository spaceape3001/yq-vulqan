////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/ISize2.hpp>

#include <tachyon/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize²)

namespace yq::tachyon {
    void    ISize²::init_info()
    {
        auto w = writer<ISize²>();
        w.description("2D Size");
    }
}
