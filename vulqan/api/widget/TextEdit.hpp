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
        
            static constexpr const uint8_t  MAX_TAB = 32;
        
            enum class TabMode : uint8_t {
                TAB     = 0,
                SPACES
            };
            
            enum class WrapMode : uint8_t {
                NONE = 0,
                SOFT,
                HARD
            };
            
            enum class SelectionMode : uint8_t {
                NORMAL = 0,
                WORD,
                LINE,
                VERTICAL
            };
        
            /*! Text edit coordinate
                
                Anything BEYOND 4 billion is out of scope for this widget.  (Even 16-bit is kinda debatable)
            */
            struct Coord {
                uint32_t    line    = 0;
                uint32_t    column  = 0;

                constexpr auto operator<=>(const Coord&) const noexcept = default;
            };

            struct Glyph {
                char32_t    character;
                uint8_t     palette     = 0;
            };
            
            struct Line {
                std::vector<Glyph>  glyphs;
            };
            
            //  common styles
            enum class Style : uint8_t {
                Default     = 0,
                Background,
                Caret,
                Selection,
                LineNumber,
                Keyword,
                Number,
                String,
                CharLiteral,
                Punctuation,
                Preprocessor,
                Identifier,
                KnownIdentifier,
                PreprocIdentifier,
                Comment,
                MultiLineComment,
                ErrorMarker,
                Breakpoint,
                CurrentLineFill,
                CurrentLineFillInactive,
                CurrentLineEdge
            };
            
            struct PaletteEntry {
                uint32_t        color   = 0;
                //  bold, italic, etc to go here
            };
            
            struct Palette {
                std::array<PaletteEntry, 256>   entries;
            };


            static const Palette&   dark_palette();
            //static const Palette&   light_palette();
            //static const Palette&   retro_blue_palette();

            TextEdit();
            ~TextEdit();

            

            //! Builds the text
            std::string         build_text() const;

            //! Gets the specified character
            char32_t            character(const Coord&) const;

            //! Number of glyphs (not bytes) including new-lines
            uint64_t            character_count() const;

            //! Clears the text
            void                clear_text();
            
            //! Number of lines
            uint32_t            line_count() const { return m_lines.size(); }

            //! Number of characters (glyphs) on line
            uint32_t            line_characters_count(uint32_t) const;

            bool                overwrite() const { return m_overwrite; }

            bool                readonly() const { return m_readonly; }

            //! Resets the configuration
            void                reset_config();
            
            //! Sets the color palette
            void                set_palette(const Palette&);
            
            void                set_readonly(bool);

            //! Sets the number of spaces per tab
            void                set_tab_count(uint8_t);
            
            //! Sets the tab mode
            void                set_tab_mode(TabMode);
            
            //! Sets the text
            void                set_text(std::string_view);
            
            //! Streams the contents out
            void                stream_text(Stream&) const;
            
            void                draw() override;
          
        private:
        
            struct ConfigData {
                TabMode             tabMode         = TabMode::TAB;
                uint8_t             tabCount        = 4;                // zero disables tabs
                WrapMode            wrapMode        = WrapMode::NONE;
                bool                keepWords       = true;             // will keep workds
                uint16_t            vertLine        = 0;                // zero disable
                bool                lineNumbers     = false;            // show line numbers (if enabled)
                bool                showWitespace   = false;
                float               lineSpacing     = 1.f;
            };
            
            struct SelectionData {
                Coord               start = {}, end = {};
                SelectionMode       mode = {};
            };
            
            Palette                 m_palette;
            std::vector<Line>       m_lines;
            ConfigData              m_config;
            bool                    m_readonly  = false;
            bool                    m_overwrite = false;
        };
        
    }
}
