////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IPosition2.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PPosition2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition²)

namespace yq::tachyon {
    void    IPosition²::init_meta()
    {
        auto w = writer<IPosition²>();
        w.description("2D Position");
    }
}
