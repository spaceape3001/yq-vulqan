////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IPosition3.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PPosition3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition³)

namespace yq::tachyon {
    void    IPosition³::init_meta()
    {
        auto w = writer<IPosition³>();
        w.description("3D Position");
    }
}
