////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIForm.hpp>

namespace yq::tachyon {
    class Frame;
    class Thread;
    struct ThreadData;
    struct ThreadSnap;

    class FrameMetricsUI : public UIForm {
        YQ_OBJECT_DECLARE(FrameMetricsUI, UIForm)
    public:
    
        static void init_info();
    
        FrameMetricsUI(UIFlags flags={});
        FrameMetricsUI(const FrameMetricsUI&);
        ~FrameMetricsUI();
        
        virtual FrameMetricsUI* clone() const override;
        
        void    fps();
        void    cycle();
        
        void    render() override;
    
    private:
        const Frame*        m_frame     = nullptr;
        const Thread*       m_thread    = nullptr;
        const ThreadData*   m_data      = nullptr;
        const ThreadSnap*   m_snap      = nullptr;
    };
}

