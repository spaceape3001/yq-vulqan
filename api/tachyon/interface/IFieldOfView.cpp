////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IFieldOfView.hpp"
#include <tachyon/proxy/PFieldOfView.hpp>
#include <tachyon/api/InterfaceInfoWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IFieldOfView)

namespace yq::tachyon {
    IFieldOfView::IFieldOfView() = default;
    IFieldOfView::~IFieldOfView() = default;

    void IFieldOfView::init_info()
    {
        auto w = writer<IFieldOfView>();
        w.description("Field of View Interface");
    }
}
