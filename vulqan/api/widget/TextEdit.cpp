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

        const TextEdit::Palette&   TextEdit::dark_palette()
        {
            static const Palette p = { { {
                { IM_COL32( 0x7f, 0x7f, 0x7f, 0xff )}, // Default
                { IM_COL32( 0x10, 0x10, 0x10, 0xff )}, // Background
                { IM_COL32( 0xe0, 0xe0, 0xe0, 0xff )}, // Caret
                { IM_COL32( 0x20, 0x60, 0xa0, 0x80 )}, // Selection
                { IM_COL32( 0x00, 0x70, 0x70, 0xff )}, // Line number
                { IM_COL32( 0x56, 0x9c, 0xd6, 0xff )}, // Keyword	
                { IM_COL32( 0x00, 0xff, 0x00, 0xff )}, // Number
                { IM_COL32( 0xe0, 0x70, 0x70, 0xff )}, // String
                { IM_COL32( 0xe0, 0xa0, 0x70, 0xff )}, // Char literal
                { IM_COL32( 0xff, 0xff, 0xff, 0xff )}, // Punctuation
                { IM_COL32( 0x80, 0x80, 0x40, 0xff )}, // Preprocessor
                { IM_COL32( 0xaa, 0xaa, 0xaa, 0xff )}, // Identifier
                { IM_COL32( 0x4d, 0xc6, 0x9b, 0xff )}, // Known identifier
                { IM_COL32( 0xa0, 0x40, 0xc0, 0xff )}, // Preproc identifier
                { IM_COL32( 0x20, 0x60, 0x20, 0xff )}, // Comment (single line)
                { IM_COL32( 0x20, 0x60, 0x40, 0xff )}, // Comment (multi line)
                { IM_COL32( 0xff, 0x20, 0x00, 0x80 )}, // ErrorMarker
                { IM_COL32( 0x00, 0x80, 0xf0, 0x40 )}, // Breakpoint
                { IM_COL32( 0x00, 0x00, 0x00, 0x40 )}, // Current line fill
                { IM_COL32( 0x80, 0x80, 0x80, 0x40 )}, // Current line fill (inactive)
                { IM_COL32( 0xa0, 0xa0, 0xa0, 0x40 )}  // Current line edge
            } } };
            return p;
        }
        
        //const TextEdit::Palette&   TextEdit::light_palette()
        //{
            //static const Palette p = { { {
                
            //} } };
            //return p;
        //}
        
        //const TextEdit::Palette&   TextEdit::retro_blue_palette()
        //{
            //static const Palette p = { { {
                
            //} } };
            //return p;
        //}

        //  ...........................................................................................................

        TextEdit::TextEdit()
        {
            m_palette   = dark_palette();
        }
        
        TextEdit::~TextEdit()
        {
        }

        //  ...........................................................................................................

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
        
        uint32_t            TextEdit::line_characters_count(uint32_t l) const
        {
            if(l >= m_lines.size())
                return 0;
            return m_lines[l].glyphs.size();
        }

        void                TextEdit::reset_config()
        {
            m_config        = ConfigData();
        }

        void                TextEdit::set_palette(const Palette& pal)
        {
            m_palette       = pal;
        }

        void                TextEdit::set_tab_count(uint8_t s)
        {
            m_config.tabCount   = std::min(s, MAX_TAB);
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

        void                TextEdit::set_tab_mode(TabMode tm)
        {
            m_config.tabMode    = tm;
        }
        
        //  ...........................................................................................................
        
        void    TextEdit::draw() 
        {
            auto drawList = ImGui::GetWindowDrawList();
            ImU32 red  = ImGui::GetColorU32(ImVec4(1., 0., 0., 1.));
            ImVec2  vstart  = ImGui::GetWindowContentRegionMin();
            ImVec2  vend    = ImGui::GetWindowContentRegionMax();
            drawList->AddRectFilled(vstart, vend, red);
        }
    }
}
