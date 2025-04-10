////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIHBox;
    
    class UIHBoxWriter : public UIElementsWriter {
    public:
        UIHBoxWriter();
        UIHBoxWriter(UIHBox*);
        UIHBoxWriter(const UIHBoxWriter&);
        ~UIHBoxWriter();
        
        UIHBox*  element();
    };
}
