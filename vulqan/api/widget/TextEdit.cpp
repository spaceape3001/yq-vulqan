////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TextEdit.hpp"
#include <MyImGui.hpp>
#include <basic/Stream.hpp>
#include <basic/StreamOps.hpp>
#include <basic/IterUtf8.hpp>
#include <basic/TextUtils.hpp>
#include <basic/stream/Text.hpp>

YQ_OBJECT_IMPLEMENT(yq::widget::TextEdit)

namespace yq {
    namespace widget {
        TextEdit::TextEdit()
        {
        }
        
        TextEdit::~TextEdit()
        {
        }

        std::string         TextEdit::build_text() const
        {
            std::string         ret;
            ret.reserve(character_count());
            {
                stream::Text    txt(ret);
                stream_text(txt);
            }
            return ret;
        }

        char32_t            TextEdit::character(const Coord& c) const
        {
            if(c.line >= m_lines.size())
                return 0;
            auto& l = m_lines[c.line];
            if(c.column >= l.glyphs.size()) 
                return 0;
            return l.glyphs[c.column].character;
        }

        uint64_t            TextEdit::character_count() const
        {
            uint64_t    ret = m_lines.size();
            for(auto& l : m_lines)
                ret += l.glyphs.size();
            return ret;
        }

        void                TextEdit::clear_text()
        {
            m_lines.clear();
        }
        
        
        

        void    TextEdit::draw() 
        {
            auto drawList = ImGui::GetWindowDrawList();
            ImU32 red  = ImGui::GetColorU32(ImVec4(1., 0., 0., 1.));
            ImVec2  vstart  = ImGui::GetWindowContentRegionMin();
            ImVec2  vend    = ImGui::GetWindowContentRegionMax();
            drawList->AddRectFilled(vstart, vend, red);
        }

        uint32_t            TextEdit::line_count() const
        {
            return m_lines.size();
        }
        
        uint32_t            TextEdit::line_characters_count(uint32_t l) const
        {
            if(l >= m_lines.size())
                return 0;
            return m_lines[l].glyphs.size();
        }

        void                TextEdit::reset_config()
        {
            m_config        = Config();
        }

        void                TextEdit::set_palette(std::span<const Style> pal)
        {
            unsigned int  sz  = std::min((unsigned int) pal.size(), NPAL);
            unsigned int  i;
            for(i = 0; i<sz; ++i)
                m_palette[i]    = pal[i];
            for(; i<NPAL; ++i)
                m_palette[i]    = Style();
        }
        
        void                TextEdit::set_text(std::string_view sv)
        {
            m_lines.clear();
            m_lines.push_back(Line());
            if(!sv.empty()){
                iter_utf8(sv, [&](char32_t ch){
                    if(ch == '\n'){
                        m_lines.push_back(Line());
                        return ;
                    }
                
                    m_lines.back().glyphs.push_back(Glyph{ch});
                });
                m_lines.push_back(Line());
            }
        }
        
        void                TextEdit::stream_text(Stream&s) const
        {
            for(auto& l : m_lines){
                for(auto& g : l.glyphs)
                    s << g.character;
                s << '\n';
            }
        }
        
    }
}
