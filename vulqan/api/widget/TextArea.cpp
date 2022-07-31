////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TextArea.hpp"
#include <MyImGui.hpp>
#include <basic/Stream.hpp>
#include <basic/StreamOps.hpp>
#include <basic/IterUtf8.hpp>
#include <basic/TextUtils.hpp>
#include <basic/stream/Text.hpp>
#include <math/AxBox2.hpp>
#include <math/vector_math.hpp>
#include <math/shape_math.hpp>

    //  for debugging
#include <asset/Colors.hpp>

YQ_OBJECT_IMPLEMENT(yq::widget::TextArea)

namespace yq {
    namespace widget {
        
        namespace {
            uint8_t digits(uint64_t n)
            {
                if(n<10ULL)
                    return 1;
                if(n<100ULL)
                    return 2;
                if(n<1'000ULL)
                    return 3;
                if(n<10'000ULL)
                    return 4;
                if(n<100'000ULL)
                    return 5;
                if(n<1'000'000ULL)
                    return 6;
                if(n<10'000'000ULL)
                    return 7;
                if(n<100'000'000ULL)
                    return 8;
                if(n<1'000'000'000ULL)
                    return 9;
                if(n<10'000'000'000ULL)
                    return 10;
                if(n<100'000'000'000ULL)
                    return 11;
                if(n<1'000'000'000'000ULL)
                    return 12;
                if(n<10'000'000'000'000ULL)
                    return 13;
                if(n<100'000'000'000'000ULL)
                    return 14;
                if(n<1'000'000'000'000'000ULL)
                    return 15;
                if(n<10'000'000'000'000'000ULL)
                    return 16;
                if(n<100'000'000'000'000'000ULL)
                    return 17;
                if(n<1'000'000'000'000'000'000ULL)
                    return 18;
                return 19;
            }
        }


        const TextArea::Palette&   TextArea::dark_palette()
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
        
        //const TextArea::Palette&   TextArea::light_palette()
        //{
            //static const Palette p = { { {
                
            //} } };
            //return p;
        //}
        
        //const TextArea::Palette&   TextArea::retro_blue_palette()
        //{
            //static const Palette p = { { {
                
            //} } };
            //return p;
        //}

        //  ...........................................................................................................

        TextArea::TextArea()
        {
            set_palette(dark_palette());
        }
        
        TextArea::~TextArea()
        {
        }

        //  ...........................................................................................................

        void    TextArea::Line::add(std::string_view sv)
        {
            iter_utf8(sv, [&](char32_t ch){
                if(ch == '\n')
                    return;
                if(ch == '\r') // return to sender, you filthy animal!
                    return;
                glyphs.push_back(Glyph{ch});
            });
        }

        void            TextArea::Line::stream(Stream&s) const
        {
            for(const Glyph& g : glyphs)
                s << g.character;
        }
        
        std::string     TextArea::Line::text() const
        {
            std::string     ret;
            ret.reserve(glyphs.size() << 1 );
            ::yq::stream::Text  txt(ret);
            stream(txt);
            return ret;      
        }

        std::u32string  TextArea::Line::utf32() const
        {
            std::u32string  ret;
            ret.resize(glyphs.size());
            for(size_t n=0;n<glyphs.size();++n)
                ret[n] = glyphs[n].character;
            return ret;
        }

        //  ...........................................................................................................
        std::string         TextArea::build_text() const
        {
            std::string         ret;
            ret.reserve(character_count());
            {
                stream::Text    txt(ret);
                stream_text(txt);
            }
            return ret;
        }

        char32_t            TextArea::character(const Coord& c) const
        {
            if(c.line >= m_lines.size())
                return 0;
            auto& l = m_lines[c.line];
            if(c.column >= l.glyphs.size()) 
                return 0;
            return l.glyphs[c.column].character;
        }

        uint64_t            TextArea::character_count() const
        {
            uint64_t    ret = m_lines.size();
            for(auto& l : m_lines)
                ret += l.glyphs.size();
            return ret;
        }

        void                TextArea::clear_text()
        {
            m_lines.clear();
        }
        
        uint32_t            TextArea::color(Style s) const
        {
            return m_palette.entries[(unsigned) s].color;
        }

        void                TextArea::set_imgui_child(bool f)
        {
            m_imguiChild    = f;
        }

        uint32_t            TextArea::line_characters_count(uint32_t l) const
        {
            if(l >= m_lines.size())
                return 0;
            return m_lines[l].glyphs.size();
        }

        std::string         TextArea::line_text(uint32_t li) const
        {
            if(li < m_lines.size())
                return m_lines[li].text();
            return std::string();
        }

        void                TextArea::reset_settings()
        {
            m_settings      = Settings();
        }

        void                TextArea::set_scale(float f)
        {   
            m_scale         = std::max(MIN_SCALE, f);
        }

        void                TextArea::set_line_spacing(float f)
        {
            m_settings.lineSpacing  = std::max(MIN_SPACING, f);
        }

        void                TextArea::set_line_text(uint32_t li, std::string_view txt)
        {
            if(li < m_lines.size()){
                auto& l = m_lines[li];
                l.glyphs.clear();
                l.add(txt);
            }
        }

        void                TextArea::set_palette(const Palette& pal)
        {
            m_palette0      = pal;
        }

        void                TextArea::set_tab_count(uint8_t s)
        {
            m_settings.tabCount = std::min(s, MAX_TAB);
        }
        
        void                TextArea::set_text(std::string_view sv)
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

        void                TextArea::set_text_lines(std::span<std::string_view> lines)
        {
            m_lines.clear();
            for(std::string_view sv : lines){
                Line    l;
                l.add(sv);
                m_lines.push_back(l);
            }
            m_lines.push_back(Line());
        }

        void                TextArea::stream_line(Stream&s, uint32_t li) const
        {
            if(li < m_lines.size())
                m_lines[li].stream(s);
        }
        
        void                TextArea::stream_text(Stream&s) const
        {
            for(auto& l : m_lines){
                for(auto& g : l.glyphs)
                    s << g.character;
                s << '\n';
            }
        }

        void                TextArea::set_tab_mode(TabMode tm)
        {
            m_settings.tabMode    = tm;
        }
        
        //  ...........................................................................................................
        
        void                TextArea::bake_palette(float f)
        {
            for(size_t n=0;n<Palette::N;++n){
                auto color = ImGui::ColorConvertU32ToFloat4(m_palette0.entries[n].color);
                color.w *= f;
                m_palette.entries[n].color    = ImGui::ColorConvertFloat4ToU32(color);
            }
        }
        
        void    TextArea::draw() 
        {
            using namespace ImGui;
            m_withinRender  = true;
            
            PushID(this);
            PushStyleColor(ImGuiCol_ChildBg, ColorConvertU32ToFloat4(color(Style::Background)));
            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));
            if(m_imguiChild){
                ImGuiWindowFlags    flags   = ImGuiWindowFlags_NoMove;
                if(!m_settings.softWrap)
                    flags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
                //if(m_needsVScroll)
                    flags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
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

        void    TextArea::handle_keyboard()
        {
        }
        
        void    TextArea::handle_mouse()
        {
        }

        void    TextArea::render_content()
        {
            using namespace ImGui;
            ImFont*         font        = GetFont();
            
            float           fontSize    = m_scale * GetFontSize();
            Vector2F        textSize    = font->CalcTextSizeA(fontSize, FLT_MAX, -1.0f, "#", nullptr, nullptr);
            textSize.y     *= m_settings.lineSpacing;
            bake_palette(GetStyle().Alpha);
            
            if(m_scrollToTop){
                m_scrollToTop   = false;
                ImGui::SetScrollY(0.f);
            }

            ImDrawList* drawList           = ImGui::GetWindowDrawList();
            
            Vector2F    cpos    = ImGui::GetCursorScreenPos();
            AxBox2F     bounds  = { cpos + (Vector2F) GetWindowContentRegionMin(), cpos + (Vector2F) GetWindowContentRegionMax() };
            bounds.lo          += m_margins.lo;
            bounds.hi          -= m_margins.hi;
            Vector2F    mid     = center(bounds);
            
            
            
            drawList->AddRectFilled(bounds.lo, mid, Color(color::AirForceBlue));
            drawList->AddRectFilled({mid.x, bounds.lo.y}, { bounds.hi.x, mid.y },  Color(color::BubbleGum));
            drawList->AddRectFilled({bounds.lo.x, mid.y}, { mid.x, bounds.hi.y }, Color(color::ElectricViolet));
            drawList->AddRectFilled(mid, bounds.hi, Color(color::Emerald));
            
            
            
            #if 0
            
            
            auto contentSize        = ImGui::GetWindowContentRegionMax();
            
            
            float           viewLeft    = contentSize.left + left_margin();
            float           textLeft    = viewLeft;
            
            float           lineNumberWidth = 0;
            
            if(m_settings.lineNumbers){
                char    buffer[64];
                sprintf(buffer, " %ld ", (long int) m_lines.size());
                textLeft += font->CalcTextSizeA(fontSize, FLT_MAX, -1.0f, buffer, nullptr, nullptr).x;
            }
            
            float           textRight   = contentSize.y - right_margin();
            float           textTop     = top_margin();
            float           textBottom  = contentSize.y - bottom_margin();
            
            
            
            
            // Color
            drawList->AddRectFilled( {0, 0}, {textLeft, textTop}, Color( color::AirForceBlue ));
            drawList->AddRectFilled( {0, textBottom}, {textLeft, contentSize.y}, Color(color::BubbleGum));
            drawList->AddRectFilled( {textRight, 0}, {contentSize.x, textTop }, Color(color::ElectricViolet));
            drawList->AddRectFilled( {textRight,textBottom}, {contentSize.x, contentSize.y}, Color(color::Emerald));
            #endif
        }


        void    TextArea::colorize()
        {
        }

        void    TextArea::reset_colors()
        {
            for(Line& l : m_lines)
                for(Glyph& g : l.glyphs)
            {
                g.style = 0;
            }
        }
    }
}
