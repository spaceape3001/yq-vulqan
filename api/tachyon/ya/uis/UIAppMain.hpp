////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {
    /*! \brief Presents a "classic" application UI (toolbars, docks, etc)
    */
    class UIAppMain : public UIElements {
    public:
        UIAppMain(UIFlags flags={});
        UIAppMain(const UIAppMain&);
        ~UIAppMain();
        
    protected:
        UIAppMain* clone() const;
    };
}
