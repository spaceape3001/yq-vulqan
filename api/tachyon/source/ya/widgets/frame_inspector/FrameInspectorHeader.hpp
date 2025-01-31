////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class FrameInspectorHeader : public FormWidget, public FrameInspector::Pane {
        YQ_TACHYON_DECLARE(FrameInspectorHeader, FormWidget)
    public:
        FrameInspectorHeader() 
        {
        }
        
        ~FrameInspectorHeader()
        {
        }
        
        const char* name() const override
        {
            return "Header";
        }

        Execution setup(const Context&ctx) 
        {
            if(m_init)
                return {};
            
            add_row("Number", [this]() -> std::string_view {
                return to_string_view( m_frame -> number() );
            });
            
            add_row("Tick", [this]() -> std::string_view {
                return to_string_view( m_frame -> tick() );
            });
            
            add_row("Origin", [this]() -> std::string_view {
                return to_string_view( m_frame -> origin().id );
            });

            m_init = true;
            return {};
        }
        
        static void init_info()
        {
        }
        
        void    render(ViContext&ctx) override
        {
            FormWidget::imgui(ctx);
        }
        
    private:
        bool            m_init = false;
    };
}
