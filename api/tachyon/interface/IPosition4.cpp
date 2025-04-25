////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IPosition4.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PPosition4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴)

namespace yq::tachyon {
    void    IPosition⁴::init_info()
    {
        auto w = writer<IPosition⁴>();
        w.description("4D Position");
    }
}
