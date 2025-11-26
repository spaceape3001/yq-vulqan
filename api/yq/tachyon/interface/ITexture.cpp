////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ITexture.hpp"
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PTexture.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ITexture)

namespace yq::tachyon {
    void ITexture::init_meta()
    {
        auto w = writer<ITexture>();
        w.description("Texture");
    }
}
