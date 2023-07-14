////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <string_view>

namespace yq::tachyon {

    //! Root undo thing
    //!
    //! An undo infrastructure
    class Undo {
    public:
    
        //! Undo whatever
        virtual void undo() {}
        
        //! Redo it
        virtual void redo() {}
        
        //! Allows undos to combine (ie, text and more text)
        virtual bool combine(Undo* next);
        
        //! Label/text
        std::string_view   label() const { return m_label; }
        
        //! Default virtual destructor
        virtual ~Undo();
        
    protected:
        std::string         m_label;
    };
}
