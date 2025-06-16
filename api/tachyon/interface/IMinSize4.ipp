////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMinSize4.hpp>

#include <tachyon/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PMinSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize⁴)

namespace yq::tachyon {
    void    IMinSize⁴::init_info()
    {
        auto w = writer<IMinSize⁴>();
        w.description("4D Size");
    }
}
