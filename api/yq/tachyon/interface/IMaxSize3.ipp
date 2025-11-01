////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IMaxSize3.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize³)

namespace yq::tachyon {
    void    IMaxSize³::init_meta()
    {
        auto w = writer<IMaxSize³>();
        w.description("3D Size");
    }
}
