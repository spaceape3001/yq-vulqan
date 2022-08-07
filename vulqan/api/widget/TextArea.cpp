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
#include <basic/Logging.hpp>
#include <math/AxBox2.hpp>

#include <math/shape_utils.hpp>

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
                { IM_COL32( 0x20, 0x20, 0x20, 0xFF )}, // Line Number Fill
                { IM_COL32( 0xa0, 0xa0, 0xa0, 0xFF )}, // Vert Edge 
                { IM_COL32( 0x20, 0x20, 0x20, 0xFF )}, // Vert Edge Fill
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
            iter_utf8(sv, [&](const char* z, int n, char32_t ch){
                if(ch == '\n')
                    return;
                if(ch == '\r') // return to sender, you filthy animal!
                    return;
                Glyph   g;
                g.character = ch;
                strncpy(g.text, z, n);
                g.text[sizeof(g.text)-1] = '\0';
                glyphs.push_back(g);
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
        
        template <typename T> 
        struct TextArea::Frame {
            T       left, right, top, bottom;
        };
        
        template <typename T> 
        log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&log, const TextArea::Frame<T>&f)
        {
            return log << "[(" << f.left << "," << f.top << ")>>(" << f.right << "," << f.bottom << ")]";
        }
        
        struct TextArea::Layout {
            Frame<float>    full, text, line;
            Vector2F        element;
            float           fontSize;
            ImFont*         font;
            float           textLine, vertLine;
            float           textWidth, textHeight;
            uint32_t        charWidth, charHeight;
            float           scrollX, scrollY;
            Frame<uint32_t> chars;       // ignores wrapping
        };

        void    TextArea::compute_layout(Layout&lay)
        {
            lay.font        = ImGui::GetFont();
            lay.fontSize    = m_scale * ImGui::GetFontSize();
            lay.element     = lay.font->CalcTextSizeA(lay.fontSize, FLT_MAX, -1.0f, "#", nullptr, nullptr);
            lay.element.y  *= m_settings.lineSpacing;

            if(m_scrollToTop){
                m_scrollToTop   = false;
                ImGui::SetScrollY(0.f);
            }

            Vector2F    cpos    = ImGui::GetCursorScreenPos();
            Vector2F    ul  = cpos + (Vector2F) ImGui::GetWindowContentRegionMin();
            Vector2F    lr  = cpos + (Vector2F) ImGui::GetWindowContentRegionMax();
            
            lay.full.left   = ul.x;
            lay.full.right  = lr.x;
            lay.full.bottom = lr.y;
            lay.full.top    = ul.y;
            
            lay.text.top    = ul.y + m_margins.lo.y;
            lay.text.right  = lr.x - m_margins.hi.x;
            lay.text.bottom = lr.y - m_margins.hi.y;
            
            lay.line.top    = lay.text.top;
            lay.line.bottom = lay.text.bottom;
            lay.line.left   = ul.x + m_margins.lo.x;
            lay.textLine    = lay.line.left;
            
            if(m_settings.lineNumbers){
                char    buffer[64];
                sprintf(buffer, "#%ld#", (long int) (m_lines.size()+1));
                float width  = lay.font->CalcTextSizeA(lay.fontSize, FLT_MAX, -1.0f, buffer, nullptr, nullptr).x;
                
                //yInfo() << "Size of '" << buffer << "' is " << width;
                
                lay.textLine += width;
            }
            
            lay.line.right  = lay.textLine;
            lay.text.left   = lay.textLine;
            
            lay.textWidth       = lay.text.right - lay.text.left;
            lay.textHeight      = lay.text.bottom - lay.text.top;
            
            lay.charWidth       = (uint32_t)(floor(lay.textWidth / lay.element.x) + 0.1f);
            lay.charHeight      = (uint32_t)(floor(lay.textHeight / lay.element.y) + 0.1f);
            
            lay.scrollX         = ImGui::GetScrollX();
            lay.scrollY         = ImGui::GetScrollY();
            
            lay.chars.top       = (uint32_t)(floor(lay.scrollY / lay.element.y) + 0.1f);
            lay.chars.left      = (uint32_t)(floor(lay.scrollX / lay.element.x) + 0.1f);
            lay.chars.bottom    = (uint32_t)(ceil((lay.scrollY+lay.textHeight) / lay.element.y) + 0.1f);
            lay.chars.right     = (uint32_t)(ceil((lay.scrollX+lay.textWidth) / lay.element.x) + 0.1f);
        }
        

        void    TextArea::render_content()
        {
            Layout          lay{};
            compute_layout(lay);

            bake_palette(ImGui::GetStyle().Alpha);
            ImDrawList* drawList    = ImGui::GetWindowDrawList();
            
            char    buffer[64];
            int     lnumdig = digits(m_lines.size()+1);

            auto renderNumber = [&](float y0, uint32_t number) {
                snprintf(buffer, sizeof(buffer), " %*ld ", (int) lnumdig, (long int) number);
                drawList -> AddText( { lay.line.left, y0 }, color(Style::LineNumber), buffer);
            };

            auto renderLine = [&](const CoordSpan& cs, float y0){
            
                if(cs.line >= m_lines.size())
                    return ;
                    
                const Line&   l   = m_lines[cs.line];
                for(uint32_t n=cs.start;n<=cs.end;++n){
                    
                    if(n >= l.glyphs.size())
                        continue;
                    const Glyph& g  = l.glyphs[n];
                
                    float   x   = lay.text.left + (n-cs.start) * lay.element.x;
                 //   drawList->AddText( {x, y0}, m_palette.entries[g.
                }
            
                //  TODO.....
            };
            
            if(m_settings.lineNumbers){
                drawList->AddRectFilled( { lay.line.left, lay.line.top}, { lay.line.right, lay.line.bottom }, color(Style::LineNumberFill));
            }

            if(m_settings.vertLine && (lay.chars.left < m_settings.vertLine) && (m_settings.vertLine <= lay.chars.right)){
                float   x   = lay.text.left + (m_settings.vertLine - lay.chars.left) * lay.element.x;
                drawList->AddRectFilled( {  x, lay.text.top}, {lay.text.right, lay.text.bottom}, color(Style::VertEdgeFill));
                drawList->AddLine( { x, lay.text.top}, {x, lay.text.bottom}, color(Style::VertEdge ));
            }
            
            //  We'll drive this stupidly at first
            for(uint32_t n=lay.chars.top; n<=lay.chars.bottom; ++n){
                float   y0  = lay.text.top + (n-lay.chars.top) * lay.element.y;
                if(m_settings.lineNumbers){
                    renderNumber(y0, n+1);
                }
                renderLine(CoordSpan{n, lay.chars.left, lay.chars.right}, y0);
            }

            
            drawList->AddRect( { lay.text.left, lay.text.top}, { lay.text.right, lay.text.bottom }, ImGui::Color(color::Fern) );
            
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
