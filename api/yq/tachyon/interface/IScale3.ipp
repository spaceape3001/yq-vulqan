////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IScale3.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale³)

namespace yq::tachyon {
    void    IScale³::init_meta()
    {
        auto w = writer<IScale³>();
        w.description("3D Scale");
    }
}
