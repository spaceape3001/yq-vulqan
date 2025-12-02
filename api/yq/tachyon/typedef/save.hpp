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
    
    //enum class SaveOption {
        ////! Do the threads themeselves,
        //DoThreads,
        
        ////! Skip the ownership information (ie, no "thread=" in the file)
        //SkipOwnership,
        
        ////! Skip children (if selective)
        //SkipChildren,
        
        ////! Want children, skip the listed
        //OnlyChildren
    //};
    //using SaveOptions   = Flags<SaveOption>;
    
    class Save;
    
    //struct SaveProperty;
    
    //class SaveResource;
    //class SaveDelegate;
    //class SaveObject;
    //class SaveTachyon;

    using SavePtr           = Ref<Save>;
    using SaveCPtr           = Ref<const Save>;

    //class Reincarnation;
    //using ReincarnationSPtr = std::shared_ptr<Reincarnation>;
    //using ReincarnationUPtr = std::unique_ptr<Reincarnation>;
}


