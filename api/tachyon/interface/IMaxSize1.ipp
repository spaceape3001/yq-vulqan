////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMaxSize1.hpp>

#include <tachyon/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PMaxSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize¹)

namespace yq::tachyon {
    void    IMaxSize¹::init_info()
    {
        auto w = writer<IMaxSize¹>();
        w.description("1D Size");
    }
}
