////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIWindow;
    
    class UIWindowWriter;
    
    class UIWindowWriter : public UIElementsWriter {
    public:

        UIWindowWriter();
        UIWindowWriter(UIWindow*);
        UIWindowWriter(const UIWindowWriter&);
        ~UIWindowWriter();
        
        UIWindow*  element();
    };
}
