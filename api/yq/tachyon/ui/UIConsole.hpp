////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>


namespace yq::tachyon {

    class UIConsoleWriter;

    /*! \brief A terminal like auto-scrolling pane of text
    
    */
    class UIConsole : public UIWindow {
        YQ_OBJECT_DECLARE(UIConsole, UIWindow)
    public:    

        using Writer = UIWindowWriter;

        struct Options {
            RGBA4F          color   = { 0., 0., 0., 0. };
            float           indent  = 0;                    // 
            std::string     pre     = {};                   // pre-text/prompt to the front
        };
    
        UIConsole(std::string_view, UIFlags flags={});
        UIConsole(const UIConsole&);
        ~UIConsole();
    
        // NOTE: A compiler on the options -- double check you're assigning the RGBA4F type!
        void    submit(const Options&, std::string_view);
        void    submit(std::string_view);

        void    clear();

        static void init_meta();
    
    protected:
        void            content() override;
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
    };

}
