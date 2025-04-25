////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <tachyon/os/Gamepad.hpp>
#include <tachyon/os/GamepadData.hpp>
#include <yq/stream/Text.hpp>

namespace yq::tachyon {
    class FrameInspectorGamepads : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorGamepads, FrameInspectorTachyons)
    public:
    
        FrameInspectorGamepads() 
        {
        }
        
        ~FrameInspectorGamepads()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(GAMEPAD); }
        virtual const char* name() const override { return "Gamepad"; }

        using FrameInspectorTachyons::render;
        
        void    render(gamepad_k)
        {
            const GamepadSnap*  snap    = static_cast<const GamepadSnap*>(m_snap);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> GAMEPAD PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Axes");
            }
            if(ImGui::TableNextColumn()){
                std::string data;
                {
                    stream::Text out(data);
                    for(size_t n=0;n<snap->axes.size();++n){
                        if(n){
                            out << ", ";
                        }
                        out << snap->axes[n];
                    }
                }
                ImGui::TextUnformatted(data);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Buttons");
            }
            if(ImGui::TableNextColumn()){
                std::string data;
                {
                    stream::Text out(data);
                    for(size_t n=0;n<snap->buttons.size();++n){
                        if(n){
                            out << ", ";
                        }
                        out << snap->buttons[n];
                    }
                }
                ImGui::TextUnformatted(data);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("GUID");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(snap->guid);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Name");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(snap->name);
            }
        }

        void    render(ViContext&ctx) override
        {
            for(GamepadID v : m_frame->ids(GAMEPAD)){
                if(!begin(v))
                    continue;
                render(GAMEPAD);
                separator();
                render(TACHYON);
                end();
            }
        }

        static void init_info()
        {
        }
    };
}
