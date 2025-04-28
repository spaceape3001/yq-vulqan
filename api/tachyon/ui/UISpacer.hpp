////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>
#include <yq/shape/Size2.hpp>
#include <tachyon/keywords.hpp>

namespace yq::tachyon {

    class UISpacerWriter;

    /*! \brief UISpacer is a spacing device (with given dimensions)
    */
    class UISpacer : public UIElement {
        YQ_OBJECT_DECLARE(UISpacer, UIElement)
    public:
        using Writer = UISpacerWriter;
        
        UISpacer(const Size2F& v=ZERO, UIFlags flags={});
        UISpacer(const UISpacer&);
        ~UISpacer();
        
        static void init_info();
        
        UISpacer* clone() const;
        
        const Size2F&     size() const { return m_size; }
        void        size(set_k, const Size2F&);
        
    protected:
    
        void        render() override;
        
    private:
        Size2F      m_size;
    };
}
