////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/keywords.hpp>
#include <yt/ui/UIElement.hpp>
#include <vector>

namespace yq::tachyon {

    //! An item with a collection of subitems
    //! \note This class takes OWNERSHIP of the pointers
    class UIElements : public UIElement {
    public:
    
        UIElements();
        
        /*! \brief Copy constructor that CLONES all sub-items
        */
        UIElements(const UIElements&);
        virtual ~UIElements();
    
        void    append(UIElement*);
        bool    empty() const;
        size_t  size() const;
        UIElements&    operator<<(UIElement*);
        
        const std::vector<UIElement*>& items() const { return m_items; }
        
        virtual UIElements*    clone() const override;
        
    protected:
        //! Default render for items is to render subitems
        virtual void        render() override;
        
        //! Default content for items is to render subitems
        virtual void        content() override;
        
        //! Calls the children
        void    render(items_k);
        
    private:
        std::vector<UIElement*>    m_items;
    };
}
