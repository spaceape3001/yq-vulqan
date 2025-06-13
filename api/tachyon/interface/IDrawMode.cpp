////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IDrawMode.hpp"
#include <tachyon/proxy/PDrawMode.hpp>
#include <tachyon/api/InterfaceInfoWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IDrawMode)

namespace yq::tachyon {
    IDrawMode::IDrawMode() = default;
    IDrawMode::~IDrawMode() = default;

    void IDrawMode::init_info()
    {
        auto w = writer<IDrawMode>();
        w.description("DrawMode Interface");
    }
}
