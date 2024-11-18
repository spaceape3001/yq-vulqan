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
    class Widget;
    using WidgetPtr         = Ref<Widget>;
    using WidgetCPtr        = Ref<const Widget>;

    template <class> class ID;
    using WidgetID = ID<Widget>;
}
