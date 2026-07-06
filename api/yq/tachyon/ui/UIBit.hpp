////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {

    /*! \brief Small bit of UI work
    
        
    */
    class UIBit {   
    public:
    
        virtual ~UIBit(){}
        
        // tentative...
        virtual void    render(){}
        
        virtual UIBit*  clone() const = 0;
    };
    
    template <typename ... Args>
    class TypedUIBit : public UIBit {
    public:
    
    };
    
}
