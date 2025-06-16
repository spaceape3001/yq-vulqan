////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMaxSize4.hpp>

#include <tachyon/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PMaxSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize⁴)

namespace yq::tachyon {
    void    IMaxSize⁴::init_info()
    {
        auto w = writer<IMaxSize⁴>();
        w.description("4D Size");
    }
}
