////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition4CM.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/centimeter/PPosition4CM.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴CM)

namespace yq::tachyon {
    void    IPosition⁴CM::init_meta()
    {
        auto w = writer<IPosition⁴CM>();
        w.description("4D Position (meters)");
    }
}
