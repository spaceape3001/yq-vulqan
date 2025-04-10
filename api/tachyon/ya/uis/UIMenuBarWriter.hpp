////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIMenuBar;
    
    class UIMenuBarWriter : public UIElementsWriter {
    public:
        UIMenuBarWriter();
        UIMenuBarWriter(UIMenuBar*);
        UIMenuBarWriter(const UIMenuBarWriter&);
        ~UIMenuBarWriter();
        
        UIMenuBar*  element();
    };
}
