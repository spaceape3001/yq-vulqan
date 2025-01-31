////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    class Frame;
    class TextLabel;
    
    class FrameInspector : public Widget {
        YQ_TACHYON_DECLARE(FrameInspector, Widget)
    public:
        FrameInspector();
        ~FrameInspector();
        
        virtual void    imgui(ViContext&);
        
        Execution setup(const Context&) override;
        
        static void init_info();
        
        class Pane;

    private:
        
        Ref<const Frame>        m_frame;
        std::vector<Pane*>      m_panes;

        bool        m_track         = true;
        bool        m_init          = false;
    };

    class FrameInspector::Pane {
    public:
        void    set_frame(const Frame*f)
        {
            m_frame = f;
        };
        
        virtual const char* name() const = 0;
        virtual uint64_t    count() const { return 0; }
        virtual bool        countable() const { return false; }
        virtual void        render(ViContext&)  = 0;
        
    protected:
        const Frame* m_frame = nullptr;
    };


}
