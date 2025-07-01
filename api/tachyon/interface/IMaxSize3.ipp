////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMaxSize3.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PMaxSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize³)

namespace yq::tachyon {
    void    IMaxSize³::init_info()
    {
        auto w = writer<IMaxSize³>();
        w.description("3D Size");
    }
}
