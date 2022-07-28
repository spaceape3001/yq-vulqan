////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Signal.hpp>
#include <engine/Widget.hpp>
#include <functional>
#include <math/RGBA.hpp>
#include <array>
#include <span>

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
        
            static constexpr const unsigned int NPAL = 256;
          
            struct Coord;
            struct Glyph;
            struct Line;
            struct Style {
                uint32_t    fore    = 0;
                uint32_t    back    = 0;
            };
            using Palette   = std::array<Style, NPAL>;

            TextEdit();
            ~TextEdit();

            Signal<engine::Undo*>   undo;

            //! Builds the text
            std::string         build_text() const;

            //! Gets the specified character
            char32_t            character(const Coord&) const;

            //! Number of characters
            uint64_t            character_count() const;

            //! Clears the text
            void                clear_text();
            
            //! Resets the configuration
            void                reset_config();
            
            //! Sets the text
            void                set_text(std::string_view);
            
            //! Streams the contents out
            void                stream_text(Stream&) const;
            
            void                draw() override;
            
            void                set_palette(std::span<const Style>);
            uint32_t            line_count() const;
            uint32_t            line_characters_count(uint32_t) const;
          
        private:
            std::vector<Line>       m_lines;
            struct Config {
                TabMode             tabMode     = TabMode::TAB;
                uint16_t            tabCount    = 4;                // zero disables tabs
                WrapMode            wrapMode    = WrapMode::NONE;
                bool                keepWords   = true;             // will keep workds
                uint16_t            vertLine    = 0;                // zero disable
                bool                lineNumbers = false;            // show line numbers (if enabled)
            }                       m_config;
            Palette                 m_palette;
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
            uint8_t     palette     = 0;
            bool        selected    = false;
        };
        
        struct TextEdit::Line {
            std::vector<Glyph>  glyphs;
        };
    }
}
