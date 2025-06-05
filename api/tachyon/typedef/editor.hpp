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
    class Panel;
    using PanelPtr      = Ref<Panel>;
    using PanelCPtr     = Ref<const Panel>;

    struct PanelSnap;
    using PanelSnapPtr  = Ref<PanelSnap>;
    using PanelSnapCPtr = Ref<const PanelSnap>;
    
    struct PanelData;
    using PanelDataPtr  = Ref<PanelData>;
    using PanelDataCPtr = Ref<const PanelData>;

    template <class> class ID;
    using PanelID = ID<Panel>;
    
    class EditorInfo;
}
