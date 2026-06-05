////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition1CM.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/centimeter/PPosition1CM.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹CM)

namespace yq::tachyon {
    void    IPosition¹CM::init_meta()
    {
        auto w = writer<IPosition¹CM>();
        w.description("1D Position");
    }
}
