////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/minis/TextLabel.hpp>
#include <yt/ui/MiniInfoWriter.hpp>
#include <yt/ui/MyImGui.hpp>
#include <ya/accessors/StringFunction.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::TextLabel)

namespace yq::tachyon {
    TextLabel::TextLabel()
    {
    }
    
    TextLabel::TextLabel(AccessorUPtr&& acc)
    {
        accessor(SET, std::move(acc));
    }

    TextLabel::TextLabel(StringFunction::FN&& fn)
    {
        accessor(SET, std::make_unique<StringFunction>(std::move(fn)));
    }

    TextLabel::TextLabel(std::string_view sv)
    {   
        accessor(SET, std::make_unique<StringValue>(sv));
    }

    TextLabel::TextLabel(const char* pString)
    {   
        assert(pString);
        accessor(SET, std::make_unique<StringValue>(pString));
    }

    TextLabel::~TextLabel()
    {
    }
    
    void    TextLabel::accessor(set_k, AccessorUPtr&& acc) 
    {
        Mini::accessor(SET, std::move(acc));
        m_accessor = dynamic_cast<StringAccessor*>(accessor());
    }
    
    void    TextLabel::imgui(ViContext&) 
    {
        if(m_accessor){
            std::string_view    val = m_accessor -> get(VALUE);
            if(val.empty())
                val = "";
            ImGui::TextUnformatted(val.data(), val.data()+val.size());
            return ;
        }
        
        Accessor* acc   = accessor();
        if(acc){
            std::string val;
            if(auto valx = to_string(m_accessor -> get(ANY))){
                val = *valx;
            } else {
                val = "";
            }
            
            ImGui::TextUnformatted(val.c_str());
            return;
        }
        
        ImGui::TextUnformatted("(missing accessor)");
    }
}
