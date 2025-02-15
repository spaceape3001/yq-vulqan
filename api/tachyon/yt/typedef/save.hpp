////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    
    class Save;
    
    struct SaveProperty;
    
    class SaveAsset;
    class SaveDelegate;
    class SaveObject;
    class SaveTachyon;

    using SaveSPtr  = std::shared_ptr<Save>;
}


