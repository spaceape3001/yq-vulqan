////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIForm.hpp>

namespace yq::tachyon {
    class Frame;
    class Thread;
    struct ThreadData;
    struct ThreadSnap;

    class UIFrameMetrics : public UIForm {
        YQ_OBJECT_DECLARE(UIFrameMetrics, UIForm)
    public:

        static void init_meta();

        UIFrameMetrics(UIFlags flags={});
        UIFrameMetrics(const UIFrameMetrics&);
        ~UIFrameMetrics();
        
        virtual UIFrameMetrics* clone() const override;
        
        void    fps();
        void    cameras();
        void    scenes();
        void    models();
        void    rendereds();
        void    lights();
        void    threads();
        void    cycle();
        
        void    render() override;

    private:
        const Frame*        m_frame     = nullptr;
        const Thread*       m_thread    = nullptr;
        const ThreadData*   m_data      = nullptr;
        const ThreadSnap*   m_snap      = nullptr;
    };
}

