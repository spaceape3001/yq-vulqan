////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition1.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹)

namespace yq::tachyon {
    void    IPosition¹::init_meta()
    {
        auto w = writer<IPosition¹>();
        w.description("1D Position");
    }
}
