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

        void    TextEdit::Line::add(std::string_view sv)
        {
            iter_utf8(sv, [&](char32_t ch){
                if(ch == '\n')
                    return;
                if(ch == '\r') // return to sender, you filthy animal!
                    return;
                glyphs.push_back(Glyph{ch});
            });
        }

        void            TextEdit::Line::stream(Stream&s) const
        {
            for(const Glyph& g : glyphs)
                s << g.character;
        }
        
        std::string     TextEdit::Line::text() const
        {
            std::string     ret;
            ret.reserve(glyphs.size() << 1 );
            ::yq::stream::Text  txt(ret);
            stream(txt);
            return ret;      
        }

        std::u32string  TextEdit::Line::utf32() const
        {
            std::u32string  ret;
            ret.resize(glyphs.size());
            for(size_t n=0;n<glyphs.size();++n)
                ret[n] = glyphs[n].character;
            return ret;
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
        
        uint32_t            TextEdit::color(Style s) const
        {
            return m_palette.entries[(unsigned) s].color;
        }

        uint32_t            TextEdit::line_characters_count(uint32_t l) const
        {
            if(l >= m_lines.size())
                return 0;
            return m_lines[l].glyphs.size();
        }

        std::string         TextEdit::line_text(uint32_t li) const
        {
            if(li < m_lines.size())
                return m_lines[li].text();
            return std::string();
        }

        void                TextEdit::reset_settings()
        {
            m_settings      = Settings();
        }

        void                TextEdit::set_line_text(uint32_t li, std::string_view txt)
        {
            if(li < m_lines.size()){
                auto& l = m_lines[li];
                l.glyphs.clear();
                l.add(txt);
            }
        }

        void                TextEdit::set_palette(const Palette& pal)
        {
            m_palette       = pal;
        }

        void                TextEdit::set_tab_count(uint8_t s)
        {
            m_settings.tabCount = std::min(s, MAX_TAB);
        }
        
        void                TextEdit::set_text(std::string_view sv)
        {
            m_lines.clear();
            if(!sv.empty()){
                vsplit(sv, '\n', [&](std::string_view sv){
                    Line        l;
                    l.add(sv);
                    m_lines.push_back(l);
                });
            }
            m_lines.push_back(Line());
        }

        void                TextEdit::set_text_lines(std::span<std::string_view> lines)
        {
            m_lines.clear();
            for(std::string_view sv : lines){
                Line    l;
                l.add(sv);
                m_lines.push_back(l);
            }
            m_lines.push_back(Line());
        }

        void                TextEdit::stream_line(Stream&s, uint32_t li) const
        {
            if(li < m_lines.size())
                m_lines[li].stream(s);
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
            m_settings.tabMode    = tm;
        }
        
        //  ...........................................................................................................
        
        void    TextEdit::draw() 
        {
            using namespace ImGui;
            m_withinRender  = true;
            
            PushID(this);
            PushStyleColor(ImGuiCol_ChildBg, ColorConvertU32ToFloat4(color(Style::Background)));
            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));
            if(m_imguiChild){
                ImGuiWindowFlags    flags   = ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_NoMove;
                if(m_settings.wrapMode != WrapMode::SOFT)
                    flags |= ImGuiWindowFlags_HorizontalScrollbar;
                BeginChild(m_title.c_str(), m_size, m_border, flags);
            }
            
            if(m_handleKeyboard)
                handle_keyboard();
            if(m_handleMouse)
                handle_mouse();

            render_content();
            
            if(m_imguiChild){
                EndChild();
            }
            PopStyleVar();
            PopStyleColor();
            PopID();
            
            m_withinRender  = false;
        }

        void    TextEdit::handle_keyboard()
        {
        }
        
        void    TextEdit::handle_mouse()
        {
        }

        void    TextEdit::render_content()
        {
            auto drawList = ImGui::GetWindowDrawList();
            ImU32 red  = ImGui::GetColorU32(ImVec4(1., 0., 0., 1.));
            ImVec2  vstart  = ImGui::GetWindowContentRegionMin();
            ImVec2  vend    = ImGui::GetWindowContentRegionMax();
            drawList->AddRectFilled(vstart, vend, red);
        }


        void    TextEdit::colorize()
        {
        }

        void    TextEdit::reset_colors()
        {
            for(Line& l : m_lines)
                for(Glyph& g : l.glyphs)
            {
                g.style = 0;
            }
        }
    }
}
