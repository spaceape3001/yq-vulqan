////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq { template <typename> class Ref; }

namespace yq::tachyon {
    class Mesh;
    using MeshPtr   = Ref<Mesh>;
    using MeshCPtr  = Ref<const Mesh>;
}
