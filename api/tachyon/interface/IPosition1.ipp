////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IPosition1.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PPosition1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹)

namespace yq::tachyon {
    void    IPosition¹::init_info()
    {
        auto w = writer<IPosition¹>();
        w.description("1D Position");
    }
}
