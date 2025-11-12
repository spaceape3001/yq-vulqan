////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/api/YesNo.hpp>
#include <vector>

namespace yq::tachyon {

    class UIElementsWriter;

    //! An item with a collection of subitems
    //! \note This class takes OWNERSHIP of the pointers
    class UIElements : public UIElement {
        YQ_OBJECT_DECLARE(UIElements, UIElement)
    public:

        using Writer = UIElementsWriter;
    
        UIElements(UIFlags flags={});
        
        /*! \brief Copy constructor that CLONES all sub-items
        */
        UIElements(const UIElements&);
        virtual ~UIElements();
    
        //! Note, we surrender the pointer to the class
        //! \return TRUE if appended, FALSE if deleted
        virtual bool    append(UIElement*);
        bool    empty() const;
        size_t  size() const;
        UIElements&    operator<<(UIElement*);
        
        const std::vector<UIElement*>& items() const { return m_items; }
        
        UIElements* copy() const;
        
        static void init_meta();
        
    protected:
    
        virtual void            postadd(UIElement*){}
    
        virtual UIElements*     clone() const override;

        //! Default render for items is to render subitems
        virtual void            render() override;
        
        //! Default content for items is to render subitems
        virtual void            content() override;
        
        virtual void            tick() override;

        //! Calls the children
        virtual void            render(items_k);
        
        virtual YesNo           acceptable(UIElement*) { return ACCEPT; }
        
        std::vector<UIElement*>    m_items;
        
        friend class UIElementsWriter;
    };
}
