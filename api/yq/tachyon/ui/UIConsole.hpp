////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    class UIConsoleWriter;

    /*! \brief A terminal like auto-scrolling pane of text
    
    */
    class UIConsole : public UIElement  {
        YQ_OBJECT_DECLARE(UIConsole, UIElement)
    public:    

        using Writer = UIConsoleWriter;

        struct Options {
            RGBA4F          color   = { 0., 0., 0., 0. };
            float           indent  = 0;                    // 
            std::string     pre     = {};                   // pre-text/prompt to the front
        };
    
        UIConsole(UIFlags flags={});
        UIConsole(const UIConsole&);
        ~UIConsole();
    
        // NOTE: A compiler on the options -- double check you're assigning the RGBA4F type!
        void    submit(const Options&, std::string_view);
        void    submit(std::string_view);

        void    clear();

        static void init_meta();
        
        const Size2F&   size() const { return m_size; }
        void            size(set_k, const Size2F&);
    
        void            render() override;
        void            content() override;
        
    protected:
        UIConsole*      clone() const override;

    private:
    
        enum class X : uint8_t {
        };

        struct Line;
        std::vector<Line>       m_lines;
        Vector2I                m_cursor    = { 0, -1 };
        double                  m_txtH      = 0.;
        float                   m_txtW      = 0.;
        size_t                  m_digest    = 0;
        Size2F                  m_size      = {};
    };

}
