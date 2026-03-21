////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IScreenScaleM.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScreenScaleM.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScreenScaleM)

namespace yq::tachyon {
    void    IScreenScaleM::init_meta()
    {
        auto w = writer<IScreenScaleM>();
        w.description("Screen Scale");
    }
}
