////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMaxSize2.hpp>

#include <tachyon/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PMaxSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize²)

namespace yq::tachyon {
    void    IMaxSize²::init_info()
    {
        auto w = writer<IMaxSize²>();
        w.description("2D Size");
    }
}
