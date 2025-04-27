////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>

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
        
        bool        m_table         = false;
        
        bool        table_begin();
        void        table_end();
        
        template <typename Pred>
        void        guard(Pred&&);
        
        static constexpr const char*  szTable     = "Panes";
        static constexpr const int    nTableCols  = 2;
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
        virtual ~Pane() {  }
        
    protected:
        const Frame*        m_frame = nullptr;
        
        bool    begin(table_k);
        void    end(table_k);

        template <typename Pred>
        void    guard(Pred&&);
        
    private:
        friend class FrameInspector;
        FrameInspector*     m_inspector = nullptr;
    };


}
