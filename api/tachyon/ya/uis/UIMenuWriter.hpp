////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIMenu;
    
    class UIMenuWriter : public UIElementsWriter {
    public:
        UIMenuWriter();
        UIMenuWriter(UIMenu*);
        UIMenuWriter(const UIMenuWriter&);
        ~UIMenuWriter();
        
        UIMenu*  element();
    };
}
