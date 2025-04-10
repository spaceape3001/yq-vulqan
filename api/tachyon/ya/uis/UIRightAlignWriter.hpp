////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIRightAlign;
    
    class UIRightAlignWriter : public UIElementsWriter {
    public:
        UIRightAlignWriter();
        UIRightAlignWriter(UIRightAlign*);
        UIRightAlignWriter(const UIRightAlignWriter&);
        ~UIRightAlignWriter();
        
        UIRightAlign*  element();
    };
}
