////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/Widget.hpp>
#include <functional>

namespace yq {
    class Stream;

    namespace engine {
        class Undo;
    };

    namespace widget {
    
        /*! \brief Text edit
        
            This is a text edit 
        *//*
            This is loosely based on https://github.com/BalazsJako/ImGuiColorTextEdit, but needed too much cleanup 
            to do anything except rewrite it.
        */
        class TextEdit : public engine::Widget {
            YQ_OBJECT_DECLARE(TextEdit, engine::Widget)
        public:
        
            enum class TabMode : uint8_t {
                TAB     = 0,
                SPACES
            };
            
            enum class WrapMode : uint8_t {
                NONE = 0,
                SOFT,
                HARD
            };
        
            using UndoSink  = std::function<void(engine::Undo*)>;
        
            TextEdit();
            ~TextEdit();
          
            struct Coord;
            struct Glyph;
            struct Line;
          
            void            clear_text();
            void            reset_config();
          
            void            set_text(std::string_view);
            void            stream_text(Stream&);
            std::string     build_text() const;

            char32_t        character(const Coord&) const;
            
            void            set_undo_sink(UndoSink);
            
            void            draw() override;
            
            uint64_t        chararacter_count() const;
          
        private:
        
            std::vector<Line>       m_lines;
            
            struct {
                TabMode             tabMode     = TabMode::TAB;
                uint16_t            tabCount    = 4;                // zero disables tabs
                WrapMode            wrapMode    = WrapMode::NONE;
                bool                keepWords   = true;             // will keep workds
                uint16_t            vertLine    = 0;                // zero disable
                bool                lineNumbers = false;            // show line numbers (if enabled)
            }                       m_config;

            UndoSink                m_undo;

        };
        
        /*! Text edit coordinate
            
            Anything BEYOND 4 billion is out of scope for this widget.  (Even 16-bit is kinda debatable)
        */
        struct TextEdit::Coord {
            uint32_t    line    = 0;
            uint32_t    column  = 0;

            constexpr auto operator<=>(const Coord&) const noexcept = default;
        };
        
        struct TextEdit::Glyph {
            char32_t    character;
            uint16_t    palette     = 0;
            bool        selected    = false;
        };
        
        struct TextEdit::Line {
            std::vector<Glyph>  glyphs;
        };
    }
}
