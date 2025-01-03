////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq { template <typename> class Ref; }

namespace yq::tachyon {
    class Application;
    struct AppCreateInfo;
    using AppCreateInfoSCPtr   = std::shared_ptr<AppCreateInfo>;
    
    class AppFrame;
}
