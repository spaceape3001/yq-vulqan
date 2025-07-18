////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IPosition4.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PPosition4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴)

namespace yq::tachyon {
    void    IPosition⁴::init_meta()
    {
        auto w = writer<IPosition⁴>();
        w.description("4D Position");
    }
}
