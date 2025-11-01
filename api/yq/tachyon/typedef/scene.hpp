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
    class Scene;
    using ScenePtr      = Ref<Scene>;
    using SceneCPtr     = Ref<const Scene>;

    struct SceneSnap;
    using SceneSnapPtr  = Ref<SceneSnap>;
    using SceneSnapCPtr = Ref<const SceneSnap>;
    
    struct SceneData;
    using SceneDataPtr  = Ref<SceneData>;
    using SceneDataCPtr = Ref<const SceneData>;

    template <class> class ID;
    using SceneID = ID<Scene>;
    
    class SceneMeta;
}
