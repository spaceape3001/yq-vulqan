////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImWidget.hpp"
#include "ImWidgetInfoWriter.hpp"
#include <tachyon/command/ui/TitleCommand.hpp>
#include <tachyon/event/ui/TitleEvent.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yq/shape/AxBox2.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ImWidget);

namespace yq::tachyon {
    ImWidgetInfo::ImWidgetInfo(std::string_view kName, Widget²Info&pMeta, const std::source_location& sl) :
        Widget²Info(kName, pMeta, sl)
    {
        set(Flag::IMGUI);
    }

    ImWidget::ImWidget(std::string_view kTitle) : m_title(kTitle)
    {
        m_flags |= X::Open;
        m_title = "ImWidget##";
        m_title += m_windowID;
    }
    
    ImWidget::~ImWidget()
    {
    }

    void    ImWidget::aabb_changed() 
    {
        m_flags |= X::SetPos;
    }

    //! The imgui wrapper
    void    ImWidget::imgui(ViContext& ctx) 
    {
        ImGuiWindowFlags    flags   = 0;


        //  Set position....
        if(m_flags(X::SetPos)){
            ImGui::SetNextWindowPos( (ImVec2) aabb().lo );
            ImGui::SetNextWindowSize( (ImVec2) aabb().span() );
        }
        
        bool    fOpen   = true;
        if(m_flags(X::CloseTab)){
            bool    state, old;
            state = old  = m_flags(X::Open);
            fOpen   = ImGui::Begin(m_title.c_str(), &state, flags);
            if(state && !old){ // opening
                //  presumably an event here too....
                // send(new TODO)
                m_flags |= X::Open;
            } else if(old && !state){ // closing
                //  presumably an event here too....
                // send(new TODO)
                m_flags -= X::Open;
            }
        } else {
            fOpen   = ImGui::Begin(m_title.c_str(), nullptr, flags);
        }
        if(fOpen)
            imguix(ctx);
            
        ImGui::End();
    }


    void    ImWidget::set_title(std::string_view k)
    {
        mail(new TitleCommand({.source=*this, .target=*this}, std::string(k)));
    }

    void ImWidget::on_title_command(const TitleCommand&cmd)
    {
        if(id() != cmd.target())
            return ;
        if(m_title == cmd.title())
            return ;

        m_title = cmd.title();
        if(m_viewer){
            send(cmd.clone(REBIND, {.target=m_viewer}));
        }
        m_title += "##";
        m_title += m_windowID;
        
        send(new TitleEvent({.source=*this}, m_title));
    }

    void ImWidget::init_info()
    {
        auto w = writer<ImWidget>();
        w.description("ImGUI widget");
        w.slot(&ImWidget::on_title_command);
    }

}
