////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    
    class Save;
    
    struct SaveProperty;
    struct SaveVariable;
    
    class SaveAsset;
    using SaveAssetPtr      = Ref<SaveAsset>;
    using SaveAssetCPtr     = Ref<const SaveAsset>;
    
    class SaveDelegate;
    using SaveDelegatePtr   = Ref<SaveDelegate>;
    using SaveDelegateCPtr  = Ref<const SaveDelegate>;

    class SaveObject;
    using SaveObjectPtr     = Ref<SaveObject>;
    using SaveObjectCPtr    = Ref<const SaveObject>;

    class SaveTachyon;
    using SaveTachyonPtr    = Ref<SaveTachyon>;
    using SaveTachyonCPtr   = Ref<const SaveTachyon>;
}


