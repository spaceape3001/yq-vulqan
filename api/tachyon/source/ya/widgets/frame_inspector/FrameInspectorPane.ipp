////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/StreamOps.hpp>
#include <yq/stream/Text.hpp>

namespace yq::tachyon {
    class FrameInspectorPane : public FormWidget, public FrameInspector::Sub {
        YQ_TACHYON_DECLARE(FrameInspectorPane, FormWidget)
    public:
    
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            Widget::imgui(ctx);
        }

        FrameInspectorPane() 
        {
        }
        
        ~FrameInspectorPane()
        {
        }

        static void init_info()
        {
        }
        
        Execution setup(const Context&ctx) override 
        {
            if(!m_init){
                add_row("Cycle Time (ns)", [this]() -> std::string_view {
                    if(!m_data)
                        return {};
                    return to_string_view(m_data->cycleTime.value);
                });

                add_row("Inbound Posts", [this]() -> std::string_view {
                    if(!m_data)
                        return {};
                    return to_string_view(m_data->inbound.size());
                });
                    
                add_row("Outbound Posts", [this]() -> std::string_view {
                    if(!m_data)
                        return {};
                    return to_string_view(m_data->outbound.size());
                });

                add_row("Owner", [this]() -> std::string_view {
                    if(!m_data)
                        return {};
                    return to_string_view(m_data->owner.id);
                });

                add_row("Paused?", [this]() -> std::string_view {
                    if(!m_snap)
                        return {};
                    return to_string_view(m_snap->paused);
                });

                add_row("Running?", [this]() -> std::string_view {
                    if(!m_snap)
                        return {};
                    return to_string_view(m_snap->running);
                });

                add_row("Started?", [this]() -> std::string_view {
                    if(!m_snap)
                        return {};
                    return to_string_view(m_snap->started);
                });

                add_row("Teardown?", [this]() -> std::string_view {
                    if(!m_snap)
                        return {};
                    return to_string_view(m_snap->teardown);
                });
            
                m_init  = true;
            }
            return FormWidget::setup(ctx);
        }
        
        void    set(TachyonID tid) 
        {
            if(m_frame){
                m_snap      = m_frame->snap(tid);
                m_data      = m_frame->data(tid);
                m_tachyon   = m_frame->object(tid);
            }
        }
        
        bool    begin(TachyonID tid)
        {
            set(tid);
            if(!m_tachyon)
                return false;
                
            std::string     name;
            {
                stream::Text    fmt(name);
                fmt << m_tachyon->metaInfo().name();
                fmt << " {";
                fmt << tid.id;
                fmt << '}';
            }
            if(!ImGui::TreeNode(name.c_str()))
                return false;
                
            m_imguiID  = metaInfo().name();
            m_imguiID += ' ';
            m_imguiID += name;
            return true;
        }
        
        void    end()
        {
            ImGui::TreePop();
        }
        
        const char*     imgui_id() const override
        {
            return m_imguiID.c_str();
        }
        
    protected:
        const TachyonSnap*      m_snap      = nullptr;
        const TachyonData*      m_data      = nullptr;
        const Tachyon*          m_tachyon   = nullptr;
    private:
        bool                    m_init      = false;
        std::string             m_imguiID;
    };
}
