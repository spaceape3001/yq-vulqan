////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMinSize1.hpp>

#include <tachyon/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PMinSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize¹)

namespace yq::tachyon {
    void    IMinSize¹::init_info()
    {
        auto w = writer<IMinSize¹>();
        w.description("1D Size");
    }
}
