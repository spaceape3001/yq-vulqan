////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>
#include <yq/core/Flags.hpp>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    
    enum class SaveOption {
        //! Do the threads themeselves,
        DoThreads,
        
        //! Skip the ownership information (ie, no "thread=" in the file)
        SkipOwnership,
        
        //! Skip children (if selective)
        SkipChildren
    };
    using SaveOptions   = Flags<SaveOption>;
    
    class Save;
    
    struct SaveProperty;
    
    class SaveAsset;
    class SaveDelegate;
    class SaveObject;
    class SaveTachyon;

    using SaveSPtr  = std::shared_ptr<Save>;
}


