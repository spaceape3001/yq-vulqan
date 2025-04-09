////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {
    class UIToolBar;

    /*! \brief Presents a "classic" application UI (toolbars, docks, etc)
    */
    class UIAppMain : public UIElements {
    public:
        UIAppMain(UIFlags flags={});
        UIAppMain(const UIAppMain&);
        ~UIAppMain();
        
        virtual AxBox2F viewport() const override;
        virtual AxBox2F viewport(content_k) const override;

    protected:
        UIAppMain* clone() const;
        
    private:
        enum class S : uint8_t {
            MenuBar,
            ToolBar
        };
        
        std::vector<UIToolBar*> m_toolbars;
        Flags<S>                m_status = {};
    };
}
