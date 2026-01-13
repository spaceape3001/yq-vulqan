////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/graphics/GraphicsView.hpp>

namespace yq::tachyon {
    class XGSceneQt;
    class XGViewQt : public gluon::GraphicsView {
        Q_OBJECT
    public:
        XGViewQt(XGSceneQt*);
        ~XGViewQt();
    private:
        XGSceneQt*  m_scene = nullptr;
    };
}
